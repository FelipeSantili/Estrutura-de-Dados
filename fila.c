#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct elemento
{
    int dado;  
    struct elemento *prox;
};

typedef struct elemento *ApElemento;
typedef struct
{
    ApElemento ini;
    ApElemento fim;
} Fila;

Fila criaFila()
{
    Fila f;
    f.ini = NULL;
    f.fim = NULL;
    return (f);
}

int filaVazia(Fila f)
{
    if (f.ini == NULL)
        return (TRUE);
    else
        return (FALSE);
}

void imprimeFila(Fila f)
{
    ApElemento ap;
    ap = f.ini;
    while (ap != NULL)
    {
        printf("%d - ", ap->dado);
        ap = ap->prox;
    }
    printf("\n");
}

Fila insereFila(Fila f, int e)
{
    ApElemento novo;
    
    novo = malloc(sizeof(struct elemento));
    novo->dado = e;
    novo->prox = NULL;
    if (filaVazia(f))
    {
        f.ini = novo;
        f.fim = novo;
    }
    else
    {
        f.fim->prox = novo;
        f.fim = novo;
    }
    return (f);
}

Fila retiraFila(Fila f, int *e)
{
    ApElemento ap;
    if (!filaVazia(f))
    {
        *e = f.ini->dado;
        ap = f.ini;
        f.ini = f.ini->prox;
        free(ap);
        if (filaVazia(f))
            f.fim = NULL;
    }
    else
    {
        *e = -1;
        printf("\nFila Vazia");
    }
    return (f);
}


void menu(){
    printf("\n-----[MENU]-----\n");
    printf("[1]- Enfilar um elemento\n"); 
    printf("[2]- Tirar o elemento da fila\n");
    printf("[3]- Apresentar o conteudo da fila\n");
    printf("[0]- Sair\n");
}

int main()
{
    int opcao;
    int valor;
    Fila f = criaFila();

    do
    {
        menu();
        printf("\nSelecione a opcao desejada: ");
        scanf("%d", &opcao);
        if(opcao >3){
            printf("\nOpcao invalida. Digite novamente: ");
            scanf("%d", &opcao);
        }

        switch (opcao)
        {
        case 1:
            printf("\n----[ENFILAR]----");
            printf("\n\nDigite o elemento que deseja inserir na FILA: ");
            scanf("%d", &valor);
            f = insereFila(f, valor);
            printf("\nElemento %d inserido com sucesso!\n", valor);
            break;
        case 2:
            printf("\n---[RETIRAR DA FILA]---\n");
            int pont=0;
            f = retiraFila(f, &pont);
            printf("\nElemento %d retirado da fila", pont);
            break;
        case 3:
            printf("\n----[ITENS DA FILA]----\n");
            imprimeFila(f);
            break;
        }
    } while (opcao != 0);
    printf("Saindo...");
    
}
