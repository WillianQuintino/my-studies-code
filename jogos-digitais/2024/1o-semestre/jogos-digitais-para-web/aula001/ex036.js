//36. Encontre a frequência das letras em uma string. Retorne o resultado como uma matriz de matrizes. Cada subarray possui 2 elementos: letra e número de ocorrências.
let text = "o rato roeu a roupa do rei de roma";
let words = text.split("");
let letters = [];
for (let i = 0; i < words.length; i++) {
    let count = 0;
    for (let j = 0; j < words.length; j++) {
        if (words[i] === words[j]) {
            count++;
        }
    }
    let found = false;
    for (let k = 0; k < letters.length; k++) {
        if (letters[k][0] === words[i]) {
            found = true;
        }
    }
    if (!found) {
        letters.push([words[i], count]);
    }
}
console.log(letters);