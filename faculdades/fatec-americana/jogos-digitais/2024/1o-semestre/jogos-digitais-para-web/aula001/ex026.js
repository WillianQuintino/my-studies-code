//26. Crie uma função que irá adicionar dois números positivos de tamanho indefinido. Os números são recebidos como strings e o resultado também deve ser fornecido como string.
let number1 = '123456789123456789123456789';
let number2 = '987654321987654321987654321';
let result = '';
let carry = 0;
let i = number1.length - 1;
let j = number2.length - 1;
while (i >= 0 || j >= 0 || carry > 0) {
    let sum = parseInt(number1[i] || 0) + parseInt(number2[j] || 0) + carry;
    result = (sum % 10) + result;
    carry = Math.floor(sum / 10);
    i--;
    j--;
}
console.log(result);
