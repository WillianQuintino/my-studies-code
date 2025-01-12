//31. Crie uma função para converter um texto CSV em um array “bidimensional”
let csv = "nome,idade,sexo\nLucas,25,M\nMaria,30,F\nJoão,20,M";
let lines = csv.split("\n");
let array = [];
for (let i = 0; i < lines.length; i++) {
    array.push(lines[i].split(","));
}
console.log(array);
