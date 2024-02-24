//11. Calcule a média dos números em uma matriz de números
//for
const array = [1, 2, 3, 4];
let sum = 0;

for (let i = 0; i < array.length; i++) {
  sum += array[i];
}

console.log(sum/array.length);

//metodo reduce
const arr = [1, 2, 3, 4];
const reducer = (accumulator, curr) => accumulator + curr;
console.log(arr.reduce(reducer)/arr.length);