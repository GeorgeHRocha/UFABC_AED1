#include <stdio.h>
#include <stdlib.h>

typedef struct s_no No;
typedef struct s_arvore Arvore;

struct s_no {
    int dado;
    No *dir, *esq;
};
struct s_arvore {
    No *raiz;
};

void lerArvore(Arvore *, int);
No *criaNo(int);
Arvore *criaArvore();
void inserir(Arvore *, No *);
void mostraFolhas(No *);

int main() {
    Arvore *arvore = criaArvore();
    int n;
    scanf("%d", &n);
    lerArvore(arvore, n);
    mostraFolhas(arvore -> raiz);
    return 0;
}

void lerArvore(Arvore *arvore, int n) {
    int i = 0, chave;
    while (i < n) {
        scanf("%d", &chave);
        inserir(arvore, criaNo(chave));
        i++;
    }
}

No *criaNo(int dado) {
    No *no = (No *)malloc(sizeof(No));
    if (no != NULL) {
        no -> dado = dado;
        no -> esq = NULL;
        no -> dir = NULL;
    }
    return no;
}

Arvore *criaArvore() {
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    if (arvore != NULL) {
        arvore -> raiz = NULL;
    }
    return arvore;
}

void inserir(Arvore *arvore, No *no) {
    No *anterior = NULL, *atual = arvore -> raiz;
    while (atual != NULL) {
        anterior = atual;
        if (no -> dado < atual -> dado) {
            atual = atual -> esq;
        } else if (no -> dado > atual -> dado) {
            atual = atual -> dir;
        } else {
            free(no);
            return;
        }
    }
    if (anterior != NULL) {
        if (no -> dado < anterior -> dado ) {
            anterior -> esq = no;
        } else {
            anterior -> dir = no;
        }
    } else {
        arvore -> raiz = no;
    }
}
void mostraFolhas(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    mostraFolhas(raiz -> esq);
    if (raiz -> esq == NULL && raiz -> dir == NULL) {
        printf("%d\n", raiz -> dado);
    }
    mostraFolhas(raiz -> dir);
}
