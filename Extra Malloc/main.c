/**
 * @file main.c
 * @author Faça um programa que receba valores enquanto forem positivos.
 * 
    Para isso, inicialmente, aloque dinamicamente um vetor de 5 números inteiros.

    A cada vez que preencher as posições disponíveis, realoque o vetor aumentando o seu tamanho em 5 posições.

    Ao receber um valor negativo, pare de solicitar novos valores e realoque o vetor para o tamanho exato da quantidade de elementos válidos digitados.


    Ao finalizar, exiba os valores recebidos e Libere a memória alocada.
 * @brief 
 * @version 0.1
 * @date 2024-06-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define TAM_INICIAL 5

int main() {

    int *vetor = (int *) malloc(TAM_INICIAL * sizeof(int));

    if (vetor == NULL) {
        perror("Erro de alocação\n");
        exit(EXIT_FAILURE);
    }

    int indice = 0;
    int tamanhoNovo = TAM_INICIAL;
    
    do {

        if (vetor[indice - 1] < 0) {
            break;
        }

        if (indice > 4) {
            tamanhoNovo += 5;
            vetor = realloc(vetor, tamanhoNovo * sizeof(int));
            
            if (vetor == NULL) {
                perror("Erro de alocação\n");
                exit(EXIT_FAILURE);
            }
        }

        printf("Digite um valor a ser inserido no vetor\n");
        scanf("%d", &vetor[indice]);

        indice++;

    } while (1);

    vetor = (int *) realloc (vetor, indice * sizeof(int));
    
    printf("[ ");
    for (int i = 0; i < indice; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");

    free(vetor);

    return 0;

}