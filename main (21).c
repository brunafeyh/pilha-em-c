#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct no {
    int num;
    struct no *prox;
};

int vazia(struct no *st) {
    return (st == NULL);
}

void limpar_pilha(struct no *st) {
    if (!vazia(st)) {
        struct no *temp = st->prox;
        free(st);
        limpar_pilha(temp);
    }
}

struct no *push(struct no *st, int num) {
    struct no *aux = (struct no *)malloc(sizeof(struct no));
    aux->num = num;
    aux->prox = NULL;

    if (!vazia(st)) {
        aux->prox = st;
    }

    return aux;
}

struct no *pop(struct no *st) {
    if (!vazia(st)) {
        struct no *temp = st;
        st = st->prox;
        free(temp);
    }
    return st;
}

int topo(struct no *st) {
    if (vazia(st)) {
        return -1;
    }
    return st->num;
}

void imprimir(struct no *st) {
    if (!vazia(st)) {
        printf(" %d", st->num);
        imprimir(st->prox);
    }
}

int main() {
    struct no *pilha1 = NULL;

    printf("A pilha 1 é vazia? RESPOSTA = %d\n\n", vazia(pilha1));

    pilha1 = push(pilha1, 10);
    pilha1 = push(pilha1, 20);
    pilha1 = push(pilha1, 30);
    pilha1 = push(pilha1, 40);

    printf("Pilha 1 =");
    imprimir(pilha1);
    printf("\n");

    printf("O topo da pilha 1 é: %d\n\n", topo(pilha1));

    pilha1 = pop(pilha1);

    printf("Pilha 1 =");
    imprimir(pilha1);
    printf("\n");

    printf("A pilha 1 é vazia? RESPOSTA = %d\n\n", vazia(pilha1));
    limpar_pilha(pilha1);
    pilha1 = NULL;
    printf("A pilha 1 é vazia? RESPOSTA = %d\n\n", vazia(pilha1));

    return 0;
}
