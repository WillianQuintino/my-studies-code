    #include<stdio.h>
    #include<stdlib.h>

    typedef struct no
    {
        int codigo;
        char nome[30];
        struct no *next;
    }no;

    struct no *I, *A, *B;

    int main()
    {
        A = NULL;
        B = NULL;
        I = NULL;

        int i = 0;

        do
        {
            if (A==NULL){
                A =(no*)malloc(sizeof(no));
                printf("\n informe o codigo: ");
                scanf("%d", &A->codigo);
                printf("\n informe o nome: ");
                scanf("%s", &A->nome);
                I = A;
                B = A;
                A -> next = NULL;
            } else {
                A = (no*)malloc(sizeof(no));
                printf("\n infome o codigo: ");
                scanf("%d", &A->codigo);
                printf("\n informe o nome: ");
                scanf("%s", &A-> nome);
                B -> next = A;
                A -> next = NULL;
                B = A;
            }
            printf("\n Ja terminou? Digite 1: ");
            scanf("%d", &i);

        }while(i != 1);

        A = I;

        while(A != NULL)
        {
            printf("\nPonteiro: %p", A);
            printf("\nCodigo: %d", A->codigo);
            printf("\nNome: %s", A->nome);
            printf("\nNext: %p", A->next);
            printf("\n-------------------------");

            A = A->next;
        }


        return 0;
    }
