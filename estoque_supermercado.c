/*
 * Sistema de Controle de Estoque - Supermercado
 *
 * Um supermercado deseja registrar a quantidade em estoque de 10 produtos.
 * O sistema:
 *   - Lê e armazena as quantidades em estoque de cada produto em um vetor
 *   - Mostra quais produtos estão com estoque abaixo de 5 unidades
 *   (OBS: usa o índice do vetor para identificar o produto)
 */

#include <stdio.h>

#define TOTAL_PRODUTOS 10
#define ESTOQUE_MINIMO 5

int main(void)
{
    int estoque[TOTAL_PRODUTOS];

    printf("=== Sistema de Controle de Estoque ===\n\n");

    /* Leitura das quantidades em estoque */
    for (int i = 0; i < TOTAL_PRODUTOS; i++) {
        printf("Informe a quantidade em estoque do Produto %d: ", i);
        scanf("%d", &estoque[i]);
    }

    /* Exibição dos produtos com estoque abaixo de 5 unidades */
    printf("\n--- Produtos com estoque abaixo de %d unidades ---\n", ESTOQUE_MINIMO);

    int encontrou = 0;
    for (int i = 0; i < TOTAL_PRODUTOS; i++) {
        if (estoque[i] < ESTOQUE_MINIMO) {
            printf("Produto %d -> Estoque: %d unidade(s)\n", i, estoque[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum produto com estoque abaixo de %d unidades.\n", ESTOQUE_MINIMO);
    }

    return 0;
}
