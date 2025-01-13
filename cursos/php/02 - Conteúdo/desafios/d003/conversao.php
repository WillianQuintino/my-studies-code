<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style.css">
</head>

<body>
    <main>
        <h1>Conversor de Moedas</h1>
        <?php
        // Cotação copiada do Google
            $cotacao = 5.37;
            // Quanto $$ você tem?
            $real = $_REQUEST["din"] ?? 0;
            // Equivalência em dólares
            $dolar = $real / $cotacao;
            //Mostrar o resultado
            // echo "Seus R$" . number_format($real, 2, ",", ".") . "equivalem a US$ " . number_format($dolar, 2, ",", ".");
            // Formatação de moedas com internacionalização!
            // Biblioteca intl (Internationalization PHP)
        
            $padrão = numfmt_create( 'pt_BR', NumberFormatter::CURRENCY );
        
            echo "<p>Seus " . numfmt_format_currency($padrão, $real, "BRL") . " equivalem a <strong>" . numfmt_format_currency($padrão, $dolar, "USD") . "</strong></p>";
        ?>
        <button onclick="javascript:history.go(-1)">Voltar</button>
    </main>
</body>

</html>