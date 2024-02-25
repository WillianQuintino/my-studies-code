//22. Crie uma função que receberá dois arrays de números como argumentos e retornará um array composto por todos os números que estão no primeiro ou no segundo array matriz, mas não em ambos
let array1 = [1, 2, 3, 4, 5];
let array2 = [4, 5, 6, 7, 8];
let array3 = array1.concat(array2);
let array4 = [];
let k = 0;
for (let i = 0; i < array3.length; i++) {
    let count = 0;
    for (let j = 0; j < array3.length; j++) {
        if (array3[i] == array3[j]) {
            count++;
        }
    }
    if (count == 1) {
        array4[k] = array3[i];
        k++;
    }
}
console.log(array4);