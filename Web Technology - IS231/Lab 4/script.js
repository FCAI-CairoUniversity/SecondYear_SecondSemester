const add = () => {
    const num1 = Number(document.getElementById("num1").value);
    const num2 = Number(document.getElementById("num2").value);

    console.log(num1);
    console.log(num2);

    window.alert(num1 === num2 ? (num1 + num2) * 3 : num1 + num2);
};
