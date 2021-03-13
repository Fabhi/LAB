function fib(n) {
    var array = [0, 1];
    for (var i = 2; i < n + 1; i++) {
        array.push(array[i - 1] + array[i - 2]);
    }
    return array;
}

function sqr(n) {
    var array = [];
    for (var i = 1; i < n + 1; i++) {
        array.push(i**2);
    }
    return array;
}

function fibonacci() {
    var value = prompt("Enter n", "10");
    var array = fib(Number(value));
    document.getElementById("display").innerHTML = "<p>" + array + "</p>";
}

function squares() {
    var value = prompt("Enter n", "10");
    var array = sqr(Number(value));
    alert(array);
}

console.log("Javascript loaded");
document.getElementById('Fibonacci').addEventListener("click", fibonacci);
document.getElementById('Squares').addEventListener("click", squares);