#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_lista Les;
typedef struct s_fila Fila;
typedef struct t_pilha Pilha;
typedef struct s_fila Circular;
typedef struct s_estrutura Estrutura;

struct s_lista {
    int *item;
    int quantidade, tamanho;
};
struct s_fila {
    int inicio, fim, tamanho;
    int *item;
};
struct t_pilha {
  int tamanho, topo, *item;
};
struct s_estrutura {
    Les les;
    Fila fila;
    Pilha pilha;
    Circular circular;
    char nome[10];
};

Estrutura criaEstrutura (char[], int);
void criaLes(Les *, int);
void insereLes(Les *, int);
int removeLes(Les *, int);
void mostraLes(Les *);
void criaFila(Fila *, int);
void insereFila(Fila *, int);
int removeFila(Fila *);
void mostraFila(Fila *);
void criaPilha(Pilha *, int);
void inserePilha(Pilha *, int);
int removePilha(Pilha *);
void mostraPilha(Pilha *);
void criaCircular(Circular *, int);
void insereCircular(Circular *, int);
int removeCircular(Circular *);
void mostraCircular(Circular *);

int main () {
    int n, tamanho, i = 0, pos_ed, chave, removido;
    char nome [10], op;
    scanf("%d", &n);
    Estrutura *estrutura = (Estrutura *)malloc(n * sizeof(Estrutura));
    while (i < n) {
        scanf("%s %d", nome, &tamanho);
        estrutura[i] = criaEstrutura(nome, tamanho);
        i++;
    }
    while (scanf("%d %c", &pos_ed, &op) != EOF) {
        if (op == 'I') {
            scanf("%d", &chave);
            if (strcmp(estrutura[pos_ed].nome, "LES") == 0) {
                insereLes(&estrutura[pos_ed].les, chave);
            } else if (strcmp(estrutura[pos_ed].nome, "FILA") == 0) {
                insereFila(&estrutura[pos_ed].fila, chave);
            } else if (strcmp(estrutura[pos_ed].nome, "PILHA") == 0) {
                inserePilha(&estrutura[pos_ed].pilha, chave);
            } else if (strcmp(estrutura[pos_ed].nome, "CIRCULAR") == 0) {
                insereCircular(&estrutura[pos_ed].circular, chave);
            }
        } else if (op == 'R') {
            if (strcmp(estrutura[pos_ed].nome, "LES") == 0) {
                scanf("%d", &chave);
                removido = removeLes(&estrutura[pos_ed].les, chave);
            } else {
                if (strcmp(estrutura[pos_ed].nome, "FILA") == 0) {
                    removido = removeFila(&estrutura[pos_ed].fila);
                } else if (strcmp(estrutura[pos_ed].nome, "PILHA") == 0) {
                    removido = removePilha(&estrutura[pos_ed].pilha);
                } else if (strcmp(estrutura[pos_ed].nome, "CIRCULAR") == 0) {
                    removido = removeCircular(&estrutura[pos_ed].circular);
                }
            }
            if (removido != -1) {
                printf("REMOVIDO: %d\n", removido);
            }
        } else if (op == 'M') {
            if (strcmp(estrutura[pos_ed].nome, "LES") == 0) {
                mostraLes(&estrutura[pos_ed].les);
            } else if (strcmp(estrutura[pos_ed].nome, "FILA") == 0) {
                mostraFila(&estrutura[pos_ed].fila);
            } else if (strcmp(estrutura[pos_ed].nome, "PILHA") == 0) {
                mostraPilha(&estrutura[pos_ed].pilha);
            } else if (strcmp(estrutura[pos_ed].nome, "CIRCULAR") == 0) {
                mostraCircular(&estrutura[pos_ed].circular);
            }
        }
    }
    return 0;
}

Estrutura criaEstrutura (char nome[], int tamanho) {
    Estrutura estrutura;
    if (strcmp(nome, "LES") == 0) {
        criaLes(&estrutura.les, tamanho);
    } else if (strcmp(nome, "FILA") == 0) {
        criaFila(&estrutura.fila, tamanho);
    } else if (strcmp(nome, "PILHA") == 0) {
        criaPilha(&estrutura.pilha, tamanho);
    } else if (strcmp(nome, "CIRCULAR") == 0) {
        criaCircular(&estrutura.circular, tamanho);
    }
    strcpy(estrutura.nome, nome);
    return estrutura;
}

void criaLes(Les *les, int n) {
    les -> item = (int *)malloc(n * sizeof(int));
    les -> quantidade = 0;
    les -> tamanho = n;
}

void insereLes(Les *les, int chave) {
    int i = 0, j;
    if (les -> quantidade < les -> tamanho) {
        while (i < les -> quantidade && chave > les -> item[i]) {
            i++;
        }
        if (i < les -> quantidade && chave  == les -> item[i]) {
            return;
        }
        j = les -> quantidade;
        while (j > i) {
            les -> item[j] = les -> item[j - 1];
            j--;
        }
        les -> item[i] = chave;
        les -> quantidade++;
    }
}

int removeLes(Les *les, int chave) {
    int i = 0, j, removido;
    while (i < les -> quantidade && chave != les -> item[i]) {
        i++;
    }
    j = i + 1;
    if (i == les -> quantidade) {
        return -1;
    }
    removido = les -> item[i];
    while (j < les -> quantidade) {
        les -> item[j - 1] = les -> item[j];
        j++;
    }
    if (i < les -> quantidade) {
        les -> quantidade--;
    }
    return removido;
}

void mostraLes(Les *les) {
    int i = 0;
    while (i < les -> quantidade) {
        printf("%d%s", les -> item[i], i < les -> quantidade - 1 ? " " : "\n");
        i++;
    }
}

void criaFila(Fila *fila, int n) {
    fila -> item = (int *)malloc(n * sizeof(int));
    fila -> inicio = -1;
    fila -> fim = -1;
    fila -> tamanho = n;
}

void insereFila(Fila *fila, int chave) {
    if (fila -> fim < fila -> tamanho - 1) {
        fila -> fim++;
        fila -> item[fila ->fim] = chave;
        if (fila -> inicio == -1) {
            fila -> inicio++;
        }
    }
}

int removeFila(Fila *fila) {
    int removido = fila -> inicio;
    if (removido > -1) {
        if (removido == fila -> fim) {
            fila -> inicio = -1;
            fila -> fim = -1;
        } else {
            fila -> inicio++;
        }
        return fila -> item[removido];
    }
    return -1;
}

void mostraFila(Fila *fila) {
    int i = fila -> inicio;
    if (fila -> inicio > -1) {
        while (i <= fila -> fim) {
            printf("%d%s", fila -> item[i], i < fila -> fim ? " " : "\n");
            i++;
        }
    }
}

void criaPilha(Pilha *pilha, int n) {
    pilha -> item = (int *) malloc (n * sizeof(int));
    pilha -> topo = -1;
    pilha -> tamanho = n;
}

void inserePilha(Pilha *pilha, int chave) {
    if (pilha -> topo < pilha -> tamanho - 1) {
        pilha -> topo++;
        pilha -> item[pilha -> topo] = chave;
    }
}

int removePilha(Pilha *pilha) {
    int removido = pilha -> topo;
    if (pilha -> topo > -1) {
        pilha -> topo --;
        return pilha -> item[removido];
    }
    return -1;
}

void mostraPilha(Pilha *pilha) {
    int i = 0;
    if (pilha -> topo > -1) {
        while (i <= pilha -> topo) {
            printf("%d%s", pilha -> item[i], i < pilha -> topo ? " " : "\n");
            i++;
        }
    }
}

void criaCircular(Circular *circular, int n) {
    circular -> item = (int *)malloc(n * sizeof(int));
    circular -> inicio = 0;
    circular -> fim = 0;
    circular -> tamanho = n;
}

void insereCircular(Circular *circular, int chave) {
    int novo_fim = (circular -> fim + 1) % circular -> tamanho;
    if (novo_fim != circular -> inicio) {
        circular -> item[circular -> fim] = chave;
        circular -> fim = novo_fim;
    }
}

int removeCircular(Circular *circular) {
    int antigo_inicio;
    if (circular -> inicio != circular -> fim) {
        antigo_inicio = circular -> inicio;
        circular -> inicio = (circular -> inicio + 1) % circular -> tamanho;
        return circular -> item[antigo_inicio];
    }
    return -1;
}

void mostraCircular(Circular *circular) {
    int i = circular -> inicio;
    while (i != circular -> fim) {
        printf("%d", circular -> item[i]);
        i = (i + 1) % circular -> tamanho;
        printf("%s", i == circular -> fim ? "\n" : " ");
    }
}
