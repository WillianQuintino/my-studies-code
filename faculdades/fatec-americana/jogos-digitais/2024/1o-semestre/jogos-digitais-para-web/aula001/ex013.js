//13. Encontre o número máximo em uma matriz de números
let max = 0;
let array = [[1, 2, 3], [4, 155, 6], [7, 8, 9]];
for (let i = 0; i < array.length; i++) {
    for (let j = 0; j < array[i].length; j++) {
        if (array[i][j] > max) {
            max = array[i][j];
        }
    }
}
console.log(max);
