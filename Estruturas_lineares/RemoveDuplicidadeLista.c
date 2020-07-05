#include <stdio.h>
#include <stdlib.h>

typedef struct s_lista Lista;
typedef struct s_item Item;

struct s_item {
    long dado;
    Item *prox;
};
struct s_lista {
    Item *inicio;
};

Lista *criaLista ();
Item *criaItem (long);
void leLista (Lista *, int);
void insere (Lista *, Item *);
Lista *removeDuplicatas (Lista *);
void limpaLista (Lista *);
void imprimir (Lista *);

int main () {
    Lista *lista = criaLista();
    int q, n, i = 0;
    scanf("%d", &q);
    while (i < q) {
        scanf("%d", &n);
        leLista(lista, n);
        imprimir(removeDuplicatas(lista));
        limpaLista(lista);
        i++;
    }
    return 0;
}

Lista *criaLista () {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL) {
        lista -> inicio = NULL;
    }
    return lista;
}

Item *criaItem (long dado) {
    Item *item = (Item*)malloc(sizeof(Item));
    if (item != NULL) {
        item -> dado = dado;
        item -> prox = NULL;
    }
    return item;
}

void leLista (Lista *lista, int n) {
    int i = 0;
    long chave;
    while (i < n) {
        scanf("%ld", &chave);
        insere(lista, criaItem(chave));
        i++;
    }
}

void insere (Lista *lista, Item *item) {
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

Lista *removeDuplicatas (Lista *lista) {
    Item *anterior = NULL, *atual = lista -> inicio;
    while (atual != NULL) {
        if (anterior != NULL && anterior -> dado == atual -> dado) {
            anterior -> prox = atual -> prox;
            free(atual);
            atual = anterior -> prox;
        } else {
            anterior = atual;
            atual = atual -> prox;
        }
    }
    return lista;
}

void limpaLista (Lista *lista) {
    Item *item = lista -> inicio;
    while (item != NULL) {
        lista -> inicio = item -> prox;
        free(item);
        item = lista -> inicio;
    }
}

void imprimir (Lista *lista) {
    Item *item = lista -> inicio;
    while (item != NULL) {
        printf("%ld%s", item -> dado, item -> prox != NULL ? " " : "\n");
        item = item -> prox;
    }
}