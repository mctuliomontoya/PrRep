const arr = [];

for (let i = 0; i < localStorage.length; i++) {
    arr.push(JSON.parse(localStorage.getItem(localStorage.key(i))));

}

buildTable(arr);

function buildTable(data) {
    const table = document.getElementById('careers-table');
    
    let tableHTML = ` `;

    for (let i = 0; i < data.length; i++) {
        tableHTML += `
        <tr>
            <td>${data[i].jobId}</td>
            <td>${data[i].jobPosition}</td>
            <td>${data[i].jobType}</td>
            <td>${data[i].jobCity}</td>
            <td>${data[i].jobVacancy}</td>
        </tr>

        <tr>
            <td>Qualifications:</td>
            <td colspan="3">
                ${data[i].jobDescription}
            </td>
            <td><button class="btn btn-primary">Apply</button></td>
        </tr>`;
    }

    table.innerHTML += tableHTML;
}