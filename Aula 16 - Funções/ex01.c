/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @brief Faça um algoritmo que implemente uma função que receba 3 números
    inteiros e retorne o maior valor;
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv);
int retornaMaior(int numeros[3]);

int main(int argc, char **argv) {

    int numeros[3];
    int maior;

    if (argc != 4) {
        printf("Digite um número válido de argumentos\n");
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        numeros[i] = strtol(argv[i + 1], NULL, 10);
    }

    maior = retornaMaior(numeros);
    
    printf("O maior número é igual a %i\n", maior);

    return 0;

}

/**
 * @brief Retorna o maior número
 * 
 * @param numeros 
 * @return Maior número de um array de 3 elementos
 */
int retornaMaior(int numeros[3]) {

    int maior = INT_MIN;

    for (int i = 0; i < 3; i++) {

        if (numeros[i] > maior) {
            maior = numeros[i];
        } 

        if (numeros[i] < 0) {
            return -1;
        }
        
    }

    return maior;

}