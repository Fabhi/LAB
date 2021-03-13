function validateUSN() {
    console.log("validateUSN Called");
    var USN_pattern = /[1-4]{1}[A-Z]{2}[0-9]{3}/;
    var inputUSN = document.getElementById("USN").textContent;
    var res = USN_pattern.test(inputUSN);
    if (!res) {
        alert("Invalid USN");
        return;
    }
    var semester = document.getElementById("sem").textContent;
    alert("Your USN " + inputUSN + " is valid.\nYour semeter is " + semester);
}