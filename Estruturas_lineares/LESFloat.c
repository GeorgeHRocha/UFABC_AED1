#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_lista Lista;
struct s_lista {
    float * item;
    int quantidade, tamanho;
};

void insere (Lista *, float);
void cria (Lista *, int);
void exclui (Lista *, float);
int busca (Lista *, float);
void imprime(Lista *);

int main () {
    Lista lista;
    int n, i = 0;
    char operador;
    float chave;
    scanf("%d", &n);
    cria(&lista, n);
    while (scanf("\n%c", &operador) != EOF) {
        if (operador == 'I') {
            scanf("%f", &chave);
            insere(&lista, chave);
        } else if (operador == 'R') {
            scanf("%f", &chave);
            exclui(&lista, chave);
        } else if (operador == 'B') {
            scanf("%f", &chave);
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
    lista -> item = (float *)malloc(n * sizeof(float));
    lista -> quantidade = 0;
    lista -> tamanho = n;
}

int busca (Lista *lista, float chave) {
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

void insere (Lista *lista, float chave) {
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

void exclui (Lista *lista, float chave) {
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
        if(fmod(lista -> item[i], 1) == 0) {
            printf("%.0f%s", lista -> item[i], (i < (lista -> quantidade - 1) ? " " : "\n"));
        } else {
            printf("%.1f%s", lista -> item[i], (i < (lista -> quantidade - 1) ? " " : "\n"));
        }
        i++;
    }
}
