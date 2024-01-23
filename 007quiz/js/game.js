/* VARIAVEIS DE CONTROLE DO NOSSO JOGO */
var qtdPerguntasFeitas = [];

// PERGUNTAS DO JOGO
const perguntas = [
    //PERGUNTA 0
    {
        pergunta: "Qual dessas linguagens não é considerada uma linguagem de programação?",
        resposta: ["PHP","Javascript", "C++", "HMTL"],
        correta: "resp3"
    },
    //PERGUNTA 1
    {
        pergunta: "Em que ano o Brasil foi descoberto?",
        resposta: ["1498","1500", "1375", "1828"],
        correta: "resp1"
    },
    //PERGUNTA 2
    {
        pergunta: "O que significa a sigla HTML?",
        resposta: ["Hyper Tonto Maluco Legal","Hyper Text Markup Language", "Hey Trade More Language", "Hyper Text Mark Lang"],
        correta: "resp1"
    },
    //pergunta 3
    {
        pergunta: "Quais dessas liguagens é considerada uma linguagem de marcação?",
        resposta: ["HTML","Javascript", "C++", "PHP"],
        correta: "reps0"
    },
];

var qtdPerguntas = perguntas.length - 1;

gerarPergunta(qtdPerguntas);

function gerarPergunta(maxPerguntas){
    //GERA UM NUMERO ALEATORIO
    let aleatorio = (Math.random() * maxPerguntas).toFixed();
    //CONVERTE PARA NUMERO
    aleatorio = Number(aleatorio);
    //MOSTRA NO CONSOLE QUAL PERGUNTA FOI SORTEADA
    console.log('A pergunta sorteado foi a: ' + aleatorio);
};