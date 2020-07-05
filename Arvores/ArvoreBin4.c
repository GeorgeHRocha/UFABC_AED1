#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_no No;
typedef struct s_arvore Arvore;

struct s_no {
    char dado[50];
    int num;
    No *dir, *esq;
};
struct s_arvore {
    No *raiz;
};

No *criaNo(char[]);
Arvore *criaArvore();
void inserir(Arvore *, No *);
No *remover(Arvore *, char[]);
int converteDadoNum(char[]);
void preOrdem(Arvore *, No *);
void emOrdem(Arvore *, No *);
void posOrdem(Arvore *, No *);

int main() {
	char operador[11];
	char chave[50];
	Arvore *arvore = criaArvore();
	No *removido;
	while (scanf("%s", operador) != EOF) {
		if (strcmp(operador, "insert") == 0) {
			scanf("%s", chave);
			inserir(arvore, criaNo(chave));
		} else if (strcmp(operador, "delete") == 0) {
			scanf("%s", chave);
			removido = remover(arvore, chave);
		} else if (strcmp(operador, "pre-order") == 0) {
			preOrdem(arvore, arvore -> raiz);
		} else if (strcmp(operador, "in-order") == 0) {
			emOrdem(arvore, arvore -> raiz);
		} else if (strcmp(operador, "post-order") == 0) {
			posOrdem(arvore, arvore -> raiz);
		}
	}
    return 0;
}

No *criaNo(char dado[]) {
    No *no = (No *)malloc(sizeof(No));
    if (no != NULL) {
        strcpy(no -> dado, dado);
        no -> num = converteDadoNum(dado);
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
        if (no -> num < atual -> num) {
            atual = atual -> esq;
        } else {
            atual = atual -> dir;
        }
    }
    if (anterior != NULL) {
        if (no -> num < anterior -> num ) {
            anterior -> esq = no;
        } else {
            anterior -> dir = no;
        }
    } else {
        arvore -> raiz = no;
    }
}

No *remover(Arvore *arvore, char dado[]) {
    int num = converteDadoNum(dado);
	No *anterior = NULL, *atual = arvore -> raiz, *anterior2, *atual2;
    while (atual != NULL && atual -> num != num) {
        anterior = atual;
        if (num < atual -> num) {
            atual = atual -> esq;
        } else {
            atual = atual -> dir;
        }
    }
    if (atual != NULL) {
        if (anterior == NULL) {
            if (atual -> esq == NULL) {
                arvore -> raiz = atual -> dir;
            } else if (atual -> dir == NULL) {
                arvore -> raiz = atual -> esq;
            } else {
                anterior2 = atual;
                atual2 = atual -> dir;
                while(atual2 -> esq != NULL) {
                    anterior2 = atual2;
                    atual2 = atual2 -> esq;
                }
                if (anterior2 != atual) {
                    anterior2 -> esq = atual2 -> dir;
                    atual2 -> dir = atual -> dir;
                }
                atual2 -> esq = atual -> esq;
                arvore -> raiz = atual2;
            }
        } else {
            if (atual -> esq == NULL) {
                if (anterior -> esq == atual) {
                    anterior -> esq = atual -> dir;
                } else {
                    anterior -> dir = atual -> dir;
                }
            } else if (atual -> dir == NULL) {
                if (anterior -> esq == atual) {
                    anterior -> esq = atual -> esq;
                } else {
                    anterior -> dir = atual -> esq;
                }
            } else {
                anterior2 = atual;
                atual2 = atual -> dir;
                while(atual2 -> esq != NULL) {
                    anterior2 = atual2;
                    atual2 = atual2 -> esq;
                }
                if (anterior2 != atual) {
                    anterior2 -> esq = atual2 -> dir;
                    atual2 -> dir = atual -> dir;
                }
                atual2 -> esq = atual -> esq;
                if (anterior -> esq == atual) {
                    anterior -> esq = atual2;
                } else {
                    anterior -> dir = atual2;
                }
            }
        }
        atual -> esq = NULL;
        atual -> dir = NULL;
    }
    return atual;
}

int converteDadoNum(char dado []) {
    int i = 0, num = 0;
    while (i < strlen(dado)) {
        num += (int)dado[i];
        i++;
    }
    return num;
}

void preOrdem(Arvore *arvore, No *raiz) {
    if (raiz != NULL) {
        printf("[%d]:%s\n", raiz -> num, raiz -> dado);
        preOrdem(arvore, raiz -> esq);
        preOrdem(arvore, raiz -> dir);
        if (arvore -> raiz == raiz) {
            printf("\n");
        }
    }
}

void emOrdem(Arvore *arvore, No *raiz) {
    if (raiz!= NULL) {
        emOrdem(arvore, raiz -> esq);
        printf("[%d]:%s\n", raiz -> num, raiz -> dado);
        emOrdem(arvore, raiz -> dir);
        if (arvore -> raiz == raiz) {
            printf("\n");
        }
    }
}

void posOrdem(Arvore *arvore, No *raiz) {
    if (raiz != NULL) {
        posOrdem(arvore, raiz -> esq);
        posOrdem(arvore, raiz -> dir);
        printf("[%d]:%s\n", raiz -> num, raiz -> dado);
        if (arvore -> raiz == raiz) {
            printf("\n");
        }
    }
}
