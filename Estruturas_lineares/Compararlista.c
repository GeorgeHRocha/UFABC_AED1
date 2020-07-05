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
void insere(Lista *, Item*);
void limpaLista (Lista *);
int compara (Lista *, Lista *);

int main () {
    int q, i = 0, na, nb, j, chave;
    Lista *listaA = criaLista();
    Lista *listaB = criaLista();
    scanf("%d", &q);
    while (i < q) {
        scanf("%d", &na);
        j = 0;
        while (j < na) {
            scanf("%d", &chave);
            insere(listaA, criaItem(chave));
            j++;
        }
        scanf("%d", &nb);
        j = 0;
        while (j < nb) {
            scanf("%d", &chave);
            insere(listaB, criaItem(chave));
            j++;
        }
        printf("%d\n", compara(listaA, listaB));
        limpaLista(listaA);
        limpaLista(listaB);
        i++;
    }
    return 0;
}

Lista *criaLista() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
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

void limpaLista (Lista *lista) {
    Item *item = lista -> inicio, *aux;
    while (item != NULL) {
        aux = item;
        item = item -> prox;
        free(aux);
    }
    lista -> inicio = NULL;
}

int compara (Lista *listaA, Lista *listaB) {
    Item *itemA = listaA -> inicio;
    Item *itemB = listaB -> inicio;
    while (itemA != NULL && itemB != NULL) {
        if (itemA -> dado != itemB -> dado) {
            return 0;
        }
        itemA = itemA -> prox;
        itemB = itemB -> prox;
    }
    if (itemA == NULL && itemB == NULL) {
        return 1;
    }
    return 0;
}
