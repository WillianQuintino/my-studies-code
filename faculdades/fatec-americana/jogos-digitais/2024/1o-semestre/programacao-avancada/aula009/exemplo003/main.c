#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct no
{
    int codigo;
    char nome[30];
    struct no *next, *back;
}no;

struct no *topo, *auxiliar, *auxiliar2, *corrente, *inicio, *fim;
int c;
c=0;

void Enterdata()
{
    printf("\n informe o codigo: ");
    scanf("%d", &corrente -> codigo);

    printf("\n informe o nome: ");
    scanf("%s", &corrente -> nome);
}

void EnterdataTwo()
{
    printf("\n informe o codigo: ");
    scanf("%d", &topo -> codigo);

    printf("\n informe o nome: ");
    scanf("%s", &topo -> nome);
}

void Insert()
{
    if (inicio == NULL)
    {
        corrente=(no*)malloc(sizeof(no));
        auxiliar=corrente;
        inicio=corrente;
        corrente->next = NULL;
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

void Sort()
{
   int Achou = 0;

   corrente = (no*)malloc(sizeof(no));
   Enterdata();
   Achou = 0;

   if(inicio == NULL)
   {
       auxiliar = corrente;
       inicio = corrente;
       corrente->next=NULL;
       Achou = 1;
       printf("\n Inserido o Primeiro Elemento na Lista");
       system("pause");
   } else {
        if(strcmp(corrente->nome, auxiliar->nome)<0)
        {
            corrente->next=auxiliar;
            inicio = corrente;
            Achou = 1;
            printf("\n Registro antecede o primeiro Elemento na Lista");
            system("pause");
        } else {
            auxiliar2 = auxiliar;
            auxiliar=auxiliar->next;
            while (auxiliar != NULL)
            {
                if((strcmp(corrente->nome, auxiliar2->nome)<=0) && (strcmp(corrente->nome, auxiliar->nome)<=0))
                {
                    auxiliar2->next=corrente;
                    corrente->next=auxiliar;
                    Achou = 1;
                    printf("\n Registro inserido no meio da lista");
                    system("pause");
                    break;
                } else {
                    auxiliar2 = auxiliar2->next;
                    auxiliar = auxiliar->next;
                }
            }
            if (Achou == 0 && (strcmp(corrente->nome, auxiliar2->nome)>0))
            {
                auxiliar2->next=corrente;
                corrente->next=NULL;
                printf("\n Registro inserido no final da Lista");
                system("pause");
            }
        }
   }
}

void InsertTwo()
{
    if (inicio == NULL)
    {
        corrente = (no*)malloc(sizeof(no));
        inicio = corrente;
        auxiliar = corrente;
        corrente->next = NULL;
        corrente->back = NULL;
        fim=corrente;
        Enterdata();
    } else {
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->back = auxiliar;
        auxiliar = corrente;
        fim = corrente;
        corrente->next = NULL;
        Enterdata();
    }
}

void Show()
{
    corrente = inicio;

    while(corrente != NULL) {
        printf("\nCodigo: %d | Nome: %s", corrente->codigo, corrente->nome);
        corrente = corrente->next;
    }
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

void SearchTwo(){
    int Achou;
    char nome[30];
    if(inicio == NULL)
    {
        printf("\n Lista vazia");
        system("pause");
    }
    auxiliar = fim; // inicio
    Achou = 0;
    printf("\n Informe o nome a ser Pesquisado: ");
    scanf("%s", &nome);
    while(auxiliar!=NULL)
    {
        if(strcmp(nome, auxiliar->nome) == 0)
        {
            printf("\n Registro encontrado com Sucesso");
            system("pause");
            Achou = 1;
            break;
        } else {
            auxiliar: auxiliar->back;//next
        }
    }
    if (Achou == 0)
    {
        printf("\n Registro não foi encontrado na Lista");
        system("pause");
    }
}

void Removed()
{
    char nome[30];
    int achou;

    if (inicio==NULL)
    {
        printf("\n Lista vazia");

        system("pause");
    } else {
        auxiliar=inicio;
        achou=0;
        printf("\n Informe o nome a ser Removido: ");
        scanf("%s", &nome);
        if(strcmp(auxiliar->nome, nome)==0)
        {
            inicio = inicio->next;
            free(auxiliar);
            printf("\n Removido registro no inicio da Lista");
            system("pause");
            achou=1;
        }else{
            corrente=auxiliar;
            auxiliar=corrente->next;
            while (auxiliar != NULL)
            {
                if(strcmp(auxiliar->nome,nome)==0)
                {
                 corrente->next = auxiliar->next;
                 free(auxiliar);
                 printf("\n Removido no meio da lista / Fim com sucesso");
                 system("pause");
                 achou=1;
                 break;
                } else {
                    auxiliar=auxiliar->next;
                    corrente=corrente->next;
                }
            }

            if (achou==0)
            {
                printf("\n Registro não costa na lista...");
                system("pause");
            }
        }
    }
}

void RemovedTwo()
{
    int Achou;
    char nome[30];
    if(inicio == NULL)
    {
        printf("\n Lista vazia");
        system("pause");
    } else {
        auxiliar = inicio;
        Achou = 0;
        printf("\n informe o nome a ser Remeviso...");
        scanf("%s", &nome);
        if(strcmp(nome, auxiliar->nome) == 0)
        {
            inicio = inicio -> next;
            free(auxiliar);
            inicio -> back = NULL;
            printf("\n Removido o Registro no inicio da  Lista");
            system("pause");
            Achou = 1;
        } else {
            auxiliar2 = auxiliar->next;
            while (auxiliar2->next != NULL)
            {
                 if (strcmp(nome, auxiliar2->nome) == 0)
                 {
                     auxiliar2 = auxiliar2->next;
                     auxiliar2->back = auxiliar;
                     auxiliar2 = auxiliar->next;
                     auxiliar->next = auxiliar2->next;
                     free(auxiliar2);
                     printf("\n Removico com sucesso no meio da Lista");
                     system("pause");
                     Achou = 1;
                     break;
                 }else{
                    auxiliar = auxiliar->next;
                    auxiliar2 = auxiliar2->next;
                 }
            }
            if(Achou == 0 && (strcmp(nome, auxiliar2->nome)==0))
            {
                auxiliar->next=NULL;
                free(auxiliar2);
                free(auxiliar2);
                printf("\n Removico no ultimo posição da Lista");
                system("pause");
            }
            if(Achou == 0)
            {
                printf("\n Registro não encontrado... tente novamente");
                system("pause");
            }
        }
    }
}

void Puch()
{
    if (topo == NULL)
    {
        topo = (no*)malloc(sizeof(no));
        topo->next=NULL;
        topo->back=NULL;
        auxiliar = topo;
        c++;
        EnterdataTwo();
    } else {
        if(c>10)
        {
            printf("\n stack overdlow...");
            system("\n pause");
        } else {
            topo=(no*)malloc(sizeof(no));
            auxiliar->next = topo;
            topo->back=auxiliar;
            topo->next=NULL;
            auxiliar=topo;
            c++;
            EnterdataTwo();
        }
    }
}

void Top()
{

    if(topo == NULL){
        printf("\n Stack underflow...\n");
        //system("\n pause");
    }else{
        printf("\n Codigo: %d", topo->codigo);
        printf("\n Nome: %s", topo->nome);
    }
}

void Pop()
{
    if (topo == NULL)
    {
        printf("\n stack underflow...");
        system("\n pause");
    } else {
        if(topo->next == NULL && topo->back == NULL)
        {
            printf("\n Removendo o ultimo elemento da Pilha\n");
            system("\n pause");
            free(topo);
            topo = NULL;
            auxiliar=NULL;
            c=0;
        } else {
            c--;
            printf("\n Removido o  Elemento da Pilha\n");
            system("\n pause");
            topo=topo->back;
            topo->next=NULL;
            free(auxiliar);
            auxiliar=topo;
        }
    }
}

void Enqueue()
{
    if(inicio == null)
    {
        corente = (no*)malloc(sizeof(no));
        corrente->next=NULL;
        fim=corrente;
        inicio=corrente;
        Enterdata();
        C++
    }
    else{
        if(c>10)
        {
            printf("\n Queue is full");
            system("pause");
        }
        else{
            fim=corrente;
            corrente=(no*)maloc(sizeof(no));
            fim->next=corrente;
            corrente->next=NULL;
            fim=corrente;
            c++;
            Enterdata();
        }
    }
}

void Dequeue(){
    if(inicio == NULL)
    {
        printf("\n Queue is Empty");
        system("pause");
    }
    else{
        inicio == fim;
        if(inicio->next == NULL)
        {
            free(inicio);
            corrente = NULL;
            fim = NULL;
            inicio = NULL;
            C=0;
            printf("\n Removido o ultimo JOB");
            system("pause");
        }
        else{
            corrente = inicio;
            inicio = inicio->next;
            free(corrente);
            c--;
            printf("\n Removido o JOB com maior tempo na Queue");
            system("pause");
        }
    }
}

void Seaqueue(){
    if(inicio == NULL)
    {
        printf("\n Queue is empty");
        system("pause");
    } else {
        corrente = inicio;
        printf("\n Informe o MIX do JOB");
        scanf("%d"; &mix);
        k=0;
        acahou = 0;
        while(corrente)
        {
            k++;
            if(mix == Corrente->codigo);
            {
                printf("\n o Job se encontrar na posicao ==> %d", k);
                system("pause");
                achou = 1;
                break;
            } else{
                corrente=corente->next;
            }
        }
        if (achou ==0)
        {
            printf("\n Job not found");
            system("pause");
        }
    }
}

void SimplyList()
{

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
            //Sort();
            break;
        case 2:
            Show();
            break;
        case 3:
            Search();
            break;
        case 4:
            Removed();
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
}

void DoubleList()
{
    corrente = NULL;
    inicio = NULL;
    auxiliar = NULL;
    int op;

    do
    {
        printf("\n******** Lista Duplamente Encadeada *******");
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
            InsertTwo();
            break;
        case 2:
            Show();
            break;
        case 3:
            SearchTwo();
            break;
        case 4:
            RemovedTwo();
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
}

void DoubleStack()
{
    corrente = NULL;
    inicio = NULL;
    auxiliar = NULL;

    int op;

    do
    {
        printf("\n********************* TOPO ******************");
        Top();
        printf("\n******** Pilha Duplamente Encadeada *******");
        printf("\n [1] Inserindo Registro na Pilha");
        printf("\n [2] Exibindo os Registros da Pilha");
        printf("\n [3] Removendo Registros da Pilha");
        printf("\n [4] Sair");

        printf("\n Escolha a Opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            Puch();
            break;
        case 2:
            //Show();
            break;
        case 3:
            Pop();
            break;
        case 4:
            break;
        default:
            printf("\n Função não encontrada.. tente novamente");
            system("pause");
        }
    }while(op != 4);

    system("cls");
    printf("\n Final de processamento \n");
    system("pause");
}

int main()
{
    setlocale(LC_CTYPE, "portuguese");// Configuração acento
    auxiliar = NULL;
    topo=NULL;

    int op;

    do
    {
        printf("\n******** Lista Simplesmente Encadeada *******");
        printf("\n [1] Lista Simplesmente Encadeada");
        printf("\n [2] Lista Duplamente Encadeada");
        printf("\n [3] Pilha Simplesmente Encadeada");
        printf("\n [4] Sair");

        printf("\n Escolha a Opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            SimplyList();
            break;
        case 2:
            DoubleList();
            break;
        case 3:
            DoubleStack();
            break;
        case 4:
            break;
        default:
            printf("\n Função não encontrada.. tente novamente");
            system("pause");
        }
    }while(op != 4);

    system("cls");
    printf("\n Final de processamento \n");
    system("pause");

    return 0;
}
