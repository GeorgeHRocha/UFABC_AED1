#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void construirMaxHeap (int *, int);
void descer (int *, int, int);
void mostrar(int *, int);

int main() {
    int n, *v;
    v = (int *)malloc(sizeof(int));
    scanf("%d", &n);
    while (n != 0) {
        v = (int *)realloc(v, n * sizeof(int));
        lerVetor(v, n);
        construirMaxHeap(v, n);
        mostrar(v, n);
        scanf("%d", &n);
    }
    return 0;
}

void lerVetor(int *v, int n) {
    int i = 0;
    while (i < n) {
        scanf("%d", &v[i]);
        i++;
    }
}

void construirMaxHeap (int *v, int n) {
    int i = (n / 2) - 1;
    while (i >= 0) {
        descer(v, n, i);
        i--;
    }
}

void descer(int *v, int n, int i) {
    int esq, dir, maior, aux;
    esq = (2 * i) + 1;
    dir = (2 * i) + 2;
    if (dir < n && v[dir] > v[i]) {
        maior = dir;
    } else {
        maior = i;
    }
    if (esq < n && v[esq] > v[maior]) {
        maior = esq;
    }
    if (maior != i) {
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        descer(v, n, maior);
    }
}

void mostrar(int *v, int n) {
    int i = 0;
    while (i < n) {
        printf("%d%s", v[i], i + 1 < n ? " " : "\n");
        i++;
    }
}