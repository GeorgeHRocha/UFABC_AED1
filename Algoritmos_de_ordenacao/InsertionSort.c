#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void mostrar (int *, int);

int main () {
    int n, *v, i = 1, j, aux;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    lerVetor(v, n);
     while (i < n) {
        aux = v[i];
        j = i;
        while (j > 0 && aux < v[j - 1]) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
        mostrar(v, n);
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

void mostrar(int *v, int n) {
    int i = 0;
    while (i < n) {
        printf("%d%s", v[i], i + 1 < n ? " " : "\n");
        i++;
    }
}