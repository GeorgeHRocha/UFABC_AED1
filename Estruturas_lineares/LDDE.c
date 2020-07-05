#include <stdio.h>
#include <stdlib.h>

typedef struct s_item Item;
typedef struct s_lista Lista;

struct s_item {
    int dado;
    Item *prox, * ant;
};
struct s_lista {
    Item *primeiro, *ultimo;
};

Item *criaItem(int);
Lista *criaLista();
void insere(Lista *, Item *);
Item *remover(Lista *, int);
void mostrar(Lista *);
void rMostrar(Lista *);

int main() {
    char operador;
    int chave;
    Lista *lista = criaLista();
    Item *removido;
    while (scanf("\n%c", &operador) != EOF) {
        if (operador == 'I') {
            scanf("%d", &chave);
            insere(lista, criaItem(chave));
        } else if (operador == 'E') {
            scanf("%d", &chave);
            removido = remover(lista, chave);
            free(removido);
        } else if (operador == 'M') {
            mostrar(lista);
        } else if (operador == 'R') {
            rMostrar(lista);
        }
    }
    return 0;
}

Item *criaItem(int dado) {
    Item *item = (Item *)malloc(sizeof(Item));
    if (item != NULL) {
        item -> dado = dado;
        item -> ant = NULL;
        item -> prox = NULL;
    }
    return item;
}

Lista *criaLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL) {
        lista -> primeiro = NULL;
        lista -> ultimo = NULL;
    }
    return lista;
}

void insere (Lista *lista, Item *item) {
    Item *anterior = NULL;
    Item *atual = lista -> primeiro;
    while (atual != NULL && item -> dado > atual -> dado) {
        anterior = atual;
        atual = atual -> prox;
    }
    if (atual != NULL && item -> dado == atual -> dado) {
        free(item);
        return;
    }
    if (atual == NULL) {
        lista -> ultimo = item;
    } else {
        atual -> ant = item;
    }
    if (anterior == NULL) {
        lista -> primeiro = item;
    } else {
        anterior -> prox = item;
    }
    item -> ant = anterior;
    item -> prox = atual;
}

Item *remover(Lista *lista, int dado) {
    Item *anterior = NULL, *atual = lista -> primeiro;
    while (atual != NULL && dado != atual -> dado) {
        anterior = atual;
        atual = atual -> prox;
    }
    if (atual != NULL) {
        if (anterior == NULL) {
			lista -> primeiro = atual -> prox;
        } else {
			anterior -> prox = atual -> prox;
        }
        if (atual -> prox == NULL) {
            lista -> ultimo = anterior;
        } else {
            atual -> prox -> ant = anterior;
        }
        atual -> ant = NULL;
		atual -> prox = NULL;
    }
    return atual;
}

void mostrar(Lista *lista) {
    Item *item = lista -> primeiro;
    while (item != NULL) {
        printf("%d ", item -> dado);
        item = item -> prox;
    }
    printf("\n");
}

void rMostrar(Lista *lista) {
    Item *item = lista -> ultimo;
    while (item != NULL) {
        printf("%d ", item -> dado);
        item = item -> ant;
    }
    printf("\n");
}
