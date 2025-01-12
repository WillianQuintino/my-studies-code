//29. Calcule a soma dos números recebidos em uma string delimitada por vírgula
let sum = 0;
let string = "1,2,3,4,5,6,7,8,9";
let array = string.split(",");
for (let i = 0; i < array.length; i++) {
    sum += parseInt(array[i]);
}
console.log(sum);
