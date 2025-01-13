<?php
    echo "Hello Celke!! <br> <br>";

    $idade = 32;
    $nome = "Cesar Szpak";

    echo "nome " . $nome . " tem a idade ". $idade . ".<br> <br>";

    $qnt_prod = 61;
    $qnt_prod = $qnt_prod - 7;
    echo "Quantidade de produto no estoque: $qnt_prod <br> <br>";

    $saldo = 5.87;
    $deposito = 2570.52;
    $saldo = $saldo + $deposito;
    echo "Saldo: " . number_format($saldo, 2, ",", ".") . " <br> <br>";

    $situação = true;
    if($situação == true){
        echo "<spam style='color: green'>Aprovado</spam> <br> <br>";
    } else {
        echo "<spam style='color: #ff0000'>Reprovado</spam> <br> <br>";
    }
?>