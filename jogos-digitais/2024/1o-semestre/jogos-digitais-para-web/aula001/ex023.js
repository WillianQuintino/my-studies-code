//23. Crie uma função que receberá dois arrays e retornará um array com elementos que estão no primeiro array mas não no segundo
let array1 = [1, 2, 3, 4, 5];
let array2 = [4, 5, 6, 7, 8];
let array3 = [];
let k = 0;
for (let i = 0; i < array1.length; i++) {
    let count = 0;
    for (let j = 0; j < array2.length; j++) {
        if (array1[i] == array2[j]) {
            count++;
        }
    }
    if (count == 0) {
        array3[k] = array1[i];
        k++;
    }
}
console.log(array3);