#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void intercala (int *, int, int, int);
void mergeSort (int *, int, int, int);
void mostrar (int *, int);

int main () {
    int n, *v;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    lerVetor(v, n);
    mostrar(v, n);
    mergeSort(v, 0, n - 1, n);
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

void intercala (int *v, int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = inicio, *r;
    r = (int *)malloc((fim + 1) * sizeof(int));
    while (i <= meio && j <= fim) {
        if (v[i] < v[j]) {
            r[k] = v[i];
            i++;
        } else {
            r[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= meio) {
        r[k] = v[i];
        i++;
        k++;
    }
    while (j <= fim) {
        r[k] = v[j];
        j++;
        k++;
    }
    i = inicio;
    while (i <= fim) {
        v[i] = r[i];
        i++;
    }
    free(r);
}

void mergeSort(int *v, int inicio, int fim, int n) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio, n);
        mergeSort(v, meio + 1, fim, n);
        mostrar(v, n);
        intercala (v, inicio, meio, fim);
    }
}

void mostrar(int *v, int n) {
    int i = 0;
    while (i < n) {
        printf("%d%s", v[i], i + 1 < n ? " " : "\n");
        i++;
    }
}
