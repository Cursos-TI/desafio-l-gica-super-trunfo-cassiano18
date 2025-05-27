#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

void calcularEstatisticas(Carta *carta) {
    // Calcula a densidade populacional e o PIB per capita
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

void exibirCarta(Carta carta) {
    printf("Cidade: %s (%s)\n", carta.cidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("\n");
}

int main() {
    // Definição das duas cartas
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.0, 800.0, 20};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1182.0, 350.0, 15};

    // Calculando estatísticas
    calcularEstatisticas(&carta1);
    calcularEstatisticas(&carta2);

    // Exibindo as cartas
    printf("=== Carta 1 ===\n");
    exibirCarta(carta1);

    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // Atributo escolhido para comparação: PIB per capita
    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");
    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);

    // Comparação usando estruturas de decisão
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}

