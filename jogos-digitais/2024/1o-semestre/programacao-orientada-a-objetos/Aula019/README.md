[🔝](../README.md)

# 24/04/2024 - Aula 019 -

Prof. Perrotti
POO

## Thread

É uma linha de processamento dentro do programa. Dentro de uma thread, os comandos são executados em sequência, um comando só vai inicar sua execução quando o anterior dor finalizado. O programa pode abrir vários threads, nesse caso, elas serão executadas em paralelo, uma independente das outras. Mas pelomentos uma thread é obrigatória a thread principal que comtém a função main(). 

## Pilha de execução (stack)

Para cada thread aberta pelo programa, é criada uma área de memória para conter os dados das funções que estão em execução no momento (stack). Nessa área fica armazenados os dados das funções em execução.

Tudo o que for declarado em uma função, como variáveis em parametros, ficam armazenados nessa área. Sempre que uma função é chamada outra função, a que fez a chamada entra em estado de espera e é alocada uma porção de memória logo acima no stack para a função que foi chamada.