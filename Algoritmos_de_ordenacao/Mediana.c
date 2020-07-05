#include <stdio.h>
#include <stdlib.h>

void lerVetor(long *, int);
void ordenar(long *, int);
double mediana (long * , int);
int main() {
    int n;
    long *v;
    scanf("%d", &n);
    v = (long *)malloc(n * sizeof(long));
    lerVetor(v, n);
    printf("%.2lf\n", mediana(v, n));
    return 0;
}

void lerVetor(long *v, int n) {
    int i = 0;
    while (i < n) {
        scanf("%ld", &v[i]);
        i++;
    }
}

void ordenar (long *v, int n) {
     int i = 1, j = 0;
     long chave;
     while (i < n) {
        chave = v[i];
        while (j >= 0 && chave < v[j]) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
        i++;
        j = i - 1;
    }
}

double mediana (long *v, int n) {
    ordenar(v, n);
    double r;
    if (n % 2 != 0) {
        r = (double)v[n / 2];
    } else {
        r = (v[(n - 1) / 2] + v[n / 2]) / 2.0;
    }
    return r;
}
