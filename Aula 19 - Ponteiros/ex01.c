/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @brief Escreva um programa que contenha duas variáveis inteiras. Compare os
    endereços e exiba o endereço e o conteúdo do maior endereço.
 * @version 0.1
 * @date 2024-04-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n1, n2;

    printf("Digite o valor da variável de número 1\n");
    scanf("%d", &n1);

    printf("Digite o valor da variável de número 2\n");
    scanf("%d", &n2);

    if (&n1 > &n2) {
        printf("Endereço 1: %p\n", &n1);
        printf("Conteúdo 1: %d\n", n1);
    } else {
        printf("Endereço 2: %p\n", &n2);
        printf("Conteúdo 2: %d\n", n2);
    }   //a primeira variável declarada sempre vai ser o maior valor, o endereço se desloca 4 bytes para trás na segunda atribuição

    return 0;

}