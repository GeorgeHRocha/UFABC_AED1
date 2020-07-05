#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_item Item;
typedef struct s_pilha Pilha;

struct s_item {
    char dado;
    Item *ant;
};
struct s_pilha {
    Item *topo;
};

Pilha *criaPilha();
Item *criaItem(char);
void empilha(Pilha *, Item *);
Item *desempilha(Pilha *);

int main() {
    Pilha *pilha = criaPilha();
    Item *removido;
    char rna[301];
    int i, qtLigacoes;
    while(scanf("%s", rna) != EOF) {
        i = qtLigacoes = 0;
        while(i < strlen(rna)) {
            if (pilha -> topo == NULL || ((pilha -> topo -> dado == 'B' && rna[i] != 'S') || (pilha -> topo -> dado == 'S' && rna[i] != 'B') || (pilha -> topo -> dado == 'C' && rna[i] != 'F') || (pilha -> topo -> dado == 'F' && rna[i] != 'C'))) {
                empilha(pilha, criaItem(rna[i]));
            } else {
                qtLigacoes++;
                removido = desempilha(pilha);
                free(removido);
            }
            i++;
        }
        printf("%d\n", qtLigacoes);
        while (pilha -> topo != NULL) {
            removido = desempilha(pilha);
            free(removido);
        }
    }
    return 0;
}

Pilha *criaPilha() {
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha -> topo = NULL;
    }
    return pilha;
}

Item *criaItem(char dado) {
    Item *item = (Item*)malloc(sizeof(Item));
    if(item != NULL) {
        item -> dado = dado;
        item -> ant = NULL;
    }
    return item;
}

void empilha(Pilha *pilha, Item *item) {
    item -> ant = pilha -> topo;
    pilha -> topo = item;
}

Item *desempilha(Pilha *pilha) {
    Item *removido = pilha -> topo;
    if(pilha -> topo != NULL) {
        pilha -> topo = removido -> ant;
        removido -> ant = NULL;
    }
    return removido;
}

