#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_lista Lista;
struct s_lista {
    char ** item;
    int quantidade, tamanho;
};

void insere (Lista *, char[]);
void cria (Lista *, int);
void exclui (Lista *, char[]);
int busca (Lista *, char[]);
void imprime(Lista *);

int main () {
    Lista lista;
    int n, i = 0;
    char operador;
    char chave[50];
    scanf("%d", &n);
    cria(&lista, n);
    while (scanf("\n%c", &operador) != EOF) {
        if (operador == 'I') {
            scanf("%s", chave);
            insere(&lista, chave);
        } else if (operador == 'R') {
            scanf("%s", chave);
            exclui(&lista, chave);
        } else if (operador == 'B') {
            scanf("%s", chave);
            if (busca(&lista, chave)) {
                printf("SIM\n");
            } else {
                printf("NAO\n");
            }
        } else if (operador == 'M') {
            imprime (&lista);
        }
    }
    return 0;
}

void cria (Lista *lista, int n) {
    int i = 0;
    lista -> item = (char**)malloc(n * sizeof(char*));
    while (i < n) {
        lista -> item[i] = (char *)calloc(50, sizeof(char));
        i++;
    }
    lista -> quantidade = 0;
    lista -> tamanho = n;
}

int busca (Lista *lista, char chave[]) {
    int esquerda, direita, meio;
    esquerda = 0;
    direita = lista -> quantidade - 1;
    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (strcmp(lista -> item[meio], chave) == 0) {
            return 1;
        }
        if (strcmp(lista -> item[meio], chave) > 0) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return 0;
}

void insere (Lista *lista, char chave[50]) {
    int i = 0, j;
    if (lista -> quantidade < lista -> tamanho) {
        while (i < lista -> quantidade && strcmp(chave, lista -> item[i]) > 0) {
            i++;
        }
        if (i < lista -> quantidade && strcmp(chave, lista -> item[i]) == 0) {
            return;
        }
        j = lista -> quantidade;
        while (j > i) {
            strcpy(lista -> item[j], lista -> item[j - 1]);
            j--;
        }
        strcpy(lista -> item[i], chave);
        lista -> quantidade++;
    }
}

void exclui (Lista *lista, char chave[]) {
    int i = 0, j;
    while (i < lista -> quantidade && strcmp(chave, lista -> item[i]) != 0) {
        i++;
    }
    j = i + 1;
    while (j < lista -> quantidade) {
        strcpy(lista -> item[j - 1], lista -> item[j]);
        j++;
    }
    if (i < lista -> quantidade) {
        lista -> quantidade--;
    }
}

void imprime (Lista *lista) {
    int i = 0;
    while (i < lista -> quantidade - 1) {
        printf("%s ", lista -> item[i]);
        i++;
    }
    if (lista -> quantidade > 0) {
        printf("%s\n", lista -> item[i]);
    }
}
