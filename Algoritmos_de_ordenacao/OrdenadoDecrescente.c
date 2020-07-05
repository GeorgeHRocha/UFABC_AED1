#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
int ordenado(int *, int);

int main () {
    int n, *v;
    v = (int *)malloc(sizeof(int));
    while (scanf("%d", &n) != EOF) {
        v = (int *)realloc(v, n * sizeof(int));
        lerVetor(v, n);
        printf("%c\n", ordenado(v, n) ? 'S' : 'N');
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

int ordenado(int *v, int n) {
    int i = 0;
    while (i + 1 < n && v[i] >= v[i + 1]) {
        i++;
    }
    return i + 1 == n || n == 0;
}
