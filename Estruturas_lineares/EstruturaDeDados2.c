#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_item Item;
typedef struct s_lista Lde;
typedef struct s_fila Fila;
typedef struct s_pilha Pilha;
typedef struct s_estrutura Estrutura;

struct s_item {
    int dado;
    Item *prox;
};
struct s_lista {
    Item *inicio;
};
struct s_fila {
    Item *inicio, *fim;
};
struct s_pilha {
    Item *topo;
};
struct s_estrutura {
    Lde *lde;
    Fila *fila;
    Pilha *pilha;
    char nome[10];
};

Estrutura criaEstrutura(char []);
Item *criaItem(int);

Lde *criaLde();
void insereLde(Lde *, Item *);
Item *removeLde(Lde *, int);
void mostraLde(Lde *);

Fila *criaFila();
void insereFila(Fila *, Item *);
Item *removeFila(Fila *);
void mostraFila(Fila *);

Pilha *criaPilha();
void inserePilha(Pilha *, Item *);
Item *removePilha(Pilha *);
void mostraPilha(Pilha *, Item *);

int main () {
    int n, i = 0, pos_ed, chave;
    char nome [10], op;
    Estrutura *estrutura;
    Item *removido;
    scanf("%d", &n);
    estrutura = (Estrutura *)malloc(n * sizeof(Estrutura));
    while (i < n) {
        scanf("%s", nome);
        estrutura[i] = criaEstrutura(nome);
        i++;
    }
    while (scanf("%d %c", &pos_ed, &op) != EOF) {
        if (op == 'I') {
            scanf("%d", &chave);
            if (strcmp(estrutura[pos_ed].nome, "LDE") == 0) {
                insereLde(estrutura[pos_ed].lde, criaItem(chave));
            } else if (strcmp(estrutura[pos_ed].nome, "FILA") == 0) {
                insereFila(estrutura[pos_ed].fila, criaItem(chave));
            } else if (strcmp(estrutura[pos_ed].nome, "PILHA") == 0) {
                inserePilha(estrutura[pos_ed].pilha, criaItem(chave));
            }
        } else if (op == 'R') {
            if (strcmp(estrutura[pos_ed].nome, "LDE") == 0) {
                scanf("%d", &chave);
                removido = removeLde(estrutura[pos_ed].lde, chave);
            } else {
                if (strcmp(estrutura[pos_ed].nome, "FILA") == 0) {
                    removido = removeFila(estrutura[pos_ed].fila);
                } else if (strcmp(estrutura[pos_ed].nome, "PILHA") == 0) {
                    removido = removePilha(estrutura[pos_ed].pilha);
                }
            }
            if (removido != NULL) {
                printf("REMOVIDO: %d\n", removido -> dado);
            }
        } else if (op == 'M') {
            if (strcmp(estrutura[pos_ed].nome, "LDE") == 0) {
                mostraLde(estrutura[pos_ed].lde);
            } else if (strcmp(estrutura[pos_ed].nome, "FILA") == 0) {
                mostraFila(estrutura[pos_ed].fila);
            } else if (strcmp(estrutura[pos_ed].nome, "PILHA") == 0) {
                mostraPilha(estrutura[pos_ed].pilha, estrutura[pos_ed].pilha -> topo);
            }
        }
    }
    return 0;
}

Estrutura criaEstrutura(char nome[]) {
    Estrutura estrutura;
    if (strcmp(nome, "LDE") == 0) {
        estrutura.lde = criaLde();
    } else if (strcmp(nome, "FILA") == 0) {
        estrutura.fila = criaFila();
    } else if (strcmp(nome, "PILHA") == 0) {
        estrutura.pilha = criaPilha();
    }
    strcpy(estrutura.nome, nome);
    return estrutura;
}

Item *criaItem(int dado) {
    Item *item = (Item*)malloc(sizeof(Item));
    if (item != NULL) {
        item -> dado = dado;
        item -> prox = NULL;
    }
    return item;
}

Lde *criaLde() {
    Lde *lde = (Lde *)malloc(sizeof(lde));
    if (lde != NULL) {
        lde -> inicio = NULL;
    }
    return lde;
}

void insereLde(Lde *lde, Item *item) {
    Item *anterior = NULL;
    Item *atual = lde -> inicio;
    while (atual != NULL && item -> dado > atual -> dado) {
        anterior = atual;
        atual = atual -> prox;
    }
    if (atual != NULL && item -> dado == atual -> dado) {
        free(item);
        return;
    }
    if (anterior == NULL) {
        lde -> inicio = item;
    } else {
        anterior -> prox = item;
    }
    item -> prox = atual;
}

Item *removeLde(Lde *lde, int chave) {
    Item *anterior = NULL;
    Item * atual = lde -> inicio;
    while (atual != NULL && atual -> dado != chave) {
        anterior = atual;
        atual = atual -> prox;
    }
    if (atual != NULL) {
        if (anterior == NULL) {
            lde -> inicio = atual -> prox;
        } else {
            anterior -> prox = atual -> prox;
        }
        atual -> prox = NULL;
    }
    return atual;
}

void mostraLde(Lde *lde) {
    Item *item = lde -> inicio;
    while (item != NULL) {
        printf("%d%s", item -> dado, item -> prox != NULL ? " " : "\n");
        item = item -> prox;
    }
}

Fila *criaFila() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila -> inicio = NULL;
        fila -> fim == NULL;
    }
    return fila;
}

void insereFila(Fila *fila, Item *item) {
    Item *final = fila -> fim;
    fila -> fim = item;
    if (fila -> inicio != NULL) {
        final -> prox = item;
    } else {
        fila -> inicio = item;
    }
}

Item *removeFila(Fila *fila) {
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

void mostraFila(Fila *fila) {
    Item *atual = fila -> inicio;
    while (atual != fila -> fim) {
        printf("%d ", atual -> dado);
        atual = atual -> prox;
    }
    if (atual != NULL) {
        printf("%d\n", atual -> dado);
    }
}

Pilha *criaPilha () {
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha -> topo = NULL;
    }
    return pilha;
}

void inserePilha(Pilha *pilha, Item *item) {
    item -> prox = pilha -> topo;
    pilha -> topo = item;
}

Item *removePilha(Pilha *pilha) {
    Item *removido = pilha -> topo;
    if (pilha -> topo != NULL) {
        pilha -> topo = removido -> prox;
        removido -> prox = NULL;
    }
    return removido;
}

void mostraPilha (Pilha *pilha, Item *item) {
    if (item != NULL) {
        mostraPilha(pilha, item -> prox);
        printf("%d%s", item -> dado, item != pilha ->topo ? " " : "\n");
    }
}
