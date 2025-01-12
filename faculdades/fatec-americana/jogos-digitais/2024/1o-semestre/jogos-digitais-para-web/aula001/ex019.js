//19. Inverta um vetor
let array = [1, 2, 3, 4, 5];
let temp;
for (let i = 0; i < array.length / 2; i++) {
    temp = array[i];
    array[i] = array[array.length - 1 - i];
    array[array.length - 1 - i] = temp;
}
console.log(array);
