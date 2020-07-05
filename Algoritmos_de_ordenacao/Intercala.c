#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *, int);
int * intercala (int *, int *, int, int);
void mostrar (int *, int);

int main () {
    int q1, q2, *v1, *v2  ,*vr;
    scanf("%d %d", &q1, &q2);
    v1 = (int *)malloc(q1 * sizeof(int));
    v2 = (int *)malloc(q2 * sizeof(int));
    lerVetor(v1, q1);
    lerVetor(v2, q2);
    mostrar(intercala(v1, v2, q1, q2), q1 + q2);
    return 0;
}

void lerVetor(int *v, int n) {
    int i = 0;
    while (i < n) {
        scanf("%d", &v[i]);
        i++;
    }
}

int * intercala (int *v1, int *v2, int q1, int q2) {
    int i = 0, j = 0, k = 0, *vr;
    vr = (int *)malloc((q1 + q2) * sizeof(int));
    while (i < q1 && j < q2) {
        if (v1[i] < v2[j]) {
            vr[k] = v1[i];
            i++;
        } else {
            vr[k] = v2[j];
            j++;
        }
        k++;
    }
    while (i < q1) {
        vr[k] = v1[i];
        i++;
        k++;
    }
    while (j < q2) {
        vr[k] = v2[j];
        j++;
        k++;
    }
    return vr;
}

void mostrar(int *v, int n) {
    int i = 0;
    while (i < n) {
        printf("%d\n", v[i]);
        i++;
    }
}
