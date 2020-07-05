#include <stdio.h>
#include <stdlib.h>

typedef struct s_item Item;
typedef struct s_fila Fila;

struct s_item {
    int dado;
    Item *prox;
};
struct s_fila {
    Item *inicio, *fim;
};

Fila *criaFila();
Item *criaItem(int);
void incluir(Fila *, Item *);
Item *excluir(Fila *);
void mostrar(Fila *);

int main () {
    char operacao;
    Fila *fila = criaFila();
    int chave;
    Item *removido;
    while (scanf("\n%c", &operacao) != EOF) {
        if (operacao == 'E') {
            scanf("%d", &chave);
            incluir(fila, criaItem(chave));
        } else if (operacao == 'D') {
            scanf("%d", &chave);
            removido = excluir(fila);
            if (removido != NULL) {
                printf("<%d>\n", removido -> dado);
            }
        } else if (operacao == 'M') {
            mostrar(fila);
        }
    }
    return 0;
}

Fila *criaFila() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila -> inicio = NULL;
        fila -> fim == NULL;
    }
    return fila;
}

Item *criaItem(int dado) {
    Item *item = (Item *)malloc(sizeof(item));
    if (item != NULL) {
        item -> dado = dado;
        item -> prox = NULL;
    }
    return item;
}

void incluir (Fila *fila, Item *item) {
    Item *final = fila -> fim;
    fila -> fim = item;
    if (fila -> inicio != NULL) {
        final -> prox = item;
    } else {
        fila -> inicio = item;
    }
}

Item *excluir(Fila *fila) {
    Item *removido = fila -> inicio;
    if (fila -> inicio == fila -> fim) {
        fila -> inicio = NULL;
        fila -> fim = NULL;
    } else {
        fila -> inicio = removido -> prox;
        removido -> prox = NULL;
    }
    return removido;
}

void mostrar (Fila *fila) {
    Item *atual = fila -> inicio;
    while (atual != fila -> fim) {
        printf("%d ", atual -> dado);
        atual = atual -> prox;
    }
    if (atual != NULL) {
        printf("%d\n", atual -> dado);
    }
}