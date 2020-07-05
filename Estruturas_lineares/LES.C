#include <stdio.h>
#include <stdlib.h>

typedef struct s_lista Lista;
struct s_lista {
    int * item;
    int quantidade;
};

void insere (Lista *, int);
void cria (Lista *, int);
void exclui (Lista *, int);
int busca (Lista *, int);
void imprime(Lista *);

int main () {
    Lista lista;
    int n, chave, i = 0;
    char operador;
    scanf("%d", &n);
    cria(&lista, n);
    while (i < n) {
        scanf("\n%c", &operador);
        scanf("%d", &chave);
        if (operador == 'I') {
            insere (&lista, chave);
        } else if (operador == 'E') {
            exclui(&lista, chave);
        }
        i++;
    }
    imprime (&lista);
    return 0;
}

void cria (Lista *lista, int n) {
    lista -> item = (int *)malloc(n * sizeof(int));
    lista -> quantidade = 0;
}

int busca (Lista *lista, int chave) {
    int esquerda, direita, meio;
    esquerda = 0;
    direita = lista -> quantidade - 1;
    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (lista -> item[meio]  == chave) {
            return meio;
        }
        if (lista -> item[meio] > chave) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return -1;
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

void imprime (Lista *lista) {
    int i = 0;
    while (i < lista -> quantidade) {
        printf("%d\n", lista -> item[i]);
        i++;
    }
}
