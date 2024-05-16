/**
 * @file ex02.c
 * @author Gabriel Paludeto
 * @brief 2) Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne
    o ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou
    igual a zero, um ponteiro nulo deverá ser retornado.
 * @version 0.1
 * @date 2024-05-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int *retornaVetor(int n) {

    if (n <= 0) {
        fprintf(stderr, "Tamanho de vetor inválido\n");
        return NULL;
    }

    int *vetor = (int *) malloc(n * sizeof(int));

    return vetor;

}

int main() {

    int tamanhoVetor;

    printf("Digite um tamanho para o vetor\n");
    scanf("%d", &tamanhoVetor);

    int *vetor = retornaVetor(tamanhoVetor);

    if (vetor == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tamanhoVetor; i++) {
        printf("Digite um número inteiro para a posição %d\n", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor digitado pelo usuário:\n");

    for (int i = 0; i < tamanhoVetor; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    
    free(vetor);

    return 0;

}