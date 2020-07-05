#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void particiona(int *, int, int);
void mostrar(int *, int);

int main () {
    int q, p, *v;
    scanf("%d %d", &q, &p);
    v = (int *)malloc(q * sizeof(int));
    lerVetor(v, q);
    particiona(v, p, q - 1);
    mostrar(v, q);
    return 0;
}

void lerVetor(int *v, int n) {
    int i = 0;
    while (i < n) {
        scanf("%d", &v[i]);
        i++;
    }
}

void particiona(int *v, int pivo, int fim) {
    int i = 0, j = 0, aux;
    aux = v[pivo];
    v[pivo] = v[fim];
    v[fim] = aux;
    while (j < fim) {
        if (v[j] <= v[fim]) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
        }
        j++;
    }
    aux = v[i];
    v[i] = v[fim];
    v[fim] = aux;
}

void mostrar(int *v, int n) {
    int i = 0;
    while (i < n) {
        printf("%d\n", v[i]);
        i++;
    }
}
