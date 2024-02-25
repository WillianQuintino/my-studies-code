//34. Crie uma função que irá converter um array contendo códigos ASCII em uma string
let ascii = [111, 32, 114, 97, 116, 111, 32, 114, 111, 101, 117, 32, 97, 32, 114, 111, 117, 112, 97, 32, 100, 111, 32, 114, 101, 105, 32, 100, 101, 32, 114, 111, 109, 97];
let text = "";
for (let i = 0; i < ascii.length; i++) {
    text += String.fromCharCode(ascii[i]);
}
console.log(text);
