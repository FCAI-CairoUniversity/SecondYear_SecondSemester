function getById() {
    if (document.getElementById('numInput').value == "") {
        alert('Please, Enter a valid number');
        return;
    }
    document.querySelector('.screenResult').innerHTML = document.getElementById('numInput').value;
}

function getByName() {
    document.querySelector('.screenResult').innerHTML = "";
    var string = document.getElementsByName('string');
    for (let index = 0; index < string.length; index++) {
        document.querySelector('.screenResult').innerHTML += `${string[index].value} <br>`;
    }
}

