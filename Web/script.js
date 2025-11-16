let allProblems = [];
const REPO_URL = 'https://github.com/mhdnazrul/CodeChef-Solutions';
let currentFiltered = [];
let currentSort = { key: null, dir: 'asc' };

document.addEventListener('DOMContentLoaded', () => {
    fetch('solutions.json')
        .then(r => r.ok ? r.json() : [])
        .then(data => {
            allProblems = data;
            currentFiltered = [...data];
            
            document.getElementById('total-solved').textContent = data.length;
            renderTable(currentFiltered);
        })
        .catch(e => console.error(e));

    const searchBox = document.getElementById('searchInput');
    let debounceTimer;
    if (searchBox) {
        searchBox.addEventListener('input', () => {
            clearTimeout(debounceTimer);
            debounceTimer = setTimeout(applyFilters, 300);
        });
    }
});

function renderTable(data) {
    const tbody = document.getElementById('table-body');
    const noRes = document.getElementById('no-results');
    tbody.innerHTML = '';
    
    if (!data.length) { noRes.style.display = 'block'; return; }
    noRes.style.display = 'none';

    data.forEach(p => {
        const tr = document.createElement('tr');
        
        const solutionUrl = p.sol_path ? `${REPO_URL}/blob/main/${p.sol_path}` : '#';
        
        tr.innerHTML = `
            <td><strong>${p.id}</strong></td>
            <td>${p.name}</td>
            <td class="center-align">
                <a href="${p.q_link}" target="_blank" class="action-btn btn-problem"><i class="fas fa-external-link-alt"></i> Prob</a>
                <a href="${solutionUrl}" target="_blank" class="action-btn btn-sol"><i class="fas fa-code"></i> Code</a>
            </td>
        `;
        tbody.appendChild(tr);
    });
}

function applyFilters() {
    const q = document.getElementById('searchInput').value.trim().toLowerCase();
    
    currentFiltered = allProblems.filter(p => {
        return !q || (`${p.id} ${p.name}`).toLowerCase().includes(q);
    });
    
    if (currentSort.key) sortTable(currentSort.key, false);
    else renderTable(currentFiltered);
}

function sortTable(key, toggle = true) {
    if (toggle) {
        if (currentSort.key === key) currentSort.dir = currentSort.dir === 'asc' ? 'desc' : 'asc';
        else { currentSort.key = key; currentSort.dir = 'asc'; }
    }
    const dir = currentSort.dir === 'asc' ? 1 : -1;
    
    currentFiltered.sort((a,b) => {
        let va = a[key] || '', vb = b[key] || '';
        return String(va).localeCompare(String(vb), undefined, { numeric: true, sensitivity: 'base' }) * dir;
    });
    
    document.querySelectorAll('.fa-sort, .fa-sort-up, .fa-sort-down').forEach(i => i.className = 'fas fa-sort');
    const icon = document.querySelector(`th[onclick="sortTable('${key}')"] i`);
    if (icon) icon.className = currentSort.dir === 'asc' ? 'fas fa-sort-up' : 'fas fa-sort-down';
    
    renderTable(currentFiltered);
}