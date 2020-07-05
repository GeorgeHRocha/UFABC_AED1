#include <stdio.h>
#include <stdlib.h>

typedef struct t_pilha Pilha;
struct t_pilha {
  int tamanho, topo, *item;
};

void cria (Pilha *, int);
void empilha (Pilha *, int);
void desempilha (Pilha *);
void mostra (Pilha);
void rMostra (Pilha);

int main () {
  Pilha pilha;
  char operador;
  int n, chave;
  scanf("%d", &n);
  cria(&pilha, n);
  while (scanf("\n%c", &operador) != EOF) {
    if (operador == 'E') {
      scanf("%d", &chave);
      empilha(&pilha, chave);
    } else if (operador == 'D') {
      desempilha(&pilha);
    } else if (operador == 'T') {
      mostra(pilha);
    } else if (operador == 'B') {
      rMostra(pilha);
    }
  }
  return 0;
}

void cria (Pilha *pilha, int n) {
  pilha -> item = (int *) malloc (n * sizeof(int));
  pilha -> topo = -1;
  pilha -> tamanho = n;
}

void empilha (Pilha * pilha, int chave) {
  if (pilha -> topo < pilha -> tamanho - 1) {
    pilha -> topo++;
    pilha -> item[pilha -> topo] = chave;
  } else {
    printf("Runtime Error: Pilha Cheia.\n");
  }
}

void desempilha (Pilha * pilha) {
  if (pilha -> topo > -1) {
    pilha -> topo --;
  } else {
    printf("Runtime Error: Pilha Vazia.\n");
  }
}

void mostra (Pilha pilha) {
  int i = pilha.topo;
  if (i > -1) {
      while (i >= 0) {
        printf("%d\n", pilha.item[i]);
        i--;
      }
  } else {
    printf("Runtime Error: Pilha Vazia.\n");
  }
}

void rMostra (Pilha pilha) {
  int i = 0;
  if (pilha.topo > -1) {
    while (i <= pilha.topo) {
      printf("%d\n", pilha.item[i]);
      i++;
    }
  } else {
    printf("Runtime Error: Pilha Vazia.\n");
  }
}