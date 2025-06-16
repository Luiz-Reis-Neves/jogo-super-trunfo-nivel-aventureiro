#include <stdio.h>
#include <string.h>

int main() {
    // Dados das duas cartas
    char nomeCidade[2][50];
    int populacao[2];
    float area[2], pib[2], densidade[2];
    int pontosTuristicos[2];

    // Entrada de dados das 2 cartas
    for (int i = 0; i < 2; i++) {
        printf("Cadastro da Carta %d:\n", i + 1);

        printf("Nome do País: ");
        scanf(" %[^\n]", nomeCidade[i]);

        printf("População: ");
        scanf("%d", &populacao[i]);

        printf("Área (em km²): ");
        scanf("%f", &area[i]);

        printf("PIB (em bilhões de reais): ");
        scanf("%f", &pib[i]);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &pontosTuristicos[i]);

        densidade[i] = populacao[i] / area[i];

        printf("\n");
    }

    int opcao;
    char continuar;

        //menu de comparacao que ira pegar os dados que o usuario digitol e comparar e declarar qual foi o melhor
    do {
        printf("\n=== MENU DE COMPARAÇÃO ===\n");
        printf("[1] - População\n");
        printf("[2] - Área\n");
        printf("[3] - PIB\n");
        printf("[4] - Pontos Turísticos\n");
        printf("[5] - Densidade Demográfica\n");
        printf("[0] - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        int vencedor = -1;
        char atributo[50];
        // logica para tratar os dados fazendo comparacoes utilizando a estrutura de decisao switch case e if else
        switch (opcao) {
            case 1:
                strcpy(atributo, "População");
                if (populacao[0] > populacao[1]) vencedor = 0;
                else if (populacao[1] > populacao[0]) vencedor = 1;
                printf("\n--- COMPARAÇÃO POR POPULAÇÃO ---\n");
                printf("%s: %d habitantes\n", nomeCidade[0], populacao[0]);
                printf("%s: %d habitantes\n", nomeCidade[1], populacao[1]);
                break;
            case 2:
                strcpy(atributo, "Área");
                if (area[0] > area[1]) vencedor = 0;
                else if (area[1] > area[0]) vencedor = 1;
                printf("\n--- COMPARAÇÃO POR ÁREA ---\n");
                printf("%s: %.2f km²\n", nomeCidade[0], area[0]);
                printf("%s: %.2f km²\n", nomeCidade[1], area[1]);
                break;
            case 3:
                strcpy(atributo, "PIB");
                if (pib[0] > pib[1]) vencedor = 0;
                else if (pib[1] > pib[0]) vencedor = 1;
                printf("\n--- COMPARAÇÃO POR PIB ---\n");
                printf("%s: %.2f bilhões de reais\n", nomeCidade[0], pib[0]);
                printf("%s: %.2f bilhões de reais\n", nomeCidade[1], pib[1]);
                break;
            case 4:
                strcpy(atributo, "Pontos Turísticos");
                if (pontosTuristicos[0] > pontosTuristicos[1]) vencedor = 0;
                else if (pontosTuristicos[1] > pontosTuristicos[0]) vencedor = 1;
                printf("\n--- COMPARAÇÃO POR PONTOS TURÍSTICOS ---\n");
                printf("%s: %d pontos\n", nomeCidade[0], pontosTuristicos[0]);
                printf("%s: %d pontos\n", nomeCidade[1], pontosTuristicos[1]);
                break;Resultado final formatado
            case 5:
                strcpy(atributo, "Densidade Demográfica");
                if (densidade[0] < densidade[1]) vencedor = 0;
                else if (densidade[1] < densidade[0]) vencedor = 1;
                printf("\n--- COMPARAÇÃO POR DENSIDADE DEMOGRÁFICA (menor vence) ---\n");
                printf("%s: %.2f hab/km²\n", nomeCidade[0], densidade[0]);
                printf("%s: %.2f hab/km²\n", nomeCidade[1], densidade[1]);
                break;
            case 0:
                printf("\nEncerrando o jogo...\n");
                return 0;
            default:
                printf("\nOpção inválida!\n");
                continue;
        }

        // exibir o resultado das comparacoes ja formatadas

        printf("\n====== RESULTADO DA COMPARAÇÃO ======\n");
        printf("Atributo Comparado: %s\n", atributo);
        printf("%s: ", nomeCidade[0]);
        switch (opcao) {
            case 1: printf("%d\n", populacao[0]);
            break;
            case 2: printf("%.2f km²\n", area[0]);
            break;
            case 3: printf("%.2f bilhões\n", pib[0]);
            break;
            case 4: printf("%d pontos turísticos\n", pontosTuristicos[0]);
            break;
            case 5: printf("%.2f hab/km²\n", densidade[0]);
            break;
        }
        printf("%s: ", nomeCidade[1]);
        switch (opcao) {
            case 1: printf("%d\n", populacao[1]);
            break;
            case 2: printf("%.2f km²\n", area[1]);
            break;
            case 3: printf("%.2f bilhões\n", pib[1]);
            break;
            case 4: printf("%d pontos turísticos\n", pontosTuristicos[1]);
            break;
            case 5: printf("%.2f hab/km²\n", densidade[1]);
            break;
        }

        if (vencedor == -1)
            printf("Resultado: Empate!\n");
        else
            printf("Resultado: %s venceu!\n", nomeCidade[vencedor]);

        printf("=====================================\n");

        printf("\nDeseja fazer outra comparação? (s/n): ");
        scanf(" %c", &continuar);

        //coloquei a opcao do usuario digitar tanto com o s maiusculo quanto minusculo utilizando a estrutua de repeticao while
    } while (continuar == 's' || continuar == 'S');

    //mensagem de finalizacao do game
    printf("\nObrigado por jogar!\n");
    return 0;
}
