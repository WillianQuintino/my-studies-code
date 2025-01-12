<?php

    echo '<h1>Aprenda PHP em 10 Minutos</h1>';
    
    // PHP = Personal Home Page

    //Variáveis
    echo '<h2>Variáveis</h2>';
    $nome = 'Guilherme';

    //Concatenar
    echo '<h2>Concatenar</h2>';
    echo 'Meu nome é ' . $nome . '<br>';

    //Variável de variável
    echo '<h2>Variável de variável</h2>';
    $Guilherme = 'Bla bla!';

    echo 'Meu nome é ' . $$nome. '<br>';
    
    //Comparar valores
    echo '<h2>Comparar valores</h2>';
    //>= <= == !=
    if($nome == 'Guilherme'){
        echo 'Verdadeiro' . '<br>';
    } else {
        echo 'Falso' . '<br>';
    }

    $idade = '26';
    if($idade == 26){
        echo 'Verdadeiro' . '<br>';
    } else {
        echo 'Falso' . '<br>';
    }

    $idade = '26';
    if($idade !== 26){
        echo 'Verdadeiro' . '<br>';
    } else {
        echo 'Falso' . '<br>';
    }
    //=== !==
    echo '<h2>Comparar valores e tipos</h2>';

    if($idade === 26){
        echo 'Verdadeiro' . '<br>';
    } else {
        echo 'Falso' . '<br>';
    }

    if($idade !== 26){
        echo 'Verdadeiro' . '<br>';
    } else {
        echo 'Falso' . '<br>';
    }    
    
    //Looping
    echo '<h2>Looping</h2>';

    echo '<h3>For</h3>';
    for($i = 0; $i < 10; $i++){
        echo $i . '<hr>';
    }

    $i = 0;

    echo '<h3>While</h3>';
    while($i < 10){
        echo $i . '<br>';
        $i++;
    }

    //Funções
    echo '<h2>Funções</h2>';
    printNumero(30);

    printNumero(50);

    printNumero('Guilherme');
    function printNumero($n){
        echo $n . '<br>';
    }
    //Classes   
    echo '<h2>Classes</h2>';
    class Pessoa{

        public $nome;
        public $idade;

        public function __construct($nome, $idade){
            $this->nome = $nome;
            $this->idade = $idade;
        }

        public function printNomeEIdade(){
            echo $this->nome . '<br>';
            echo $this->idade . '<br>';
        }
    }

    $pessoa = new Pessoa('Guilherme', 26);

    $pessoa->printNomeEIdade();

    $pessoa2 = new Pessoa('Guilherme', 29);

    $pessoa2->printNomeEIdade();

    //Arrays
    echo '<h2>Arrays</h2>';
    $arr = ['guilherme', 'joao', 'felipe'];

    echo $arr[0] . '<br>';
    echo $arr[1] . '<br>';
?>