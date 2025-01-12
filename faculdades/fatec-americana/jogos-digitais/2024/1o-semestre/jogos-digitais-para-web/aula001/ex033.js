//33. Crie uma função que irá converter uma string em um array contendo os códigos ASCII de cada caractere
let text = "o rato roeu a roupa do rei de roma";
let words = text.split("");
let ascii = [];
for (let i = 0; i < words.length; i++) {
    ascii.push(words[i].charCodeAt(0));
}
console.log(ascii);
