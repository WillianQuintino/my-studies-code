//16. Calcule a soma dos dígitos de um número inteiro positivo
let sum = 0;
function sumDigits(n) {
    while (n > 0) {
        sum += n % 10;
        n = Math.floor(n / 10);
    }
    return sum;
}
console.log(sumDigits(1234));
