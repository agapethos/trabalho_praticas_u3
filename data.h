#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
  int dia;
  int mes;
  int ano;
  char cidade[50];
  char clima[30];
} Tempo;

static bool anoBissexto(int ano) {
  return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

static int validarTempo(Tempo tempo) {
  bool tp_mes; // 0 para mês com 30 dias e 1 para mês com 31 dias.

  // Verificar meses.
  if (tempo.mes < 1 || tempo.mes > 12)
    return 0;

  // Atribuir se o mês da data tem 30 ou 31 dias.
  if ((tempo.mes <= 7 && tempo.mes % 2) ||
      (tempo.mes > 7 && !(tempo.mes % 2))) {
    tp_mes = 1;
  } else
    tp_mes = 0;

  // Verificar dia no ano bissexto.
  if (anoBissexto(tempo.ano) && tempo.mes == 2 && (tempo.dia < 1 || tempo.dia > 29))
    return 0;

  // Verificar dias.
  if(!anoBissexto(tempo.ano) && tempo.mes == 2 && (tempo.dia < 1 || tempo.dia > 28)) // Fevereiro.
    return 0;
  if (tp_mes == 1 && (tempo.dia < 1 || tempo.dia > 31))
    return 0;
  if (tp_mes == 0 && (tempo.dia < 1 || tempo.dia > 30))
    return 0;

  return 1;
}

#endif