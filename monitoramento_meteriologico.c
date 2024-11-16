#include "data.h"
#include "tempo.h"


int anexarData(Tempo tempo) {
  printf("Digite o dia, mês e ano, respectivamente:\n");
  scanf(" %d %d %d", &tempo.dia, &tempo.mes,
        &tempo.ano);
  if(validarTempo(tempo) == 0) {
    printf("Data inválida.\n");
    return 0;
  }else 
    return 1;
}

int main() {
  Tempo tempo;
  int temp;
  do {
    temp = anexarData(tempo);
  }while (temp == 0);
  tempo.clima = definirClima();
}