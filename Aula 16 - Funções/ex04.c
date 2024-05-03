/**
 * @file ex04.c
 * @author Gabriel Paludeto
 * @brief Faça uma função que receba a média final de um aluno
    por parâmetro e retorne o seu conceito, conforme a tabela
    abaixo:
 * @version 0.1
 * @date 2023-11-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv);
char retornar_conceito(float mediaFinal);

int main(int argc, char **argv) {

    float mediaFinal;
    char conceito;

    if (argc != 2) {
        printf("Número inválido de argumentos\n");
        return 0;
    }

    mediaFinal = strtol(argv[1], NULL, 10);
    conceito = retornar_conceito(mediaFinal);

    if (conceito == 'Z') {
        printf("Valor inválido\n");
        return 0;
    }

    printf("O conceito é igual a %c\n", conceito);
    
    return 0;

}

/**
 * @brief Retorna conceito com base em média final
 * 
 * @param mediaFinal 
 * @return Retorna o conceito de um aluno com base em sua média final 
 */
char retornar_conceito(float mediaFinal) {

    char conceito;

    if (mediaFinal >= 9 && mediaFinal <= 10) {
        conceito = 'A';
    } else if (mediaFinal >= 7 && mediaFinal < 9) {
        conceito = 'B';
    } else if (mediaFinal >= 5 && mediaFinal < 7) {
        conceito = 'C';
    } else if (mediaFinal >= 0 && mediaFinal < 5) {
        conceito = 'D';
    } else {
        conceito = 'Z';
    }

    return conceito;

}