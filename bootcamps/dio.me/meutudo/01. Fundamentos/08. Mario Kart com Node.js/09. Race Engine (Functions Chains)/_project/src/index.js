// OBJETOS: 
// Ao declarar desta forma isso se torna um objeto no JavaScrit
const player1 = {
    NOME: "Mario",
    VELOCIDADE: 4,
    MANOBRABILIDADE: 3,
    PODER: 3,
    PONTOS: 0,
};

const player2 = {
    NOME: "Luigi",
    VELOCIDADE: 3,
    MANOBRABILIDADE: 4,
    PODER: 4,
    PONTOS: 0,
};

// ASYNC FUNCTION:
// - A classe Math trás todas as principais funções de calculo matematicos utilizadas
// - No node as função são sincronas execuntão todas as funções ao mesmo tempo
// - Mas não queremos executar ao mesmo tempo então tranformamos em Async
async function rollDice(){
    return Math.floor( // Função da classe Math para arendondar os valores quebrados
        Math.random() // Gera um numero aletarorio de 0 á 1
        * 6 // por precisarmos de um valor até 6 nós mutiplicamos pela quantidade 
    ) + 1; // após arendondar ele vai arendondar para baixo então adicionamos 1 para temos o valor 6
}

// Race Engine
// Função em cadeia (Functions Chains) é quando chamamos uma dentro da outra e use com parcimonia
async function playRaceEngine(character1, character2) {
    
}
// MAIN:
//criar a função principal do codigo uma função de entrada
(async function main() {
    console.log(
        `🏁🚨 Corrida entre ${player1.NOME} e ${player2.NOME} começando... \n`
    );

    await playRaceEngine(player1, player2);
    // usando as `` você cria um template
})(); // função auto invocavel

