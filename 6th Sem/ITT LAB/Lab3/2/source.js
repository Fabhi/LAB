function printLatinWord(token){
    if (token === " ") return token; 
    rotatedToken = token.substring(1) + token.charAt(0);
    latinToken = rotatedToken + "ay";
    return latinToken;
}

function convert(initialString){
    var tokens = initialString.split(' ');
    var modifiedTokens = new Array(tokens.length);
    for (var i=0; i<tokens.length;i++)
        modifiedTokens[i] = printLatinWord(tokens[i]);
    var finalString = modifiedTokens.join(" ");
    return finalString;
}

function updateStatus(){
    var text = document.getElementById("inputText").value;
    var converted = convert(text);
    var d1 = document.getElementById("output");
    d1.insertAdjacentHTML('afterbegin', '<p>' + converted + '</p>');
    console.log(d1.innerHTML);
}