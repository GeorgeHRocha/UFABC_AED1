#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void mostrar (int *, int);

int main () {
    int n, *v, i = 0, j, quant = 0, aux, iMenor;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    lerVetor(v, n);
    mostrar(v, n);
    while (i < n - 1) {
        iMenor = i;
        j = i + 1;
        while (j < n) {
            if (v[j] < v[iMenor]) {
                iMenor = j;
                quant++;
            }
            j++;
        }
        if (i != iMenor) {
            aux = v[i];
            v[i] = v[iMenor];
            v[iMenor] = aux;
        }
        mostrar(v, n);
        i++;
    }
    mostrar(v, n);
    printf("%d\n", quant);
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
