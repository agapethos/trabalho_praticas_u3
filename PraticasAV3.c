#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Estrutura para previsão do tempo
typedef struct
{
    int dias;
    int mes;
    char cidade[50];
} Tempo;

// Variáveis globais para armazenar os registros de previsões
Tempo tempos_registrados[48];
int i = 0;

static int definirCidade(Tempo *tempo, int opcao);
static int validarData(Tempo *tempo);
int verificar_previsao_tempo();
void doar_para_vitimas();
void enviar_mensagens();

int main()
{
    int escolha;

    do
    {
        printf("\n========== Menu Principal ==========\n");
        printf("1. Verificar a previsão do tempo\n");
        printf("2. Doar para vítimas das chuvas\n");
        printf("3. Enviar mensagens de apoio\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            verificar_previsao_tempo();
            break;
        case 2:
            doar_para_vitimas();
            break;
        case 3:
            enviar_mensagens();
            break;
        case 4:
            printf("\nSaindo do programa. Até logo!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}

// Função para definir a cidade
static int definirCidade(Tempo *tempo, int i)
{
    switch (i)
    {
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

// Função para validar o mês e o número de dias
static int validarData(Tempo *tempo)
{
    bool tp_mes; // 0 para mês com 30 dias e 1 para mês com 31 dias.

    // Verificar mês.
    if (tempo->mes < 1 || tempo->mes > 12)
        return 0;

    // Atribuir se o mês tem 30 ou 31 dias.
    if ((tempo->mes <= 7 && tempo->mes % 2) ||
        (tempo->mes > 7 && !(tempo->mes % 2)))
    {
        tp_mes = 1;
    }
    else
        tp_mes = 0;

    // Definir dias.
    if (tp_mes == 1)
        tempo->dias = 31;
    if (tp_mes == 0)
        tempo->dias = 30;
    if (tempo->mes == 2)  // Fevereiro
        tempo->dias = 29; // Ano fixo de 2024 (bissexto)

    return 1;
}

// Função para gerar um clima aleatório
static const char *gerarClima()
{
    const char *tp_clima[] = {"Ensolarado", "Nublado",
                              "Chuva leve", "Chuva moderada",
                              "Chuva intensa", "Chuva intensa + tempestade",
                              "Instável"};
    int totalClimas = sizeof(tp_clima) / sizeof(tp_clima[0]);

    // Seleciona uma palavra aleatória
    int indiceAleatorio = rand() % totalClimas;
    return tp_clima[indiceAleatorio];
}

// Função para verificar previsões e registrar
int verificar_previsao_tempo()
{
    Tempo tempo;
    int opc;
    FILE *log;
    log = fopen("registro.txt", "a"); // Alterado para 'a' (append) para adicionar no arquivo sem sobrescrever

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Loop principal para escolha da cidade
    do
    {
        printf("Escolha uma cidade:\n");
        printf("Porto Alegre(1), Caxias do Sul(2), Pelotas(3), Santa Maria(4)\n");
        scanf(" %d", &opc);
    } while (!definirCidade(&tempo, opc));

    // Entrada do mês
    do
    {
        printf("Digite um mês do ano de 2024 (1 a 12):\n");
        scanf(" %d", &tempo.mes);
        if (!validarData(&tempo))
        {
            printf("Mês inválido. Tente novamente.\n");
        }
    } while (!validarData(&tempo));

    // Verificação de registros
    for (int j = 0; j < i; j++)
    {
        if (strcmp(tempos_registrados[j].cidade, tempo.cidade) == 0 && tempos_registrados[j].mes == tempo.mes)
        {
            printf("Previsões do tempo já foram registradas para essa cidade e data.\n");
            fclose(log);
            return 0;
        }
    }

    // Adição ao arquivo
    tempos_registrados[i] = tempo;
    i++;
    fprintf(log, "*** REGISTRO METEOROLÓGICO DO MÊS %d DE 2024 EM %s ***\n\n",
            tempo.mes, tempo.cidade);
    for (int j = 1; j <= tempo.dias; j++)
    {
        fprintf(log, "Dia %d: %s\n", j, gerarClima());
    }
    printf("Previsões do tempo registradas no arquivo 'registro.txt'.\n");

    fclose(log);
    return 1;
}

// Função para doar para as vítimas
void doar_para_vitimas()
{
    int opcao;
    do
    {
        printf("\n========== Menu de Doações ==========\n");
        printf("1. Como doar dinheiro\n");
        printf("2. Como doar alimentos\n");
        printf("3. Como doar roupas e cobertores\n");
        printf("4. Como ser voluntário\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n=== Como doar dinheiro ===\n");
            printf("PIX: 92.958.800/0001-38 (SOS Rio Grande do Sul)\n");
            break;
        case 2:
            printf("\n=== Como doar alimentos ===\n");
            printf("Priorize alimentos não perecíveis: arroz, feijão, etc.\n");
            break;
        case 3:
            printf("\n=== Como doar roupas e cobertores ===\n");
            printf("Entregue roupas de frio em bom estado nos pontos de coleta.\n");
            break;
        case 4:
            printf("\n=== Como ser voluntário ===\n");
            printf("Cadastre-se na Defesa Civil do RS.\n");
            break;
        case 5:
            printf("\nObrigado por ajudar!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);
}

// Função para enviar mensagens de apoio
void enviar_mensagens()
{
    int tipo;
    printf("\nEnviar mensagens de apoio\n");
    printf("===============================\n");
    printf("1. Para crianças\n");
    printf("2. Para jovens\n");
    printf("3. Para adultos\n");
    printf("Escolha o destinatário: ");
    scanf("%d", &tipo);

    switch (tipo)
    {
    case 1:
        printf("Seja forte, pequeno! Dias melhores virão.\n");
        break;
    case 2:
        printf("Sua força inspira! Não desista.\n");
        break;
    case 3:
        printf("Você não está sozinho! Acredite na recuperação.\n");
        break;
    default:
        printf("Opção inválida. Tente novamente.\n");
    }
}
