#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int codigo;
    char nome[30];
    struct no *next;
}no;
struct no *auxiliar, *corrente, *inicio;

void Enterdata()
{
    printf("\n informe o codigo");
    scanf("%d", &corrente -> codigo);

    printf("\n informe o nome");
    scanf("%s", &corrente -> nome);
}

void insert()
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

int main()
{
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

        printf("\n Escolha a Opção...");
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
            printf}("\n Função a ser desenvolvida");
            system("pause");
            break;
        case 4:
            printf}("\n Função a ser desenvolvida \n
                    ");
            system("pause");
            break;
        default:
            printf("\n Função não encontrada.. tente novamente");
            system("pause");
        }
    }while(op != 5);

    system("cls");
    print("\n Final de processamento");
    system("pause");

    return 0;
}
