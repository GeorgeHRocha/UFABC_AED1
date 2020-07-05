#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
int busca(int *, int, int);
int particiona(int *, int, int);
void mostrar(int *, int);

int main () {
    int n, x, *v;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    lerVetor(v, n);
    scanf("%d", &x);
    printf("%d\n", particiona(v, busca(v, n, x), n - 1));
    return 0;
}

void lerVetor(int *v, int n) {
    int i = 0;
    while (i < n) {
        scanf("%d", &v[i]);
        i++;
    }
}

int busca (int *v, int n, int valor) {
    int i = 0;
    while (i < n) {
        if (v[i] == valor) {
            return i;
        }
        i++;
    }
    return -1;
}

int particiona(int *v, int pivo, int fim) {
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
    return i;
}
