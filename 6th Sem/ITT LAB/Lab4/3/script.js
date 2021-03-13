var oldValue;
function bringToTop(element) {
    oldValue = element.style.zIndex;
    element.style.zIndex = 3;
    
}

function resetPosition(element) {
    element.style.zIndex = oldValue;
}


var colors = ["#9ccb9c", "#D04545", "cornflowerblue"];
var coordinates = [
    { left: "60px", bottom: "60px" },
    { left: "30px", bottom: "30px" },
    { left: "0px", bottom: "0px" }
];

var boxes = document.getElementsByClassName("boxed");
Array.from(boxes).forEach((element, index) => {
    element.style.zIndex = 3 - index.toString(); 
    element.style.left = coordinates[index].left;
    element.style.bottom = coordinates[index].bottom;
    element.style.backgroundColor = colors[index];

    // Configure onmouseover and onmouseout event
    element.onmouseover = () => bringToTop(element);
    element.onmouseout = () => resetPosition(element);
});