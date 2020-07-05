#include <stdio.h>
#include <stdlib.h>

typedef struct s_lista Lista;
struct s_lista {
    float * num,  * den;
    int quantidade, tamanho;
};

void insere (Lista *, float, float);
void cria (Lista *, int);
void exclui (Lista *, float, float);
int busca (Lista *, float, float);
void imprime(Lista *);

int main () {
    Lista lista;
    int n, i = 0;
    char operador;
    float chaveNum, chaveDen;
    scanf("%d", &n);
    cria(&lista, n);
    while (scanf("\n%c", &operador) != EOF) {
        if (operador == 'I') {
            scanf("%f %f", &chaveNum, &chaveDen);
            insere(&lista, chaveNum, chaveDen);
        } else if (operador == 'R') {
            scanf("%f %f", &chaveNum, &chaveDen);
            exclui(&lista, chaveNum, chaveDen);
        } else if (operador == 'B') {
            scanf("%f %f", &chaveNum, &chaveDen);
            if (busca(&lista, chaveNum, chaveDen)) {
                printf("SIM\n");
            } else {
                printf("NAO\n");
            }
        } else if (operador == 'M') {
            imprime (&lista);
        }
    }
    return 0;
}

void cria (Lista *lista, int n) {
    lista -> num = (float *)malloc(n * sizeof(float));
    lista -> den = (float *)malloc(n * sizeof(float));
    lista -> quantidade = 0;
    lista -> tamanho = n;
}

int busca (Lista *lista, float chaveNum, float chaveDen) {
    int esquerda, direita, meio;
    esquerda = 0;
    direita = lista -> quantidade - 1;
    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (lista -> num[meio] / lista -> den[meio]  == chaveNum / chaveDen) {
            return 1;
        }
        if (lista -> num[meio] / lista -> den[meio] > chaveNum / chaveDen) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return 0;
}

void insere (Lista *lista, float chaveNum, float chaveDen) {
    int i = 0, j;
    if (lista -> quantidade < lista -> tamanho) {
        while (i < lista -> quantidade && chaveNum / chaveDen > lista -> num[i] / lista -> den[i]) {
            i++;
        }
        if (i < lista -> quantidade && chaveNum / chaveDen  == lista -> num[i] / lista -> den[i]) {
            return;
        }
        j = lista -> quantidade;
        while (j > i) {
            lista -> num[j] = lista -> num[j - 1];
            lista -> den[j] = lista -> den[j - 1];
            j--;
        }
        lista -> num[i] = chaveNum;
        lista -> den[i] = chaveDen;
        lista -> quantidade++;
    }
}

void exclui (Lista *lista, float chaveNum, float chaveDen) {
    int i = 0, j;
    while (i < lista -> quantidade && chaveNum / chaveDen != lista -> num[i] / lista -> den[i]) {
        i++;
    }
    j = i + 1;
    while (j < lista -> quantidade) {
        lista -> num[j - 1] = lista -> num[j];
        lista -> den[j - 1] = lista -> den[j];
        j++;
    }
    if (i < lista -> quantidade) {
        lista -> quantidade--;
    }
}

void imprime (Lista *lista) {
    int i = 0;
    while (i < lista -> quantidade - 1) {
        printf("%d/%d ", (int)(lista -> num[i]), (int)(lista -> den[i]));
        i++;
    }
    if (lista -> quantidade > 0) {
        printf("%d/%d\n", (int)(lista -> num[i]), (int)(lista -> den[i]));
    }
}
