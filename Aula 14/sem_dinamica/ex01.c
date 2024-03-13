/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @brief Crie uma estrutura para representar as coordenadas de
    um ponto no plano (posições X e Y). Em seguida, declare
    e leia do teclado dois pontos e exiba a distância entre
    eles.
 * @version 0.1
 * @date 2024-03-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto {
    float x, y;
} Ponto;

float calculaDistancia(Ponto pontoA, Ponto pontoB) {

    float distancia = sqrt(pow(pontoB.x - pontoA.x, 2) + pow(pontoB.y - pontoA.y, 2));

    return distancia;

}

int main() {
    
    Ponto ponto1, ponto2;
    float distancia;
    
    printf("Digite a coordenada X do ponto:\n");
    scanf("%f", &ponto1.x);

    printf("Digite a coordenada Y do ponto:\n");
    scanf("%f", &ponto1.y);

    printf("Digite a coordenada X do ponto:\n");
    scanf("%f", &ponto2.x);

    printf("Digite a coordenada Y do ponto:\n");
    scanf("%f", &ponto2.y);

    distancia = calculaDistancia(ponto1, ponto2);


    printf("A distância entre os dois pontos é de aproximadamente %.2f u.m.\n", distancia);


    return 0;

}