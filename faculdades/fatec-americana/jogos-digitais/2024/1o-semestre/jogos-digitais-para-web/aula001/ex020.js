//20. Inverta uma string.
let string = "Hello World";
let temp = "";
for (let i = string.length - 1; i >= 0; i--) {
    temp += string[i];
}
console.log(temp);
