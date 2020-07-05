#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void intercala (int *, int, int, int);
void mostrar (int *, int);

int main () {
    int q1, q2, *v;
    scanf("%d %d", &q1, &q2);
    v = (int *)malloc((q1 + q2) * sizeof(int));
    lerVetor(v, q1 + q2);
    intercala(v, 0, q1 - 1, q1 + q2 - 1);
    mostrar(v, q1 + q2);
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

void mostrar(int *v, int n) {
    int i = 0;
    while (i < n) {
        printf("%d\n", v[i]);
        i++;
    }
}
