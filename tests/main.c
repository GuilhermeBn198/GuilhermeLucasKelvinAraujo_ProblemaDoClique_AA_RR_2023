#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval t1, t2;
double elapsedTime;

/*para o calculo do tempo*/
unsigned long time_diff(struct timeval a, struct timeval b) {
  struct timeval res;
  timersub(&a, &b, &res);
  return res.tv_sec * 1000000 + res.tv_usec;
}

void FazAlgo(int n) {
  int i, j, k;
  int controle = 0;
  for (i = 1; i < n - 1; i++) {
    for (j = i + 1; j <= n; j++) {
      for (k = 1; k <= j; k++) {
        controle++;
      }
    }
  }
}

void FazAlgov2(int n) {
  int i, j, k;
  int controle = 0;
  for (i = 1; i < n - 1; i++) {
    for (j = i + 1; j <= n; j++) {
      controle++;
      controle = controle + (j - 1);
    }
  }
}

int main(int argc, char **argv) {
  FILE *fp;
  int num, count = 0;
  int *lista = NULL;

  if (argc != 2) {
    printf("Uso: %s <arquivo>\n", argv[0]);
    exit(0);
  }
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo.\n");
    exit(1);
  }

  while (fscanf(fp, "%d", &num) == 1) {  // lê todos os elementos do arquivo
    count++;                             // conta quantos elementos foram lidos
  }
  int n = count;
  printf("QUANTIDADE DE ITEMS: %d", n);  // número total de entradas do arquivo
  fclose(fp);

  gettimeofday(&t1, NULL);
  FazAlgov2(n);
  gettimeofday(&t2, NULL);

  printf("\n Tempo de Execucao: ---> %lf \n", time_diff(t2, t1) / 1000000.0);

  return 0;
}
