/**
 * @file ex03.c
 * @author Gabriel Paludeto
 * @brief Crie um programa que contenha uma matriz (3x3) de float. Imprima o
    endereço de cada posição dessa matriz.
 * @version 0.1
 * @date 2024-04-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3

int main() {

    float matriz[LINHAS][COLUNAS];

    for (int i = 0; i < COLUNAS; i++) {
        for (int j = 0; j < LINHAS; j++) {
            printf("Endereço %dx%d: %p\n", i + 1, j + 1, &matriz[i][j]);
        }
    }   

    return 0;

}