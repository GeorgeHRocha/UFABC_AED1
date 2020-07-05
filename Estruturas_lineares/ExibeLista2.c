#include <stdio.h>
#include <stdlib.h>

typedef struct s_lista Lista;
typedef struct s_item Item;

struct s_item {
    int dado;
    Item *prox;
};
struct s_lista {
    Item *inicio;
};

Lista *criaLista();
Item *criaItem(int);
void lerLista (Lista *lista);
void insere(Lista *, Item *);
void imprimirReverso(Item *);
void limpaLista (Lista *);

int main () {
    Lista *lista = criaLista();
    int q, i = 0;
    scanf("%d", &q);
    while (i < q) {
        lerLista(lista);
        imprimirReverso(lista -> inicio);
        limpaLista(lista);
        i++;
    }
    return 0;
}

Lista *criaLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL) {
        lista -> inicio = NULL;
    }
    return lista;
}

Item *criaItem(int dado) {
    Item *item = (Item*)malloc(sizeof(Item));
    if (item != NULL) {
        item -> dado = dado;
        item -> prox = NULL;
    }
    return item;
}

void lerLista (Lista *lista) {
    int i = 0, chave, n;
    scanf("%d", &n);
    while (i < n) {
        scanf("%d", &chave);
        insere(lista, criaItem(chave));
        i++;
    }
}

void insere(Lista *lista, Item *item) {
    Item *anterior = NULL;
    Item *atual = lista -> inicio;
    while (atual != NULL) {
        anterior = atual;
        atual = atual -> prox;
    }
    if (anterior == NULL) {
        lista -> inicio = item;
    } else {
        anterior -> prox = item;
    }
}

void imprimirReverso (Item *item) {
    if (item != NULL) {
        imprimirReverso(item -> prox);
        printf("%d\n", item -> dado);
    }
}

void limpaLista (Lista *lista) {
    Item *item = lista -> inicio;
    while (item != NULL) {
        lista -> inicio = item -> prox;
        free(item);
        item = lista -> inicio;
    }
}