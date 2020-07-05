#include <stdio.h>
#include <stdlib.h>

typedef struct s_lista Lista;
struct s_lista {
    int * item;
    int quantidade;
};

void cria (Lista *, int);
void lerLista (Lista *, int);
void insere (Lista *, int);
void exclui (Lista *, int);
int busca (Lista *, int);
int compara(Lista *, Lista*);

int main () {
    Lista listaQ, listaR;
    int q, r, chave, i = 0;
    char operador;
    scanf("%d %d", &q, &r);
    cria(&listaQ, q);
    cria(&listaR, r);
    lerLista(&listaQ, q);
    lerLista(&listaR, r);
    printf("%s\n", compara(&listaQ, &listaR) ? "SIM" : "NAO");
    return 0;
}

void cria (Lista *lista, int n) {
    lista -> item = (int *)malloc(n * sizeof(int));
    lista -> quantidade = 0;
}

void lerLista (Lista *lista, int n) {
    int i = 0, chave;
    char operador;
    while (i < n) {
        scanf("\n%c %d", &operador, &chave);
        if (operador == 'I') {
            insere (lista, chave);
        } else if (operador == 'E') {
            exclui(lista, chave);
        }
        i++;
    }
}

void insere (Lista *lista, int chave) {
    int i = 0, j;
    while (i < lista -> quantidade && chave > lista -> item[i]) {
        i++;
    }
    if (i < lista -> quantidade && chave  == lista -> item[i]) {
        return;
    }
    j = lista -> quantidade;
    while (j > i) {
        lista -> item[j] = lista -> item[j - 1];
        j--;
    }
    lista -> item[i] = chave;
    lista -> quantidade++;
}

void exclui (Lista *lista, int chave) {
    int i = 0, j;
    while (i < lista -> quantidade && chave != lista -> item[i]) {
        i++;
    }
    j = i + 1;
    while (j < lista -> quantidade) {
        lista -> item[j - 1] = lista -> item[j];
        j++;
    }
    if (i < lista -> quantidade) {
        lista -> quantidade--;
    }
}

int busca (Lista *lista, int chave) {
    int esquerda, direita, meio;
    esquerda = 0;
    direita = lista -> quantidade - 1;
    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (lista -> item[meio]  == chave) {
            return 1;
        }
        if (lista -> item[meio] > chave) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return 0;
}

int compara (Lista * listaQ, Lista * listaR) {
    int i = 0;
    while (i < listaQ -> quantidade) {
        if (!busca(listaR, listaQ -> item[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}
