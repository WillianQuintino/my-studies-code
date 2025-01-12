//35. Crie uma função que receberá n como argumentos e retornará um array de n números aleatórios de 1 a n. Os números devem ser únicos dentro do array.
let n = 10;	
let array = [];
let i = 0;
while (i < n) {
    let number = Math.floor(Math.random() * n) + 1;
    if (array.indexOf(number) === -1) {
        array.push(number);
        i++;
    }
}
console.log(array);