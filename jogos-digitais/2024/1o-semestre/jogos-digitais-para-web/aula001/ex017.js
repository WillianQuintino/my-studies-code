//17. Gire um vetor 1 posição à esquerda
let array = [1, 2, 3, 4, 5];
let temp = array[0];
for (let i = 0; i < array.length - 1; i++) {
    array[i] = array[i + 1];
}
array[array.length - 1] = temp;
console.log(array);
