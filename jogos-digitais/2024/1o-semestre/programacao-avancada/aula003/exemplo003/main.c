#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct no
{
    int codigo;
    char nome[30];
    struct no *next;
}no;

struct no *auxiliar, *corrente, *inicio;

void Enterdata()
{
    printf("\n informe o codigo: ");
    scanf("%d", &corrente -> codigo);

    printf("\n informe o nome: ");
    scanf("%s", &corrente -> nome);
}

void Insert()
{
    if (inicio == NULL)
    {
        corrente=(no*)malloc(sizeof(no));
        auxiliar=corrente;
        inicio=corrente;
        corrente->next=NULL;
        Enterdata();
    }
    else
    {
        corrente=(no*)malloc(sizeof(no));
        auxiliar -> next = corrente;
        corrente -> next = NULL;
        auxiliar = corrente;
        Enterdata();
    }
}

void Show()
{

}

void Search()
{
    char nome[30];
    int achou;

    if(inicio == NULL)
    {
        printf("\n Lista vazia...");
        system("pause");
    }else{
        auxiliar = inicio;
        printf("\n informe o nome a ser pesquisado: ");
        scanf("%s", &nome);
        achou=0;
        while (auxiliar != NULL){
            if(strcmp(auxiliar->nome,nome)==0)
            {
                printf("\n Codigo ...: %d", auxiliar->codigo);
                printf("\n Nome .....: %s", auxiliar->nome);
                system("pause");
                achou=1;
                break;
            }else{
                auxiliar=auxiliar->next;
            }
        }
        if (achou==0)
        {
            printf("\n Registro não costa na lista...");
            system("pause");
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "portuguese");// Configuração acento
    corrente = NULL;
    inicio = NULL;
    auxiliar = NULL;

    int op;

    do
    {
        printf("\n******** Lista Simplesmente Encadeada *******");
        printf("\n [1] Inserindo Registro na Lista");
        printf("\n [2] Exibindo os Registros da Lista");
        printf("\n [3] Pesquisa os Registros da Lista");
        printf("\n [4] Removendo Registros da Lista");
        printf("\n [5] Sair");

        printf("\n Escolha a Opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            Insert();
            break;
        case 2:
            Show();
            break;
        case 3:
            Search();
            break;
        case 4:
            printf("\n Função a ser desenvolvida \n");
            system("pause");
            break;
        case 5:
            break;
        default:
            printf("\n Função não encontrada.. tente novamente");
            system("pause");
        }
    }while(op != 5);

    system("cls");
    printf("\n Final de processamento \n");
    system("pause");

    return 0;
}
