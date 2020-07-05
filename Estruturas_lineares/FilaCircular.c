#include <stdio.h>
#include <stdlib.h>

typedef struct s_fila Fila;

struct s_fila {
    int inicio, fim, tamanho;
    int *item;
};

void cria (Fila *, int n);
void enfileira(Fila *, int);
int desenfileira(Fila *);

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
            }
        }
    }
    return 0;
}

void cria (Fila *fila, int n) {
    fila -> item = (int *)malloc(n * sizeof(int));
    fila -> inicio = 0;
    fila -> fim = 0;
    fila -> tamanho = n;
}

void enfileira(Fila *fila, int chave) {
    int novo_fim = (fila -> fim + 1) % fila -> tamanho;
    if (novo_fim != fila -> inicio) {
        fila -> item[fila -> fim] = chave;
        fila -> fim = novo_fim;
    }
}
int desenfileira(Fila *fila) {
    int antigo_inicio;
    if (fila -> inicio != fila -> fim) {
        antigo_inicio = fila -> inicio;
        fila -> inicio = (fila -> inicio + 1) % fila -> tamanho;
        return antigo_inicio;
    }
    return -1;
}
