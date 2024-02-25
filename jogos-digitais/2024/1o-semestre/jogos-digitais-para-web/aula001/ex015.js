//15. Crie uma função que retornará um booleano especificando se um número é primo
let isPrime = true;
function primeNumber(n) {
    for (let i = 2; i < n; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}
console.log(primeNumber(7));