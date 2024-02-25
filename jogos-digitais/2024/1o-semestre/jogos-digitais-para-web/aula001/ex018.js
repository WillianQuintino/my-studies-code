//18. Gire um vetor 1 posição à direita
let array = [1, 2, 3, 4, 5];
let temp = array[array.length - 1];
for (let i = array.length - 1; i > 0; i--) {
    array[i] = array[i - 1];
}
array[0] = temp;
console.log(array);
