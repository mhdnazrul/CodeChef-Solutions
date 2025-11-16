import os
import json
import re
import urllib.parse

# কনফিগারেশন
DIRECTORIES = ["Solutions"]
WEB_DIR = "Web"
EXTENSIONS = {".cpp", ".c", ".py", ".java", ".js", ".kt", ".cs"}
REPO_URL = "https://github.com/mhdnazrul/CodeChef-Solutions"

# FIX: Regex ঠিক করা হয়েছে যাতে TEST, FLOW007, A1B2 সব ধরনের আইডি সাপোর্ট করে
CODECHEF_REGEX = re.compile(
    r'https?://(?:www\.)?codechef\.com/(?:[^/\s]+/)*problems/([A-Za-z0-9_]+)',
    re.IGNORECASE
)

problems_data = []
stats = {"total": 0}
seen_files = set()

def parse_problem_link(file_path):
    """ফাইল থেকে CodeChef লিঙ্ক খুঁজে বের করে"""
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read(2000) # প্রথম ২০০০ ক্যারেক্টার চেক করবে
            match = CODECHEF_REGEX.search(content)
            if match:
                return {"url": match.group(0), "id": match.group(1)}
    except Exception as e:
        print(f"⚠️ File read error: {e}")
    return None

def sanitize_filename(filename):
    """ফাইলের নাম ক্লিন করে"""
    name, ext = os.path.splitext(filename)
    new_name = re.sub(r'[^a-zA-Z0-9_]', '_', name)
    new_name = re.sub(r'_+', '_', new_name).strip('_')
    return f"{new_name}{ext}"

def process_files():
    if not os.path.exists(WEB_DIR): os.makedirs(WEB_DIR)

    for folder in DIRECTORIES:
        if not os.path.exists(folder): continue
        
        for root, _, files in os.walk(folder):
            for file in files:
                if not any(file.endswith(ext) for ext in EXTENSIONS): continue
                
                original_path = os.path.join(root, file)
                new_filename = sanitize_filename(file)
                new_path = os.path.join(root, new_filename)
                
                if original_path != new_path:
                    try:
                        os.rename(original_path, new_path)
                        file = new_filename
                    except OSError as e:
                        print(f"⚠️ Rename error: {e}")
                        continue
                
                file_key = file.lower()
                if file_key in seen_files:
                    try: 
                        os.remove(new_path)
                        print(f"🗑️ Duplicate removed: {new_path}")
                        continue
                    except OSError: pass
                seen_files.add(file_key)

                link_info = parse_problem_link(new_path)
                
                problem_id = "Unknown"
                q_link = "#"
                
                if link_info:
                    problem_id = link_info['id']
                    q_link = link_info['url']
                else:
                    # FIX: Regex ঠিক করা হয়েছে
                    name_match = re.match(r'^([A-Za-z0-9_]+)', file, re.IGNORECASE)
                    if name_match:
                        problem_id = name_match.group(1)
                        q_link = f"https://www.codechef.com/problems/{problem_id}"

                problem_name = os.path.splitext(file)[0].replace('_', ' ').replace('-', ' ')
                
                rel_path = os.path.relpath(new_path, start=os.getcwd()).replace("\\", "/")
                
                problems_data.append({
                    "id": problem_id,
                    "name": problem_name,
                    "q_link": q_link,
                    "sol_path": rel_path,
                    "filename": file
                })
                
                stats["total"] += 1

    with open(os.path.join(WEB_DIR, "solutions.json"), "w", encoding='utf-8') as f:
        json.dump(problems_data, f, indent=2)
    
    generate_readme()
    print(f"✅ Processed {stats['total']} solutions.")

def generate_readme():
    print("📝 Generating README.md...")
    sorted_probs = sorted(problems_data, key=lambda x: x['name'])
    
    repo_owner = os.getenv('GITHUB_REPOSITORY_OWNER', 'mhdnazrul')
    repo_name_env = os.getenv('GITHUB_REPOSITORY', 'CodeChef-Solutions')
    repo_name = repo_name_env.split('/')[-1] if '/' in repo_name_env else repo_name_env

    md = f"""<h1 align="center">CodeChef Solution Archive</h1>
<p align="center">
    <a href="https://{repo_owner}.github.io/{repo_name}/">
        <img src="https://img.shields.io/badge/View_Website-Click_Here-brown?style=for-the-badge&logo=codechef&logoColor=white" alt="Website">
    </a>
</p>
<p align="center">
    <img src="https://img.shields.io/badge/Language-C++%20%7C%20Python-blue?style=for-the-badge&logo=c%2B%2B" alt="Language">
    <img src="https://img.shields.io/badge/Total%20Solved-{stats['total']}-orange?style=for-the-badge&logo=codechef" alt="Total">
</p>
<p align="center">
    <b>🚀 Find me on: </b>
    <a href="https://github.com/mhdnazrul">GitHub</a> | <a href="https://www.codechef.com/users/nazrulislam_7">CodeChef</a>
</p>

---

## 📊 Statistics
**Total Problems Solved:** {stats['total']}

---

<h2 align="center">📋 Solution Index</h2>

| Problem ID | Problem Name | Question | Solution |
| :---: | :--- | :---: | :---: |
"""
    
    for p in sorted_probs:
        sol_full_link = f"{REPO_URL}/blob/main/{urllib.parse.quote(p['sol_path'])}"
        md += f"| {p['id']} | {p['name']} | [View]({p['q_link']}) | [Code]({sol_full_link}) |\n"

    md += f"\n<br>\n<p align=\"center\"><i>Auto-generated by <a href=\"Web/generate.py\">generate.py</a></i></p>"
    
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(md)

if __name__ == "__main__":
    process_files()