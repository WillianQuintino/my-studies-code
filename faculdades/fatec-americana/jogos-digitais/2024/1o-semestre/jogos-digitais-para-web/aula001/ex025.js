//25. Imprima os 100 primeiros números de Fibonacci e sua soma.
function fibonacci(n) {
    let fib = [0, 1];
    for (let i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}
let fib = fibonacci(100);
let sum = 0;
for (let i = 0; i < fib.length; i++) {
    sum += fib[i];
}
console.log(fib);
console.log(sum);