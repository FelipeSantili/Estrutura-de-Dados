#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct elemento {
    int dado;
    struct elemento *prox;
};
typedef struct elemento *Pilha;

Pilha criaPilha() {
    return NULL;
}

int pilhaVazia(Pilha p) {
    if (p == NULL)
        return (TRUE);
    else
        return (FALSE);
}

void imprimePilha(Pilha p) {
    Pilha ap;
    printf("\nItens da pilha:\n");
    
    if (!pilhaVazia(p)) {
        ap = p;
        while (ap->prox != NULL) {
            printf("%d - ", ap->dado);
            ap = ap->prox;
        }
        printf("%d", ap->dado); // Imprime o último elemento sem o hífen
    }

    printf("\n");
}


Pilha empilha(Pilha p, int e) {
    Pilha novo;
    novo = malloc(sizeof(struct elemento));
    novo->dado = e;
    novo->prox = p;
    return (novo);
}

Pilha desempilha(Pilha p, int *e) {
    Pilha ap;

    if (!pilhaVazia(p)) {
        *e = p->dado;
        ap = p;
        p = p->prox;
        free(ap);
    } else {
        *e = -1;
        printf("\nPilha Vazia\n\n");
    }
    return (p);
}

int main() {
    int opcao;
    int valor;
    int pont_valor; // Declare uma variável int para receber o valor desempilhado
    int *pont = &pont_valor; // Inicialize o ponteiro com o endereço da variável
    printf("\nExercicio lista encadeada\n");
    Pilha p = criaPilha();

    do {
        printf("\n[----------MENU----------]");
        printf("\n\n1 -- Empilhar elemento \n2 - Desempilhar um elemento\n3 - Imprimir conteudo da pilha\n4 -- Sair\n");
        printf("\nSelecione a opção desejada: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n[-------Empilhar-------]");
                printf("\n\nDigite o elemento que deseja inserir na pilha: ");
                scanf("%d", &valor);
                p = empilha(p, valor);
                break;
            case 2:
                printf("\n[------Desempilhar------]");
                p = desempilha(p, pont);
                printf("Elemento desempilhado: %d\n", *pont);
                break;
            case 3:
                printf("\n[--------Imprime--------]");
                imprimePilha(p);
                break;
        }
    } while (opcao != 4);

    printf("Sair.....");

    return 0;
}
