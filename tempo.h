#ifndef TEMPO_H
#define TEMPO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int dias;
  int mes;
  char cidade[50];
} Tempo;

static int definirCidade(Tempo *tempo, int i) {
  switch (i) {
  case 1:
    strcpy(tempo->cidade, "PORTO ALEGRE");
    break;
  case 2:
    strcpy(tempo->cidade, "CAXIAS DO SUL");
    break;
  case 3:
    strcpy(tempo->cidade, "PELOTAS");
    break;
  case 4:
    strcpy(tempo->cidade, "SANTA MARIA");
    break;
  default:
    return 0;
  }
  return 1;
}

static int validarData(Tempo *tempo) {
  bool tp_mes; // 0 para mês com 30 dias e 1 para mês com 31 dias.

  // Verificar mês.
  if (tempo->mes < 1 || tempo->mes > 12)
    return 0;

  // Atribuir se o mês tem 30 ou 31 dias.
  if ((tempo->mes <= 7 && tempo->mes % 2) ||
      (tempo->mes > 7 && !(tempo->mes % 2))) {
    tp_mes = 1;
  } else
    tp_mes = 0;

  // Definir dias.
  if (tp_mes == 1)
    tempo->dias = 31;
  if (tp_mes == 0)
    tempo->dias = 30;
  if (tempo->mes == 2) // Fevereiro.
    tempo->dias = 29;

  return 1;
}

static const char *gerarClima() {
  const char *tp_clima[] = {"Ensolarado",    "Nublado",
                            "Chuva leve",    "Chuva moderada",
                            "Chuva intensa", "Chuva intensa + tempestade",
                            "Instável"};
  int totalClimas = /* Calcula o número de tipos de clima no array*/
      sizeof(tp_clima) / sizeof(tp_clima[0]);

  // Seleciona uma palavra aleatória
  int indiceAleatorio = rand() % totalClimas;
  return tp_clima[indiceAleatorio];
}

#endif