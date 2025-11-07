let allSolutions = [];

document.addEventListener('DOMContentLoaded', () => {
    fetch('solutions.json')
        .then(response => response.json())
        .then(data => {
            allSolutions = data;
            renderStatistics(allSolutions);
            renderTable(allSolutions);
        })
        .catch(error => console.error('Error loading solutions.json:', error));

    document.getElementById('search-box').addEventListener('input', applyFilters);
});

function renderStatistics(solutions) {
    document.getElementById('total-solved').textContent = solutions.length;
}

function renderTable(solutions) {
    const tableBody = document.getElementById('solutions-table-body');
    tableBody.innerHTML = '';

    solutions.forEach(sol => {
        const row = document.createElement('tr');

        const idCell = document.createElement('td');
        idCell.textContent = sol.problemId;
        row.appendChild(idCell);

        const nameCell = document.createElement('td');
        nameCell.textContent = sol.problemName;
        row.appendChild(nameCell);

        const questionCell = document.createElement('td');
        questionCell.innerHTML = `
            <a href="${sol.questionUrl}" target="_blank" class="link-btn">Question</a>
        `;
        row.appendChild(questionCell);
        
        const solutionCell = document.createElement('td');
        solutionCell.innerHTML = `
            <a href="${sol.solutionUrl}" target="_blank" class="link-btn solution">Solution</a>
        `;
        row.appendChild(solutionCell);

        tableBody.appendChild(row);
    });
}

function applyFilters() {
    const searchText = document.getElementById('search-box').value.toLowerCase();

    const filteredSolutions = allSolutions.filter(sol => {
        const nameMatch = sol.problemName.toLowerCase().includes(searchText);
        return nameMatch;
    });

    renderTable(filteredSolutions);
}