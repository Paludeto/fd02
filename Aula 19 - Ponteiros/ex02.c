/**
 * @file ex02.c
 * @author Gabriel Paludeto
 * @brief Crie um programa que contenha um vetor float (tamanho 10). Imprima o
    endereço de cada posição desse vetor.
 * @version 0.1
 * @date 2024-04-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

int main() {

    float vetor[TAMANHO];

    for (int i = 0; i < TAMANHO; i++) {
        printf("Endereço %d: %p\n", i, &vetor[i]);
    }

    return 0;

}