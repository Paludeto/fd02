/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @brief Escreva um programa que receba um número inteiro
    representando a quantidade total de segundos e, usando
    passagem de parâmetros por referência, converta a
    quantidade informada de segundos em Horas, Minutos e
    Segundos. Imprima o resultado da conversão no formato
    HH:MM:SS. Utilize o seguinte protótipo da função:
    void converteHora(int total_segundos, int* hora, int* min, int* seg)
 * @version 0.1
 * @date 2024-03-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

void converteHora(int totalSegundos, int *hora, int *min, int *seg);

int main() {

    int segundos;
    int hora, min, seg;

    printf("Digite um número de segundos\n");
    scanf("%d", &segundos);

    converteHora(segundos, &hora, &min, &seg);

    printf("%02d:%02d:%02d\n", hora, min, seg);

    return 0;

}

void converteHora(int totalSegundos, int *hora, int *min, int *seg) {
    
    *hora = totalSegundos / 3600;
    *min = totalSegundos / 60;

    if (*min >= 60) {
        *min = 0;
    }

    *seg = totalSegundos;

    if (*seg >= 60) {
        *seg = 0;
    }
    
    return;
    
}   