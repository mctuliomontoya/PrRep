
const formulario = document.querySelector('#formulario');

const procesaTodo = (event) => {
    event.preventDefault();
    const datos = new FormData(event.target);

    const datosCompletos = Object.fromEntries(datos.entries());
    console.log(JSON.stringify(datosCompletos));

}

function saveCareers() {
    let jobId = document.getElementById("job-id").value;
    let jobPosition = document.getElementById("job-position").value;
    let jobType = document.getElementById("job-type").value;
    let jobCity = document.getElementById("job-city").value;
    let jobVacancy = document.getElementById("job-vacancy").value;
    let jobDescription = document.getElementById("job-description").value;


    let careers_records = {
        "jobId": jobId,
        "jobPosition": jobPosition,
        "jobType": jobType,
        "jobCity": jobCity,
        "jobVacancy": jobVacancy,
        "jobDescription": jobDescription,
    }
    console.log(careers_records);

    localStorage.setItem(jobId, JSON.stringify(careers_records));
}


/*if all the fields are filled, the form is submitted*/
const validaFormulario = () => {

    const jobID = document.getElementById('job-id').value;
    const jobPosition = document.getElementById('job-position').value;
    const jobType = document.getElementById('job-type').value;
    const jobVacancies = document.getElementById('job-vacancy').value;
    const jobDescription = document.getElementById('job-description').value;
    const jobCity = document.getElementById('job-city').value;

    if (jobID != '' && jobPosition != '' && jobType != '' && jobVacancies != '' && jobDescription != '' && jobCity != '') {

        saveCareers();
        //deshabilitarFormulario();
    }

}
formulario.addEventListener('submit', validaFormulario);
