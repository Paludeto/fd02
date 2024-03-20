/**
 * @file ex02.c
 * @author Gabriel Paludeto
 * @brief Elabore uma função que receba por parâmetro o sexo (caractere) e a
    altura de uma pessoa (real), calcule e retorne seu peso ideal. Para isso,
    utilize as fórmulas a seguir.
    - Para homens: (72.7 * altura) - 58
    - Para mulheres: (62.1 * altura) - 44.7
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define PESO_HOMEM 72.7
#define PESO_MULHER 62.1

int main(int argc, char **argv);
float calcular_peso_ideal(char sexo, float altura);

int main(int argc, char **argv) {

    char sexo;
    float altura, pesoIdeal;

    if (argc != 3) {
        printf("Digite um valor válido de argumentos\n");
        return 0;
    }

    sexo = argv[1][0];
    altura = atof(argv[2]);

    pesoIdeal = calcular_peso_ideal(sexo, altura);

    printf("O seu peso ideal é igual a %.2fkg\n", pesoIdeal);

    return 0;

}

/**
 * @brief Retorna o peso ideal de uma pessoa baseada em seu sexo e altura
 * 
 * @param sexo 
 * @param altura 
 * @return peso ideal de acordo com o sexo e altura 
 */
float calcular_peso_ideal(char sexo, float altura) { 

    float pesoIdeal;

    if (sexo == 'h') {
        pesoIdeal = (PESO_HOMEM * altura) - 58;
    } else if (sexo == 'm') {
        pesoIdeal = (PESO_MULHER * altura) - 44.7;
    } else {
        printf("Digite um caractere válido");
        return 0;
    }

    return pesoIdeal;

}


