/**
 * @file ex05.c
 * @author Gabriel Paludeto
 * @brief Crie uma função que que receba o valor de um inteiro
    positivo N, calcule e retorne o fatorial desse número.
 * @version 0.1
 * @date 2023-11-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv);
double calcular_fatorial(int num);

int main(int argc, char **argv) {

    int num;
    double fatorial;

    if (argc != 2) {
        printf("Número inválido de argumentos\n");
        return 0;
    }

    num = strtol(argv[1], NULL, 10);
    fatorial = calcular_fatorial(num);

    printf("O fatorial do número %d é igual a %.0f\n", num, fatorial);

    return 0;

}

/**
 * @brief Cacula o fatorial de um número inteiro
 * 
 * @param num 
 * @return Fatorial de um número inteiro
 */
double calcular_fatorial(int num) {
    
    double fatorial = 1;

    while (num > 1) {
        fatorial = fatorial * num;
        num--;
    } 

    return fatorial;

}