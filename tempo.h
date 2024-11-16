#ifndef TEMPO_H
#define TEMPO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const char* definirClima() {
    const char *tp_clima[] = {"Ensolarado", "Nublado", "Chuva leve", "Chuva moderada", "Chuva intensa", "Chuva intensa + tempestade", "Instável"};
    int totalClimas = sizeof(tp_clima) / sizeof(tp_clima[0]); // Calcula o número de tp_clima no array

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Seleciona uma palavra aleatória
    int indiceAleatorio = rand() % totalClimas;
    return tp_clima[indiceAleatorio];
}

#endif