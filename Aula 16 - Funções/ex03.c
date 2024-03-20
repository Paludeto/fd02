/**
 * @file ex03.c
 * @author Gabriel Paludeto
 * @brief Escreva um procedimento que recebe por parâmetro as 3 notas de um
    aluno e uma letra. Se a letra for A, o procedimento calcula a média
    aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3
    e 2) e se for S, a soma das notas. O valor calculado também deve ser
    retornado e exibido na função main.
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv);
float calculo_notas(float n1, float n2, float n3, char letra);


int main(int argc, char **argv) {

    float n1, n2, n3, resultado;
    char letra;

    if (argc != 5) {
        printf("Digite um número válido de argumentos!\n");
        return 0;
    }

    n1 = strtol(argv[1], NULL, 10);
    n2 = strtol(argv[2], NULL, 10);
    n3 = strtol(argv[3], NULL, 10);
    letra = argv[4][0];

    resultado = calculo_notas(n1, n2, n3, letra);

    if (resultado == -1) {
        printf("Caractere inválido digitado\n");
        return 0;
    }

    printf("O resultado da sua operação é igual a %.2f\n", resultado);

    return 0;

}

/**
 * @brief Calcula média aritmética, média ponderada, ou soma entre 3 notas
 * 
 * @param n1 
 * @param n2 
 * @param n3 
 * @param letra 
 * @return Média aritmética, média ponderada, ou soma entre 3 notas
 */
float calculo_notas(float n1, float n2, float n3, char letra) {
    
    float resultado;

    if (tolower(letra) == 'a') {
        resultado = (n1 + n2 + n3) / 3;
    } else if (tolower(letra) == 'p') {
        resultado = (n1 * 5 + n2 * 3 + n3 * 2) / 10;
    } else if (tolower(letra) == 's') {
        resultado = n1 + n2 + n3;
    } else {
        return -1;
    }

    return resultado;

}