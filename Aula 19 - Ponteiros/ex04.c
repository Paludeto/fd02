/**
 * @file ex04.c
 * @author Gabriel Paludeto
 * @brief  Crie um programa que contenha um vetor de inteiros de tamanho 5.
    Utilizando aritmética de ponteiros, leia os dados do teclado e exiba seus
    valores multiplicado por 2. Em seguida, exiba o endereço de memória das
    posições que contém valores pares.
 * @version 0.1
 * @date 2024-04-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

int main() {

    int valores[TAMANHO];

    for (int i = 0; i < TAMANHO; i++) {
        printf("Digite o valor de número %d\n", i + 1);
        scanf("%d", &*(valores + i));
    }

    printf("Valores divisíveis por 2:\n");
    for (int j = 0; j < TAMANHO; j++) {
        if(*(valores + j) % 2 == 0) {
            printf("%d ", *(valores + j));
        }
    }
    printf("\n");

    return 0;

}