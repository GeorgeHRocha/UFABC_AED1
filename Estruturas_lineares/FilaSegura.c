#include <stdio.h>
#include <stdlib.h>

typedef struct s_fila Fila;

void cria (Fila *, int n);
void enfileira(Fila *, int);
int desenfileira(Fila *);

struct s_fila {
    int inicio, fim, tamanho;
    int *item;
};

int main() {
    Fila fila;
    int n, chave;
    char operador;
    scanf("%d", &n);
    cria(&fila, n);
    while (scanf("\n%c", &operador) != EOF) {
        if (operador == 'E') {
            scanf("%d", &chave);
            enfileira(&fila, chave);
        } else if (operador == 'D') {
            chave = desenfileira(&fila);
            if (chave != -1) {
                printf("%d\n", fila.item[chave]);
            } else {
                printf("Runtime Error: Fila Vazia.\n");
            }
        }
    }
    return 0;
}

void cria (Fila *fila, int n) {
    fila -> item = (int *)malloc(n * sizeof(int));
    fila -> inicio = -1;
    fila -> fim = -1;
    fila -> tamanho = n;
}

void enfileira(Fila *fila, int chave) {
    if (fila -> fim < fila -> tamanho - 1) {
        fila -> fim++;
        fila -> item[fila -> fim] = chave;
        if (fila -> inicio == -1) {
            fila -> inicio++;
        }
    } else {
        printf("Runtime Error: Fila Cheia.\n");
    }
}
int desenfileira(Fila *fila) {
    /*int aux = 0;
    if (fila -> inicio > -1) {
        aux = fila -> item[fila -> inicio];
        fila -> inicio++;
        if (fila -> inicio > fila -> fim) {
            fila -> inicio = -1;
            fila -> fim = -1;
        }
    }*/
    int aux = fila -> inicio;
    if (aux > -1) {
        if (aux == fila -> fim) {
            fila -> inicio = -1;
            fila -> fim = -1;
        } else {
            fila -> inicio++;
        }
    }
    return aux;
}
