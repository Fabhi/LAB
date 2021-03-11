var fontSize = 5;
var increment = 5;
var color = "red";
var text = "TEXT-GROWING";

// function to modify DOM
function modify(color, size, text){
    document.getElementById("placeholder").style.color = color;
    document.getElementById("placeholder").style.fontSize = size;
    document.getElementById("placeholder").textContent = text;
}

//function to update the variables and then call modify on them
function update(){
    modify(color, fontSize.toString()+"pt", text);

    // Update fontSize
    fontSize += increment;

    // Update color and text
    if (increment < 0){
        color = "blue";
        text="TEXT-SHRINKING";
    }
    else {
        color = "red";
        text="TEXT-GROWING"; 
    }
    // Update increment
    if(fontSize === 5 || fontSize === 50) 
        increment = -increment;
}

document.getElementById("placeholder").textContent="Javascript linked";
setInterval(update, 1000)