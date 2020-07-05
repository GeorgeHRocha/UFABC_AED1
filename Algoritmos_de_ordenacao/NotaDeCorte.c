#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
void quickSort(int *, int, int);
int media(int *, int);

int main () {
    int n, k, *v;
    scanf("%d %d", &n, &k);
    v = (int *)malloc(n * sizeof(int));
    lerVetor(v, n);
    quickSort(v, 0, n - 1);
    printf("%d\n", media(&v[n - k], k));
    return 0;
}

void lerVetor(int *v, int n) {
    int i = 0;
    while (i < n) {
        scanf("%d", &v[i]);
        i++;
    }
}

void quickSort(int *v, int inicio, int fim) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[(inicio + fim) / 2];
    while(esq <= dir) {
        while (v[esq] < pivo) {
            esq++;
        }
        while (v[dir] > pivo) {
            dir--;
        }
        if (esq <= dir) {
            aux  = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
            esq++;
            dir--;
       }
    }
   if (inicio < dir) {
       quickSort(v, inicio, dir);
   }
   if (esq < fim) {
       quickSort(v, esq, fim);
   }
}

int media(int * v, int n) {
    int i = 0, soma = 0;
    while (i < n) {
        soma = soma + v[i];
        i++;
    }
    return soma / n;
}
