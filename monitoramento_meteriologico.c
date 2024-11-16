#include "tempo.h"
#include <stdio.h>

int main() {
  Tempo tempo;
  int i;
  FILE *log;
  log = fopen("registro.txt", "w");
  // Inicializa o gerador de números aleatórios
  srand(time(NULL));
  do {
    printf("Escolha uma cidade:\n");
    printf("Porto Alegre(1), Caxias do Sul(2), Pelotas(3), Santa Maria(4)\n");
    scanf(" %d", &i);
  } while (!definirCidade(&tempo, i));

  do {
    printf("Digite um mês do ano de 2024 (1 a 12):\n");
    scanf(" %d", &tempo.mes);
  } while (!validarData(&tempo));

  fprintf(log, "*** REGISTRO METERIOLÓGICO DO MÊS %d DE 2024 EM %s ***\n\n",
          tempo.mes, tempo.cidade);
  for (i = 0; i <= tempo.dias; i++) {
    fprintf(log, "Dia %d: %s\n", i, gerarClima());
  }
  fclose(log);
}