[🔝](../README.md)

# 24/04/2024 - Aula 019 -

Prof. Perrotti
POO

## Thread

É uma linha de processamento dentro do programa. Dentro de uma thread, os comandos são executados em sequência, um comando só vai inicar sua execução quando o anterior dor finalizado. O programa pode abrir vários threads, nesse caso, elas serão executadas em paralelo, uma independente das outras. Mas pelomentos uma thread é obrigatória a thread principal que comtém a função main().

## Pilha de execução (stack)

Para cada thread aberta pelo programa, é criada uma área de memória para conter os dados das funções que estão em execução no momento (stack). Nessa área fica armazenados os dados das funções em execução.

Tudo o que for declarado em uma função, como variáveis em parametros, ficam armazenados nessa área. Sempre que uma função é chamada outra função, a que fez a chamada entra em estado de espera e é alocada uma porção de memória logo acima no stack para a função que foi chamada.

## Execução

É gerada quando uma situação inválida impede o processamento normal do programa. A exeção é sempre lançada na função que estiver no topo da pilha, já que estiver no topo da pilha, já que é a única que está realmente executando.

O objetivo da exeção é notificar a função que uma situação de erro está impedindo o processamento. A função que recebe a execeçãp pode capturar ou ignorar. Se capturar, a exceção é destruída e o processamento segue normalmente.

Mas se aexeção for ignorada ( ou seja não capturada) a função será abortada e a exceção. Se nenhuma função capturar a exeção na função main() que também será abortada caso não a capture, abortando o programa.

## try - catch - finally

Bloco `try` -> É onde fica o código que está sugeito a exceções. Vai ser executado até o ponto onde a exceção ocorrer.

Bloco `catch(NomeExecao exc)` -> É o bloco que captura e trata as exeções. Pode haver vários blocos catch, um para cada exceção que será capturada. Apenas um bloco catch será executado.

Bloco `finally` -> Este bloco sempre será executado, ocorrendo ou não a exceção. Use para finalizar opreções que não podem ficar pendentes.

## Classe Exception

É ancestral de todas as exceções no java.