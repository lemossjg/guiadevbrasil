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

#define NUM_ALUNOS 6
#define IMC_IDEAL 22.5

void imprimir_classificacao(float imc) {
    if (imc < 18.5)
        printf("Abaixo do peso");
    else if (imc < 25.0)
        printf("Peso normal");
    else if (imc < 30.0)
        printf("Sobrepeso");
    else if (imc < 35.0)
        printf("Obesidade grau I");
    else if (imc < 40.0)
        printf("Obesidade grau II");
    else
        printf("Obesidade grau III");
}

int main(void) {
    char nomes[NUM_ALUNOS][50];
    float peso[NUM_ALUNOS], altura[NUM_ALUNOS], imc[NUM_ALUNOS];
    float soma_imc = 0.0;
    float media_imc;
    int indice_ideal = 0;
    float menor_diferenca;

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
        printf("%-20s %-10.1f %-10.2f %-10.2f ", nomes[i], peso[i], altura[i], imc[i]);
        imprimir_classificacao(imc[i]);
        printf("\n");
    }

    printf("\n==========================================\n");
    printf("  Media de IMC da turma: %.2f\n", media_imc);
    printf("==========================================\n");

    printf("  Classificacao media: ");
    imprimir_classificacao(media_imc);
    printf("\n");

    printf("\n==========================================\n");
    printf("  Aluno mais proximo do peso ideal (IMC = %.1f):\n", IMC_IDEAL);
    printf("  %s (IMC: %.2f)\n", nomes[indice_ideal], imc[indice_ideal]);
    printf("==========================================\n");

    return 0;
}
