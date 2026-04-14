/*
 * Avaliação Física em Academia
 *
 * Programa que registra o peso e a altura de 6 alunos e calcula:
 * - O IMC de cada aluno
 * - A média de IMC da turma
 * - O aluno mais próximo do peso ideal (IMC = 22.5)
 *
 * Fórmula do IMC: peso (kg) / altura² (m)
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define NUM_ALUNOS 6
#define IMC_IDEAL 22.5

void classificar_imc(float imc, char *classificacao) {
    if (imc < 18.5)
        strcpy(classificacao, "Abaixo do peso");
    else if (imc < 24.9)
        strcpy(classificacao, "Peso normal");
    else if (imc < 29.9)
        strcpy(classificacao, "Sobrepeso");
    else if (imc < 34.9)
        strcpy(classificacao, "Obesidade grau I");
    else if (imc < 39.9)
        strcpy(classificacao, "Obesidade grau II");
    else
        strcpy(classificacao, "Obesidade grau III");
}

int main(void) {
    char nomes[NUM_ALUNOS][50];
    float peso[NUM_ALUNOS], altura[NUM_ALUNOS], imc[NUM_ALUNOS];
    float soma_imc = 0.0;
    float media_imc;
    int indice_ideal = 0;
    float menor_diferenca;
    char classificacao[50];

    printf("==========================================\n");
    printf("   AVALIACAO FISICA - ACADEMIA\n");
    printf("==========================================\n\n");

    /* Entrada de dados dos 6 alunos */
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("--- Aluno %d ---\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", nomes[i]);

        printf("Peso (kg): ");
        scanf("%f", &peso[i]);

        printf("Altura (m): ");
        scanf("%f", &altura[i]);

        /* Calculo do IMC do aluno */
        imc[i] = peso[i] / (altura[i] * altura[i]);
        soma_imc += imc[i];

        printf("\n");
    }

    /* Calculo da media de IMC da turma */
    media_imc = soma_imc / NUM_ALUNOS;

    /* Encontrar o aluno mais proximo do peso ideal (IMC = 22.5) */
    menor_diferenca = fabs(imc[0] - IMC_IDEAL);
    for (int i = 1; i < NUM_ALUNOS; i++) {
        float diferenca = fabs(imc[i] - IMC_IDEAL);
        if (diferenca < menor_diferenca) {
            menor_diferenca = diferenca;
            indice_ideal = i;
        }
    }

    /* Exibicao dos resultados */
    printf("\n==========================================\n");
    printf("   RESULTADOS DA AVALIACAO\n");
    printf("==========================================\n\n");

    printf("%-20s %-10s %-10s %-10s %s\n", "Nome", "Peso(kg)", "Altura(m)", "IMC", "Classificacao");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < NUM_ALUNOS; i++) {
        classificar_imc(imc[i], classificacao);
        printf("%-20s %-10.1f %-10.2f %-10.2f %s\n",
               nomes[i], peso[i], altura[i], imc[i], classificacao);
    }

    printf("\n==========================================\n");
    printf("  Media de IMC da turma: %.2f\n", media_imc);
    printf("==========================================\n");

    classificar_imc(media_imc, classificacao);
    printf("  Classificacao media: %s\n", classificacao);

    printf("\n==========================================\n");
    printf("  Aluno mais proximo do peso ideal (IMC = %.1f):\n", IMC_IDEAL);
    printf("  %s (IMC: %.2f)\n", nomes[indice_ideal], imc[indice_ideal]);
    printf("==========================================\n");

    return 0;
}
