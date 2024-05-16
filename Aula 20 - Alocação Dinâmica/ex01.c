/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @brief  1) Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. Em
    seguida, faça a alocação dinâmica desse vetor. Por fim, leia o vetor do usuário e o
    imprima.
 * @version 0.1
 * @date 2024-05-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int main() {

    int tamanhoVetor;

    printf("Digite o tamanho desejado para o vetor\n");
    scanf("%d", &tamanhoVetor);

    int *vetor = (int *) malloc(tamanhoVetor * sizeof(int));

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