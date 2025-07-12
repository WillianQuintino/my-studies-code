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

// Blocks
// Switch case
async function getRandomBlock() {
    let random = Math.random();
    let result;

    switch (true) {
        case random < 0.33:
            result = "RETA";
            break;
        case random < 0.66:
            result = "CURVA";
            break;
        default:
            result = "CONFRONTO";
            break;
    }

    return result;
}

// Race Engine
// Função em cadeia (Functions Chains) é quando chamamos uma dentro da outra e use com parcimonia
async function playRaceEngine(character1, character2) {
    for(let round = 1; round <= 5; round++){
        console.log(`🏁 Rodada ${round}`);

        // sortear bloco
        let block = await getRandomBlock();
        console.log(`Bloco: ${block}`);
    }
    
    // rolar os dados Alt + Shift + cima ou baixo duplica linha
    let diceResult1 = await rollDice();
    let diceResult2 = await rollDice();

    //teste de habilidade
    // variaveis normalmente segue conveções e a que esta sendo utilizada neste codigo é a CamelCase
    let totalTestSkill1 = 0;
    let totalTestSkill2 = 0;

    // comando if é uma condicionar que testad de uma unica maneira
    if(block === "RETA"){
        totalTestSkill1 = diceResult1 + character1.VELOCIDADE;
        totalTestSkill2 = diceResult2 + character2.VELOCIDADE;
    }
    
    if(block === "CURVA"){
        totalTestSkill1 = diceResult1 + character1.MANOBRABILIDADE;
        totalTestSkill2 = diceResult2 + character2.MANOBRABILIDADE;
    }

    //Escopo de variaveis ela só existe onde ela está ou seja o powerResult1 e powerResult2 não é acessado externo
    if(block === "CONFRONTO"){
        let powerResult1 = diceResult1 + character1.PODER
        let powerResult2 = diceResult2 + character2.PODER
    }
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

