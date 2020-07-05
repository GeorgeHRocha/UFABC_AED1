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
void lerLista (Lista *);
void insere(Lista *, Item *);
Lista *intercalaListas(Lista *, Lista*);
void imprimir(Lista *);
void limpaLista (Lista *);


int main () {
    Lista *listaA, *listaB;
    int q, i = 0;
    listaA = criaLista();
    listaB = criaLista();
    scanf("%d", &q);
    while (i < q) {
        lerLista(listaA);
        lerLista(listaB);
        imprimir(intercalaListas(listaA, listaB));
        limpaLista(listaA);
        limpaLista(listaB);
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

Lista *intercalaListas(Lista *listaA, Lista *listaB) {
    Lista *lista = criaLista();
    Item *itemA = listaA -> inicio, *itemB = listaB -> inicio;
    while (itemA != NULL && itemB != NULL) {
        if (itemA -> dado < itemB -> dado) {
            insere(lista, criaItem(itemA -> dado));
            itemA = itemA -> prox;
        } else {
            insere(lista, criaItem(itemB -> dado));
            itemB = itemB -> prox;
        }
    }
    while (itemA != NULL) {
        insere(lista, criaItem(itemA -> dado));
        itemA = itemA -> prox;
    }
    while (itemB != NULL) {
        insere(lista, criaItem(itemB -> dado));
        itemB = itemB -> prox;
    }
    return lista;
}

void imprimir (Lista *lista) {
    Item *item = lista -> inicio;
    while (item != NULL) {
        printf("%d%s", item -> dado, item -> prox != NULL ? " " : "\n");
        item = item -> prox;
    }
    limpaLista(lista);
}

void limpaLista (Lista *lista) {
    Item *item = lista -> inicio;
    while (item != NULL) {
        lista -> inicio = item -> prox;
        free(item);
        item = lista -> inicio;
    }
}