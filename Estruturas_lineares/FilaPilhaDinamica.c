#include <stdio.h>
#include <stdlib.h>

typedef struct s_item Item;
typedef struct s_fila Fila;
typedef struct s_pilha Pilha;

struct s_item {
    int dado;
    Item *prox;
};
struct s_fila {
    Item *inicio, *fim;
};
struct s_pilha {
    Item *topo;
};

Item *criaItem(int);
Fila *criaFila();
Pilha *criaPilha();
void incluir(Fila *, Item *);
Item *excluir(Fila *);
void empilha(Pilha *, Item *);
Item *desempilha(Pilha *);
void filaPilha(Item *, Pilha *);
void limpaPilha(Pilha *);
void mostrarPilha(Pilha *);

int main () {
    char operacao;
    Fila *fila = criaFila();
    Pilha *pilha = criaPilha();
    int chave;
    Item *removido;
    while (scanf("\n%c", &operacao) != EOF) {
        if (operacao == 'E') {
            scanf("%d", &chave);
            incluir(fila, criaItem(chave));
        } else if (operacao == 'D') {
            scanf("%d", &chave);
            removido = excluir(fila);
        } else if (operacao == 'P') {
            limpaPilha(pilha);
            filaPilha(fila -> inicio, pilha);
        } else if (operacao == 'M') {
            mostrarPilha(pilha);
        }
    }
    return 0;
}

Item *criaItem(int dado) {
    Item *item = (Item *)malloc(sizeof(item));
    if (item != NULL) {
        item -> dado = dado;
        item -> prox = NULL;
    }
    return item;
}

Fila *criaFila() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila -> inicio = NULL;
        fila -> fim == NULL;
    }
    return fila;
}

Pilha *criaPilha () {
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha -> topo = NULL;
    }
    return pilha;
}

void incluir(Fila *fila, Item *item) {
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

void empilha (Pilha *pilha, Item *item) {
    item -> prox = pilha -> topo;
    pilha -> topo = item;
}

Item *desempilha(Pilha *pilha) {
    Item *removido = pilha -> topo;
    if(pilha -> topo != NULL) {
        pilha -> topo = removido -> prox;
        removido -> prox = NULL;
    }
    return removido;
}

void filaPilha(Item *item, Pilha *pilha) {
    if (item != NULL) {
        filaPilha(item -> prox, pilha);
        empilha(pilha, item);
    }
}

void limpaPilha(Pilha *pilha) {
    Item *item;
    while(pilha -> topo != NULL) {
        item = desempilha(pilha);
        free(item);
    }
}

void mostrarPilha (Pilha *pilha) {
    Item *atual = pilha -> topo;
    while (atual != NULL) {
        printf("%d\n", atual-> dado);
        atual = atual -> prox;
    }
}
