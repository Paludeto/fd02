/**
 * @file ex02.c
 * @author Gabriel Paludeto
 * @brief Reescreva o exercício anterior utilizando a estrutura horário
    (contendo hora, minuto e segundo) e passando a estrutura por
    referência. Utilize o seguinte protótipo da função:
    void converteHorario(int total_segundos, Horario* hor) 
 * @version 0.1
 * @date 2024-03-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Horario {
    int horas, minutos, segundos;
} Horario;

void converteHorario(int totalSegundos, Horario *horario);

int main() {

    Horario horario;
    int totalSegundos;

    printf("Digite um número de segundos\n");
    scanf("%d", &totalSegundos);

    converteHorario(totalSegundos, &horario);

    printf("%02d:%02d:%02d\n", horario.horas, horario.minutos, horario.segundos);
    
    return 0;

}

void converteHorario(int totalSegundos, Horario *horario) {

    horario->segundos = totalSegundos;

    if (totalSegundos >= 60) {
        horario->segundos = 0;
    }

    horario->minutos = totalSegundos / 60;

    if (horario->minutos >= 60) {
        horario->minutos = 0;
    }

    horario->horas = totalSegundos / 3600;

    return;

}