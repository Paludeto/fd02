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

Ponto *criaPonto() {

    Ponto *novoPonto = (Ponto *)malloc(sizeof(Ponto));

    if (novoPonto == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        return NULL;
    }

    printf("Digite a coordenada X do ponto:\n");
    scanf("%f", &novoPonto->x);

    printf("Digite a coordenada Y do ponto:\n");
    scanf("%f", &novoPonto->y);

    return novoPonto;

}

void deletaPonto(Ponto *ponto) {

    if (ponto != NULL) {
        free(ponto);
    }

}

float calculaDistancia(Ponto *pontoA, Ponto *pontoB) {

    float distancia = sqrt(pow(pontoB->x - pontoA->x, 2) + pow(pontoB->y - pontoA->y, 2));

    return distancia;

}

int main() {
    
    printf("Ponto 1\n");
    Ponto *pontoA = criaPonto();
    printf("Ponto 2\n");
    Ponto *pontoB = criaPonto();

    float distancia = calculaDistancia(pontoA, pontoB);

    deletaPonto(pontoA);
    deletaPonto(pontoB);

    printf("A distância entre os dois pontos é de aproximadamente %.2f u.m.\n", distancia);


    return 0;

}