/**
 * @file ex02.c
 * @author Gabriel Paludeto
 * @brief Crie uma função que retorne x*y através de operação de soma. A função
    recebe x e y por parâmetro
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

float retornaMultiplicacao(float x, float y) {

    if (y == 0) {
        return 0;
    } else {
        return x += retornaMultiplicacao(x, y - 1);
    }

}

int main() {

    float x, y, resultado;

    printf("Digite um valor para x\n");
    scanf("%f", &x);

    printf("Digite o número de vezes para multiplicar x\n");
    scanf("%f", &y);

    resultado = retornaMultiplicacao(x, y);

    printf("A multiplicação de %.2f * %.2f é igual a %.2f\n", x, y, resultado);

    return 0;

}