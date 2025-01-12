//12. Crie uma função que receba um array de números como argumentos e retorne um array contendo apenas os números positivos
let j = 0;
let pair = {};
function evenNumberOnly(Array) {
    for (let i = 0; i < Array.length; i++) {
        if (Array[i] > 0)
        {
            pair[j] = Array[i];
            j++;
        }
        
    }
    return pair;
}

let array = [12, 34, -16, 56, 51, -32, 12];

console.log(evenNumberOnly(array));