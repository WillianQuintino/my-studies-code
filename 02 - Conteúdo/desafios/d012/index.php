<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Desafio PHP</title>
    <link rel="stylesheet" href="style.css">
</head>

<body>
    <?php
        $total_segundos = $_GET['seg'] ?? '0';        
    ?>
    <main>
        <h1>Calculadora de Tempo</h1>
        <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
            <label for="preco">Qual o total de segundos?</label>
            <input type="number" name="seg" id="seg" min="0" step="1" require value="<?=$total_segundos?>">
            <input type="submit" value="Calcular">
        </form>
    </main>
    <section>
        <?php 
            $sobra = $total_segundos;
            // Total de Demanas
            $semana = (int)($sobra / 604_800);
            $sobra = $sobra % 604_800;
            // Total de Dias
            $dia = (int)($sobra / 86_400);
            $sobra = $sobra % 86_400;
            // Total de Horas
            $hora = (int)($sobra / 3_600);
            $sobra = $sobra % 3_600;
            // Total de Minutos
            $minuto = (int)($sobra / 60);
            $sobra = $sobra % 60;
            // Total de Segundos
            $segundo = $sobra;

        ?>
        <h2>Totalizando tudo</h2>
        <p> Analisando o valor que você digitou, <strong><?=number_format($total_segundos, 0, ",", ".")?>
                segundos</strong> equivalem a um total de:
        </p>
        <ul>
            <li><?=$semana?> semanas</li>
            <li><?=$dia?> dias</li>
            <li><?=$hora?> horas</li>
            <li><?=$minuto?> minutos</li>
            <li><?=$segundo?> segundos</li>
        </ul>

    </section>
</body>

</html>