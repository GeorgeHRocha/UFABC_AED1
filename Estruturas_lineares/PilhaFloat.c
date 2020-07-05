#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct t_pilha Pilha;
struct t_pilha {
  int tamanho, topo;
  float *item;
};

void cria (Pilha *, int);
void empilha (Pilha *, float);
void desempilha (Pilha *);
void topo (Pilha);
void mostra (Pilha);
void rMostra (Pilha);

int main () {
  Pilha pilha;
  char operador;
  int n;
  float chave;
  scanf("%d", &n);
  cria(&pilha, n);
  while (scanf("\n%c", &operador) != EOF) {
    if (operador == 'E') {
      scanf("%f", &chave);
      empilha(&pilha, chave);
    } else if (operador == 'D') {
      desempilha(&pilha);
    } else if (operador == 'T') {
      topo(pilha);
    } else if (operador == 'X') {
      mostra(pilha);
    } else if (operador == 'B') {
      rMostra(pilha);
    }
  }
  return 0;
}

void cria (Pilha *pilha, int n) {
  pilha -> item = (float *) malloc (n * sizeof(float));
  pilha -> topo = -1;
  pilha -> tamanho = n;
}

void empilha (Pilha * pilha, float chave) {
  if (pilha -> topo < pilha -> tamanho - 1) {
    pilha -> topo++;
    pilha -> item[pilha -> topo] = chave;
  }
}
void desempilha (Pilha * pilha) {
  if (pilha -> topo > -1) {
    pilha -> topo --;
  }
}

void topo (Pilha pilha) {
  if (pilha.topo > -1) {
     if (fmod(pilha.item[pilha.topo], 1) == 0) {
        printf("%.0f\n", pilha.item[pilha.topo]);
     } else {
        printf("%.1f\n", pilha.item[pilha.topo]);
     }
  }
}

void mostra (Pilha pilha) {
  int i = pilha.topo;
  if (i > -1) {
      while (i >= 0) {
        if (fmod(pilha.item[i], 1) == 0) {
          printf("%.0f%s", pilha.item[i], i > 0 ? " " : "\n");
        } else {
          printf("%.1f%s", pilha.item[i], i > 0 ? " " : "\n");
        }
        i--;
      }
  }
}

void rMostra (Pilha pilha) {
  int i = 0;
  if (pilha.topo > -1) {
    while (i <= pilha.topo) {
     if (fmod(pilha.item[i], 1) == 0) {
        printf("%.0f%s", pilha.item[i], i < pilha.topo ? " " : "\n");
      } else {
        printf("%.1f%s", pilha.item[i], i < pilha.topo ? " " : "\n");
      }
      i++;
    }
  }
}