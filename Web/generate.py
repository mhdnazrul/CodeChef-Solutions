import os
import json
import re
from typing import Dict, Any, Optional, List

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
ROOT_DIR = os.path.abspath(os.path.join(SCRIPT_DIR, '..'))

FOLDERS_TO_SCAN = [
    os.path.join(ROOT_DIR, 'Solutions')
]
OUTPUT_JSON_FILE = os.path.join(SCRIPT_DIR, 'solutions.json')
README_FILE = os.path.join(ROOT_DIR, 'README.md')

CODECHEF_REGEX = re.compile(
    r'(https?://www\.codechef\.com/'
    r'(?:'
    r'[^/]+/problems/([A-Z0-9_]+)'
    r'|problems/([A-Z0-9_]+)'
    r'))'
)

def parse_problem_link(file_path: str) -> Optional[Dict[str, str]]:
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            for line in f:
                match = CODECHEF_REGEX.search(line)
                if match:
                    url = match.group(1)
                   
                    problem_id = match.group(2) or match.group(3)
                   
                    if problem_id:
                        return {"url": url, "id": problem_id}
                               
            print(f"Warning: Could not find ANY valid CodeChef link in: {file_path}")
            return None
           
    except Exception as e:
        print(f"Error reading file {file_path}: {e}")
        return None

def generate_readme(solutions: List[Dict[str, Any]]):
    print(f"Generating {README_FILE}...")
   
    content = f"""##  CodeChef Solution Archive [link](https://mhdnazrul.github.io/CodeChef-Solutions/) 
### 📢 Find me on:
- [CodeChef Solution Archive Website](https://mhdnazrul.github.io/CodeChef-Solutions/) 
- [GitHub](https://github.com/mhdnazrul) | [CodeChef](https://www.codechef.com/users/nazrulislam_7) | [Facebook](https://www.facebook.com/mhdnazrulislam.me/)

## 📊 Statistics
* **Total Problems Solved:** {len(solutions)}
---
## 📋 Solution Index
"""
   
    content += "| Problem ID | Problem Name | Question | Solution |\n"
    content += "| :---- | :---- | :----: | :----: |\n"
   
    for sol in solutions:
        problem_id = sol.get('problemId', 'N/A')
        problem_name = sol.get('problemName', 'N/A')
        question_url = sol.get('questionUrl', '#')
        solution_url = sol.get('solutionUrl', '#')
       
        content += f"| {problem_id} | {problem_name} | [Question]({question_url}) | [Solution]({solution_url}) |\n"

    try:
        with open(README_FILE, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"Successfully generated '{README_FILE}'")
    except Exception as e:
        print(f"Error writing {README_FILE}: {e}")

def main():
    all_solutions = []
   
    print(f"Scanning folders: {', '.join(FOLDERS_TO_SCAN)}...")
   
    for folder in FOLDERS_TO_SCAN:
        for root, _, files in os.walk(folder):
            for file in files:
                if file.endswith('.cpp'):
                    file_path = os.path.join(root, file)
                    link_info = parse_problem_link(file_path)
                   
                    if link_info:
                        problem_id = link_info['id']
                        url = link_info['url']
                       
                        file_name_only = os.path.splitext(file)[0]
                        problem_name = file_name_only.replace('_', ' ').replace('-', ' ')
                       
                        solution_path = os.path.relpath(file_path, ROOT_DIR)
                        web_path = solution_path.replace(os.sep, '/')
                       
                        solution_entry = {
                            "problemName": problem_name,
                            "problemId": problem_id,
                            "questionUrl": url,
                            "solutionUrl": f"./{web_path}"
                        }
                        all_solutions.append(solution_entry)

    all_solutions.sort(key=lambda x: x['problemName'])
   
    try:
        with open(OUTPUT_JSON_FILE, 'w', encoding='utf-8') as f:
            json.dump(all_solutions, f, indent=4)
        print(f"\nSuccessfully generated '{OUTPUT_JSON_FILE}' with {len(all_solutions)} solutions.")
    except Exception as e:
        print(f"Error writing JSON file: {e}")

    generate_readme(all_solutions)

if __name__ == "__main__":
    main()