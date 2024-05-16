/**
 * @file ex04.c
 * @author Gabriel Paludeto
 * @brief 4) Escreva uma função que receba como parâmetro um valor L e um valor C e retorne
    o ponteiro para uma matriz alocada dinamicamente contendo L linhas e C colunas.
    Essa matriz deve ser inicializada com o valor 0 em todas as suas posições.
    Obs: Ao final de cada programa, não se esqueça de liberar a memória alocada
    dinamicamente
 * @version 0.1
 * @date 2024-05-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int **retornaMatriz(int L, int C) {

    int **matriz = (int **) malloc(L * sizeof(int*));

    if (matriz == NULL) {
        fprintf(stderr, "Erro de alocação\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < L; i++) {

        matriz[i] = (int *) calloc(C, sizeof(int));

        if (matriz[i] == NULL) {
            fprintf(stderr, "Erro de alocação\n");
            exit(EXIT_FAILURE);
        }

    }
    
    return matriz;

}

void liberaMatriz(int **matriz, int L) {

    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return;

}

int main() { 

    int L, C;

    printf("Digite o número de linhas desejadas para a sua matriz\n");
    scanf("%d", &L);

    printf("Digite o número de colunas desejadas para a sua matriz\n");
    scanf("%d", &C);

    int **matriz = retornaMatriz(L, C);

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    liberaMatriz(matriz, L);

    return 0;

}