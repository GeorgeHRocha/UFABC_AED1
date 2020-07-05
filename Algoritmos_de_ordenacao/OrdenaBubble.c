#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void mostrar (int *, int);

int main () {
    int n, *v, i = 1, j = 0, aux, trocas = 0;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    lerVetor(v, n);
    mostrar(v, n);
    while (i < n) {
        while (j < n - i) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                mostrar(v, n);
                trocas++;
            }
            j++;
        }
        i++;
        j = 0;
    }
    mostrar(v, n);
    printf("Trocas: %d\n", trocas);
    return 0;
}

void lerVetor(int *v, int n) {
    int i = 0;
    while (i < n) {
        scanf("%d", &v[i]);
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
