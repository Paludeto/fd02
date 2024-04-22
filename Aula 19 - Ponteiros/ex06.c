/**
 * @file ex06.c
 * @author Gabriel Paludeto
 * @brief Considere a seguinte declaração:
    int a, *b, **c, ***d;
    Escreva um programa que receba o valor de a, calcule e exiba:
     O dobro do valor a, utilizando o ponteiro b
     O triplo do valor a, utilizando o ponteiro c
     O quadruplo do valor a, utilizando o ponteiro d
 * @version 0.1
 * @date 2024-04-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, *b, **c, ***d;

    b = &a;
    c = &b;
    d = &c;

    printf("Digite o valor de a\n");
    scanf("%d", &a);

    *b = 2 * a;

    printf("Dobro: %d\n", *b);

    **c = 3 * a;

    printf("Triplo: %d\n", **c);

    ***d = 4 * a;

    printf("Quadrúplo: %d\n", ***d);

    return 0;

}