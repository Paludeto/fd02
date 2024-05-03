/**
 * @file ex05.c
 * @author Gabriel Paludeto
 * @brief Um problema típico em ciência da computação consiste em
    converter um número da sua forma decimal para binária. Crie um
    algoritmo recursivo para resolver esse problema.
    - Solução trivial: x=0 quando o número inteiro já foi convertido para
    binário
    - Passo da recursão: saber como x/2 é convertido. Depois, imprimir um
    dígito (0 ou 1) dado o sucesso da divisão.
 * @version 0.1
 * @date 2024-04-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

void conversaoBinaria(int n);

int main() {

    int n;

    printf("Digite um valor para o número n\n");
    scanf("%d", &n);

    conversaoBinaria(n);
    printf("\n");

    return 0;

}

void conversaoBinaria(int n) {

    if (n == 0) {
        return;
    } else {
        conversaoBinaria(n / 2);
        printf("%d", n % 2);
    }

}