function validateUSN() {
    console.log("validateUSN Called");
    var USN_pattern = /[1-4]{1}[A-Z]{2}[0-9]{2}[A-Z]{2}[0-9]{3}/;
    var inputUSN = document.querySelector("#USN").value;
    console.log(inputUSN);
    var res = USN_pattern.test(inputUSN);
    if (!res) {
        alert("Invalid USN");
        return;
    }
    var semester = document.getElementById("sem").value;
    alert("Your USN " + inputUSN + " is valid.\nYour semeter is " + semester);
}