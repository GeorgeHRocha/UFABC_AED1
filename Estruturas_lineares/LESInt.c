#include <stdio.h>
#include <stdlib.h>

typedef struct s_lista Lista;
struct s_lista {
    int * item;
    int quantidade, tamanho;
};

void cria (Lista *, int);
void insere (Lista *, int);
void exclui (Lista *, int);
int busca (Lista *, int);
void imprime(Lista *);

int main () {
    Lista lista;
    int n, i = 0;
    char operador;
    int chave;
    scanf("%d", &n);
    cria(&lista, n);
    while (scanf("\n%c", &operador) != EOF) {
        if (operador == 'I') {
            scanf("%d", &chave);
            insere(&lista, chave);
        } else if (operador == 'R') {
            scanf("%d", &chave);
            exclui(&lista, chave);
        } else if (operador == 'B') {
            scanf("%d", &chave);
            printf("%s\n", busca(&lista, chave) ? "SIM" : "NAO");
        } else if (operador == 'M') {
            imprime (&lista);
        }
    }
    return 0;
}

void cria (Lista *lista, int n) {
    lista -> item = (int *)malloc(n * sizeof(int));
    lista -> quantidade = 0;
    lista -> tamanho = n;
}

void insere (Lista *lista, int chave) {
    int i = 0, j;
    if (lista -> quantidade < lista -> tamanho) {
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

void imprime (Lista *lista) {
    int i = 0;
    while (i < lista -> quantidade) {
        printf("%d%s", lista -> item[i], i < lista -> quantidade - 1 ? " " : "\n");
        i++;
    }
}
