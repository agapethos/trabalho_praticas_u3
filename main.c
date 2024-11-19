/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#include <stdio.h>

void doar_para_vitimas() {
    int opcao;

    do {
        printf("\n========== Menu de Doações ==========\n");
        printf("1. Como doar dinheiro\n");
        printf("2. Como doar alimentos\n");
        printf("3. Como doar roupas e cobertores\n");
        printf("4. Como ser voluntário\n");
        printf("5. Sair\n");
        printf("=============================================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n=== Como doar dinheiro ===\n");
                printf("* Veja abaixo algumas opções para doações em dinheiro \n");
                printf("para órgãos oficiais e entidades confiáveis\n");
                printf("   - Governo do Rio Grande do Sul \n");
                printf("Chave PIX: 92.958.800/0001-38 (CNPJ)\n");
                printf("Nome: SOS Rio Grande do Sul / Banco: Banrisul\n");
                printf("---------------------------------------------\n");
                printf("\n   - Comunitas \n");
                printf("PIX - 92.958.800/0001-38 (CNPJ) \n");
                printf("--------------------------------------------\n");
                printf("\n   - Ação da Cidadania\n");
                printf("Doações também podem ser realizadas pelo site:\n");
                printf("www.acaodacidadania.org.br/emergencias\n");
                printf("e pelo PIX: sos@acaodacidadania.org.br\n");
                break;

            case 2:
                printf("\n=== Como doar alimentos ===\n");
                printf("* Priorize alimentos não perecíveis como:\n");
                printf("   - Arroz, feijão, macarrão, óleo, açúcar, leite em pó e enlatados.\n");
                printf("* Entregue as doações em:\n");
                printf("   - Centros de arrecadação organizados pela Defesa Civil do RS.\n");
                printf("   - Pontos oficiais em escolas, igrejas e prefeituras das cidades atingidas.\n");
                printf("* Consulte rádios locais e redes sociais para saber os pontos de coleta mais próximos.\n");
                break;

            case 3:
                printf("\n=== Como doar roupas e cobertores ===\n");
                printf("1. Priorize roupas em bom estado, especialmente para frio e chuva:\n");
                printf("   - Casacos, calças, blusas de frio, sapatos e cobertores.\n");
                printf("2. Evite doar roupas de verão ou em mau estado.\n");
                printf("3. Locais de entrega:\n");
                printf("   - Centros comunitários e igrejas próximas às áreas afetadas.\n");
                printf("   - Bancos de doação organizados por supermercados parceiros.\n");
                break;

            case 4:
                printf("\n=== Como ser voluntário ===\n");
                printf("* Entre em contato com a Defesa Civil do RS para se cadastrar como voluntário:\n");
                printf("   - Acesse: casamilitar-rs.com.br/voluntariado\n");
                printf("   - Telefones de contato disponíveis no site oficial.\n");
                printf("* Atividades comuns para voluntários:\n");
                printf("   - Distribuição de alimentos e roupas nas áreas atingidas.\n");
                printf("   - Limpeza e reparos emergenciais em casas e vias públicas.\n");
                printf("* Consulte organizações locais para participar de mutirões.\n");
                break;

            case 5:
                printf("\nObrigado por se preocupar com as vítimas da tragédia no Rio Grande do Sul.\n");
                printf("Sua ajuda faz  diferença!\n");
                break;

            default:
                printf("\nDeu ruim. Por favor, tente novamente.\n");
                break;
        }
    } while (opcao != 5);
}



int main()
{
    
    int escolha;
    
    while(escolha != 4){
        printf("\n");
        printf("1. Verificar  a previsao do Tempo\n");
        printf("2.Doar para vítimas das chuvas\n");
        printf("3.Enviar mensagens de apoio\n");
        printf("4.Sair\n");
        
        scanf("%d", &escolha);
        
        if(escolha==1){
            
        }
        
        if(escolha==2){
           doar_para_vitimas();
            
        }
        
        if(escolha ==3){
            
        }
    }

    return 0;
}