/* VARIAVEIS DE CONTROLE DO NOSSO JOGO */
var perguntasFeitas = [];

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
        correta: "resp0"
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
    
    //VERIFICAR SE A PERGUNTA SORTEADA JÁ FOI FEITA
    if(!perguntasFeitas.includes(aleatorio)){
        //COLOCAR A PERGUNTA FEITA
        perguntasFeitas.push(aleatorio);

        //PREENCHER O HTML COM OS DADOS DA QUESTAO SORTEADA
        var p_selecionada = perguntas[aleatorio].pergunta;
        console.log(p_selecionada);
        
        //ALIMENTAR A PERGUNTA VINDA DO SORTEIO
        $("#pergunta").html(p_selecionada);
        $("#pergunta").attr('data-indice', aleatorio)

        //COLOCAR AS RESPOSTAS
        for(let i = 0; i < 4; i++){
            //ALIMENTAR AS RESPOSTAS
            $("#resp" + i).html(perguntas[aleatorio].resposta[i]);
        }

        //EMBARALHAR AS RESPOSTAS
        var pai = $("#respostas");
        var botoes = pai.children();

        for(var i=1; i < botoes.length; i++){
            pai.append(botoes.eq(Math.floor(Math.random() * botoes.length)));
        }
    }else{
        //SE A PERGUNTA JÁ FOI FEITA
        console.log('Essa pergunta já foi feita. Sorteando novamente...');
        if(perguntasFeitas.length < qtdPerguntas +1){
            return gerarPergunta(maxPerguntas);
        }else{
            console.log('Acabaram as perguntas!');
            $('#quiz').addClass('oculto');
            $('#mensagem').html('Parabéns! Você acertou todas as perguntas!');
            $('#status').removeClass('oculto');
        }
    }
};
$('.resposta').click(function(){
    if($('#quiz').attr('data-status') !== 'travado'){
        //PERCORRER TODAS AS RESPOSTAS E DESMARCAR A CLASSES SELECIONADA
        resetaBotoes();

        //ADICIONAR A CLASSE SELECIONADA
        $(this).addClass('selecionada');
    }
});
$("#confirm").click(function(){
    //PEGAR O INDICE DA PERGUNTA
    var indice = $("#pergunta").attr('data-indice');

    //QUAL É A RESPOSTA CERTA
    var respCerta = perguntas[indice].correta;

    //QUAL A RESPOSTA QUE O USUARIO SELECIONOU
    $(".resposta").each(function(){
        if($(this).hasClass('selecionada')){
            var respostaEscolhida = $(this).attr('id');

            if(respCerta == respostaEscolhida){
                console.log('Acertou!');
                proximaPergunta();
            }else{
                console.log('Errou!');
                $('#quiz').attr('data-status', 'travado');
                $('#confirm').addClass('oculto');
                $('#'+respCerta).addClass('correta');
                $('#'+respostaEscolhida).removeClass('selecionada').addClass('errada');
                //4 segundos para mostrar a mensagem de game over
                setTimeout(function(){
                    gameOver();
                }, 4000);
            };
        }
    });
});

function newGame(){
    $('#confirm').removeClass('oculto');
    $('#quiz').attr('data-status', 'ok');
    perguntasFeitas = [];
    resetaBotoes();
    gerarPergunta(qtdPerguntas);    
    $('#quiz').removeClass('oculto');
    $('#status').addClass('oculto');
};

function proximaPergunta(){
    resetaBotoes();
    gerarPergunta(qtdPerguntas);
};

function resetaBotoes(){
    //PERCORRER TODAS AS RESPOSTAS E DESMARCAR A CLASSES SELECIONADA
    $('.resposta').each(function(){
        if($(this).hasClass('selecionada')){
            $(this).removeClass('selecionada');
        }
        if($(this).hasClass('correta')){
            $(this).removeClass('correta');
        }
        if($(this).hasClass('errada')){
            $(this).removeClass('errada');
        }
    });
};

function gameOver(){
    $('#quiz').addClass('oculto');
    $('#mensagem').html('Game Over!');
    $('#status').removeClass('oculto');
};

$('#novoJogo').click(function(){
    newGame();
});