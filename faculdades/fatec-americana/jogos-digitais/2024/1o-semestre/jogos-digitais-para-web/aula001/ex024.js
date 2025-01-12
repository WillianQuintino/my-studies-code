//24. Crie uma função que receberá um array de números como argumentos e retornará um novo array com elementos distintos
let array1 = [1, 2, 3, 4, 3, 6, 7, 10, 9, 10];
let array2 = [];
let k = 0;
for (let i = 0; i < array1.length; i++) {
    let count = 0;
    for (let j = 0; j < array2.length; j++) {
        if (array1[i] == array2[j]) {
            count++;
        }
    }
    if (count == 0) {
        array2[k] = array1[i];
        k++;
    }
}
console.log(array2);