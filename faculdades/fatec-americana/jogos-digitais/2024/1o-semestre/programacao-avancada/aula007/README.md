[🔝](../README.md)

# 01/04/2024 - Aula 007

# Resposta dos Exercícios.

1. as modalidades mencionadas na estrutura de historia são:    
   
   - Ponteiro Sentinela:
     
     São ponteiros que serve de referência aos demais ponteiros da para fins de operacionalizar os dados da lista a perda deste Ponteiro poderá acarretar a recuperação dos dados da lista.
   
   - Ponteiros de Processamento
     
     São ponteiros que fazem o encadeamento entre os nós, alocação de endereço de memoria, enfim são Ponteiro que fazem o armazenamento e a recuperação dos dados lista.
   
   - Ponteiro de Estrutura
     
     São ponteiros que fazem parte da struct permitindo o armazenamento de endereço dos nós garantindo a integridade da lista.

2- Podemos referenciar o ponteiro somente endereço de memoria, ou seja, um ponteiro permite apontar para endereço de memoria, de acordo com o tipo de dado.

3- Alocação de endereço de memória ocorre de forma aleatória ao ponteiro, mas o acesso aos dados ocorre de forma sequencial, ou seja uma lista.

4- As listas são encontradas no gerenciamento  de arquivos nos meios magnéticos, e Registros em arquivos e tabelas.

5- As opreações permitidas em lista são

   Inserção, Remoção, Classificação, Pesquisa, Atualização -> CRUD -> Create | Read | Update | Delete.

6- O compilador trata as variáveis. 

- Estáticas da seguinte forma:
  
  Durante o ato de compilação ele reconhece a existência da variável e já atribui um endereço até o fim do processamento.

- Variável Dinâmica:
  
  Durante o ato da compilação, o compilador reconhece a variável dinâmica, mas não atribui endereço de memória a mesma, sabendo este atributo desenvolver durante a execução do programa.

7- Deslocar Ponteiro

   auxiliar = inicio;

   Saltar ponteiro

   auxiliar = auxiliar->next;

   Sincronizar Ponteiro

   Corrente = auxiliar->next;

   Encadeamento entre nó

   auxiliar->next=corrente || corrente->next=auxiliar

8- I                                        F

   [z[]]->[[]]->[[]]->[[]]->[[]z]

        Lista Duplamente

        __________________________|

        L[[]]->[[]]->[[]]->[[]]->[[]]-|

            L_______________________|

        inicio->back=fim;

        fim->next=inicio;

        Lista circular

9. Podemos notar nas primeiras linhas, na struct podemos observar dois campos como next e back, e podemos concluir que a lista é uma Duplamente Encadeada. Podemos encontrar com mais de dois ponteiros reconhecendo como uma arvore e assim por diante

10. Comando responsável para atribui endereço de memoria e o Malloc.
    
    Corrente = (no*) malloc (sizeof(no));
    
    ## Pilha
    
    A pilha é uma das estruturas de dados mais úteis em computação, sendo aplicada em vários problemas clássicos de área.
    
    ## Fundamentos
    
    Pilha é um tipo de lista lenear em que as inserções e acessos são feitos rum extremo,  
