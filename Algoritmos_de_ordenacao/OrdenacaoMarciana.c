#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void lerVetor(int *, int);
void ordenar (int *, int);
int converte (int);
void mostrar (int *, int);

int main () {
    int n, *v;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    lerVetor(v, n);
    ordenar(v, n);
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

void ordenar(int *v, int n) {
    int i = 1, j, aux;
    while (i < n) {
        aux = v[i];
        j = i;
        while (j > 0 && converte(aux) < converte(v[j - 1])) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
        i++;
    }
}

int converte (int a) {
    char c[10], aux[] = /*"0564897312"*/"0897312645";
    int i = 0;
    sprintf(c, "%i", a);
    while (i < strlen(c)) {
        c[i] = aux[c[i] - '0'];
        i++;
    }
    return atoi(c);
}

void mostrar(int *v, int n) {
    int i = 0;
    while (i < n) {
        printf("%d%s", v[i], i + 1 < n ? " " : "\n");
        i++;
    }
}