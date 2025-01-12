//28. Crie uma função que coloque a primeira letra de cada palavra em maiúscula em um texto
let text = "o rato roeu a roupa do rei de roma";
let words = text.split(" ");
let newText = "";
for (let i = 0; i < words.length; i++) {
    newText += words[i].charAt(0).toUpperCase() + words[i].slice(1) + " ";
}
console.log(newText);