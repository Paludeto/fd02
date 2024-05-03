/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @brief Crie uma função que retorne o fatorial de um número passado por
    parâmetro. A ideia do fatorial está abaixo:
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int retornaFatorial(int n) {

    if (n == 0) {
        return 1;
    } else {
        return n * retornaFatorial(n - 1);
    }

}

int main() {

    int numero, fatorial;

    printf("Digite um número para calcular o seu fatorial\n");
    scanf("%d", &numero);

    fatorial = retornaFatorial(numero);

    printf("O fatorial do número %d é igual a %d\n", numero, fatorial);

    return 0;

} 