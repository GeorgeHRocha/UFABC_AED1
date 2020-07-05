#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void ordenarInsertion(int *, int);
void mostrar (int *, int);

int main () {
    int n, *v, i = 1, *r;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    lerVetor(v, n);
    r = (int *)malloc(n * sizeof(int));
    i = 0;
    while (i < n) {
        r[i] = v[i];
        ordenarInsertion(r, i + 1);
        printf("Sublista Ordenada: ");
        mostrar(r, i + 1);
        printf("Sublista Desordenada:");
        if (i + 1 < n) {
            printf(" ");
            mostrar(&v[i + 1], n - i - 1);
        } else {
            printf("\n");
        }
        i++;
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

void ordenarInsertion(int *v, int n) {
    int i = 1, j, aux;
    while (i < n) {
        aux = v[i];
        j = i;
        while (j > 0 && aux < v[j - 1]) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
        i++;
    }
}

void mostrar(int *v, int n) {
    int i = 0;
    while (i < n) {
        printf("%d%s", v[i], i + 1 < n ? " " : "\n");
        i++;
    }
}