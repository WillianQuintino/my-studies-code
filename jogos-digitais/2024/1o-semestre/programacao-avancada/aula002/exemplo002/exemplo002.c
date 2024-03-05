    #include<stdio.h>
    #include<stdlib.h>

    typedef struct no
    {
        int codigo;
        char nome[30];
        struct no *next;
    }no;

    struct no *A, *B;

    int main()
    {
        A = NULL;
        B = NULL;

        int i;

        for(i=0; i<5; i++)
        {
            A =(no*)malloc(sizeof(no));
            printf("\n informe o codigo ");
            scanf("%d", &A->codigo);
            printf("\n informe o nome ");
            scanf("%s", &A->nome);
            B = A;
            B -> next = A;
            B = A;
            A -> next = NULL;
        }

        return 0;
    }
