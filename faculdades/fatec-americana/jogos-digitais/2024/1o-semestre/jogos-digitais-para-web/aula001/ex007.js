//7. Calcule a soma dos números pares maiores que 10 e menores que 30
let soma = 0;
for(i=10; i <= 30; i+=2){    
    console.log(i +" + " + soma);
    soma += i;
}
console.log(soma)