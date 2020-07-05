#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void quickSort(int *, int, int, int);
void mostrar(int *, int);

int main () {
    int n, *v;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    lerVetor(v, n);
    mostrar(v, n);
    quickSort(v, 0, n - 1, n);
    mostrar(v, n);
    return 0;
}

void lerVetor(int *v, int n) {
    int i = 0;
    while (i < n) {
        scanf("%d", &v[i]);
        i++;
    }
}

void quickSort(int *v, int inicio, int fim, int n) {
    if (inicio < fim) {
        int i = inicio, j = inicio, aux;
        while (j < fim) {
            if (v[j] <= v[fim]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
            }
            mostrar(v, n);
            j++;
        }
        aux = v[i];
        v[i] = v[fim];
        v[fim] = aux;
        mostrar(v, n);
        quickSort(v, inicio, i - 1, n);
        quickSort(v, i + 1, fim, n);
    }
}

void mostrar(int *v, int n) {
    int i = 0;
    while (i < n) {
        printf("%d%s", v[i], i + 1 < n ? " " : "\n");
        i++;
    }
}
