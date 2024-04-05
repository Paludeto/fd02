/**
 * @file ex03.c
 * @author Gabriel Paludeto
 * @brief Crie uma função que retorne x elevado a y através de operação de
    multiplicação. A função recebe x e y por parâmetro
 * @version 0.1
 * @date 2024-04-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

float retornaPotencia(float x, float y);

int main() {

    float x, y, resultado;

    printf("Digite um valor para x\n");
    scanf("%f", &x);

    printf("Digite um valor para y\n");
    scanf("%f", &y);

    resultado = retornaPotencia(x, y);

    printf("%.2f elevado a %.2f é igual a %.2f\n", x, y, resultado);

    return 0;

}

float retornaPotencia(float x, float y) {

    if (y == 0) {
        return 1;
    } else {
        return x * retornaPotencia(x, y - 1);
    }

}