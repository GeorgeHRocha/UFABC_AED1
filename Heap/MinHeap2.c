#include <stdio.h>
#include <stdlib.h>

typedef struct s_Heap Heap;

struct s_Heap {
    int *no, quantidade;
};

void criaHeap(Heap *);
void realocaHeap(Heap *, int);
void construirMinHeap(int *, int);
void descer(int *, int, int);
void inserir(Heap *, int);
void remover(Heap *, int);

int main() {
    int q, req, i = 0, v;
    Heap heap;
    criaHeap(&heap);
    scanf("%d", &q);
    while (i < q) {
        scanf("%d", &req);
        if (req == 3) {
            printf("%d\n", heap.no[0]);
        } else {
            scanf("%d", &v);
            if (req == 1) {
                realocaHeap(&heap, heap.quantidade + 1);
                inserir(&heap, v);
            } else if (req == 2) {
                remover(&heap, v);
            }
        }
        i++;
    }
    return 0;
}

void criaHeap(Heap *heap) {
    heap -> no = (int *)malloc(sizeof(int));
    heap -> quantidade = 0;
}

void realocaHeap(Heap *heap, int quantidade) {
    heap -> no = (int *)realloc(heap -> no, quantidade * sizeof(int));
}

void construirMinHeap(int *v, int n) {
    int i = (n / 2) - 1;
    while (i >= 0) {
        descer(v, n, i);
        i--;
    }
}

void descer(int *v, int n, int i) {
    int esq, dir, maior, aux;
    esq = (2 * i) + 1;
    dir = (2 * i) + 2;
    if (dir < n && v[dir] < v[i]) {
        maior = dir;
    } else {
        maior = i;
    }
    if (esq < n && v[esq] < v[maior]) {
        maior = esq;
    }
    if (maior != i) {
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        descer(v, n, maior);
    }
}

void inserir(Heap *heap, int v) {
    heap -> no[heap -> quantidade] = v;
    heap -> quantidade++;
    if (heap -> quantidade > 1 && v < heap -> no[(heap -> quantidade - 2) / 2]) {
        construirMinHeap(heap -> no, heap -> quantidade);
    }
}

void remover(Heap *heap, int v) {
    int aux, i = 0;
    while(i < heap -> quantidade) {
        if (heap -> no[i] == v) {
            if (i != heap -> quantidade - 1) {
                aux = heap -> no[i];
                heap -> no[i] = heap -> no[heap -> quantidade - 1];
                heap -> no[heap -> quantidade - 1] = aux;
                descer(heap -> no, heap -> quantidade, i);
            }
            heap -> quantidade--;
            realocaHeap(heap, heap -> quantidade);
            return;
        }
        i++;
    }
}
