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
Item *remover(Lista *, int);
int busca (Lista *, int);
void imprimir(Lista *);


int main () {
    char operacao;
    int chave;
    Lista *lista = criaLista();
    Item *removido;
    while (scanf("\n%c", &operacao) != EOF) {
        if (operacao == 'I') {
            scanf("%d", &chave);
            insere(lista, criaItem(chave));
        } else if (operacao == 'R') {
            scanf("%d", &chave);
            removido = remover(lista, chave);
            if (removido != NULL) {
                printf("REMOVIDO: %d\n", removido -> dado);
            }
            free(removido);
        } else if (operacao == 'B') {
            scanf("%d", &chave);
            if (busca(lista, chave)) {
                printf("SIM\n");
            }
        } else if (operacao == 'M') {
            imprimir(lista);
        }
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
    while (atual != NULL && item -> dado > atual -> dado) {
        anterior = atual;
        atual = atual -> prox;
    }
    if (atual != NULL && item -> dado == atual -> dado) {
        free(item);
        printf("Logic Error: Chave ja existe na Lista.\n");
        return;
    }
    if (anterior == NULL) {
        lista -> inicio = item;
    } else {
        anterior -> prox = item;
    }
    item -> prox = atual;
}

Item *remover(Lista *lista, int chave) {
    Item *anterior = NULL;
    Item * atual = lista -> inicio;
    if (atual == NULL) {
        printf("Underflow Error: Lista Vazia.\n");
    } else {
        while (atual != NULL && atual -> dado != chave) {
            anterior = atual;
            atual = atual -> prox;
        }
        if (atual != NULL) {
            if (anterior == NULL) {
                lista -> inicio = atual -> prox;
            } else {
                anterior -> prox = atual -> prox;
            }
            atual -> prox = NULL;
        } else {
            printf("Logic Error: Chave inexistente na Lista.\n");
        }
    }
    return atual;
}

int busca(Lista *lista, int chave) {
    Item *atual = lista -> inicio;
    if (atual == NULL) {
        printf("Underflow Error: Lista Vazia.\n");
    } else {
        while (atual != NULL && atual -> dado != chave) {
            atual = atual -> prox;
        }
        if (atual != NULL) {
            return 1;
        }
        printf("Logic Error: Chave inexistente na Lista.\n");
    }
    return 0;
}

void imprimir (Lista *lista) {
    Item *item = lista -> inicio;
    if (item == NULL){
        printf("Underflow Error: Lista Vazia.\n");
    }
    while (item != NULL) {
        printf("%d%s", item -> dado, item -> prox != NULL ? " " : "\n");
        item = item -> prox;
    }
}