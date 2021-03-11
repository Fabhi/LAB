function updateRows(table){
    for(var i=1; i<11;i++){
        var row = table.insertRow(-1); 
        for(var j=1; j<4; j++){
            var cell = row.insertCell(-1);
            cell.innerHTML = Math.pow(i,j).toString();
        }
    }
}

function createTable(){
    var table = document.getElementById('squareTable');
    var row = table.insertRow(0);
    var content = ["Number", "Square", "Cube"];
    for (var i = 0; i < 3; i++) {
        var headerCell = document.createElement("TH");
        headerCell.innerHTML = content[i];
        row.appendChild(headerCell);
    }
    updateRows(table);
}

createTable();
