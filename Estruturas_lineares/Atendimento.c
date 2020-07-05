#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_aluno Aluno;
typedef struct s_fila Fila;

struct s_aluno{
    char *nome;
    int ra;
};

struct s_fila {
    Aluno *alunos;
    int inicio, fim, tamanho, quantidade;
};

void criaAluno(Aluno *);
void criaFila(Fila *, int);
void inclui(Fila *, int, char[50]);
int elimina(Fila *);
void mostra(Fila);
void rMostra (Fila);
int quantidade(Fila);

int main() {
    Fila fila;
    int n, ra, chave;
    char operador, nome[50];
    scanf("%d", &n);
    criaFila(&fila, n);
    while (scanf("\n%c", &operador) != EOF) {
        if (operador == 'I') {
            scanf("%d %s", &ra, nome);
            inclui(&fila, ra, nome);
        } else if (operador == 'A') {
            chave = elimina(&fila);
            if (chave != -1) {
                printf("[%d] %s\n", fila.alunos[chave].ra, fila.alunos[chave].nome);
            }
        } else if (operador == 'M') {
            mostra(fila);
        } else if (operador == 'R') {
            rMostra(fila);
        } else if (operador == 'Q') {
            printf("Quantidade: %d\n", quantidade(fila));
        }
    }
    return 0;
}

void criaAluno(Aluno *aluno) {
    aluno -> nome = (char*)malloc(50*sizeof(char));
}

void criaFila(Fila *fila, int n) {
    fila -> alunos = (Aluno*)malloc(n * sizeof(Aluno));
    int i = 0;
    while (i < n) {
        criaAluno(&fila -> alunos[i]);
        i++;
    }
    fila -> inicio = -1;
    fila -> fim = -1;
    fila -> quantidade = 0;
    fila -> tamanho = n;
}

void inclui(Fila *fila, int ra, char nome [50]) {
    if (fila -> fim < fila -> tamanho - 1) {
        fila -> fim++;
        fila -> alunos[fila ->fim].ra= ra;
        strcpy(fila -> alunos[fila -> fim].nome, nome);
        if (fila -> inicio == -1) {
            fila -> inicio++;
        }
    }
}

int elimina(Fila *fila) {
    int aux = fila -> inicio;
    if (aux > -1) {
        if (aux == fila -> fim) {
            fila -> inicio = -1;
            fila -> fim = -1;
        } else {
            fila -> inicio++;
        }
    }
    return aux;
}

void mostra(Fila fila) {
    int i = fila.inicio;
    if (i > -1) {
      while (i <= fila.fim) {
          printf("[%d] %s\n", fila.alunos[i].ra, fila.alunos[i].nome);
          i++;
      }
    }
}

void rMostra (Fila fila) {
    int i = fila.fim;
    if (i > -1) {
      while (i >= fila.inicio) {
          printf("[%d] %s\n", fila.alunos[i].ra, fila.alunos[i].nome);
          i--;
      }
    }
}

int quantidade(Fila fila) {
    if (fila.fim == -1) {
        return 0;
    }
    return fila.fim - fila.inicio + 1;
}