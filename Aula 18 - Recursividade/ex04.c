/**
 * @file ex04.c
 * @author Gabriel Paludeto
 * @brief  Faça uma função recursiva que retorne o n-ésimo termo da sequência de
    Fibonacci, sendo que n é recebido por parâmetro. Utilize essa função para
    desenvolver um programa que mostre no main() os n termos dessa
    sequência na tela, a partir do valor de n recebido pelo teclado. Sabe-se que
    o 1º termo é 0 e o 2º termo é 1.
 * @version 0.1
 * @date 2024-04-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int indice);

int main() {

    int n, resultado;

    printf("Digite o número do termo da sequência de Fibonacci que deseja exibir\n");
    scanf("%d", &n);

    resultado = fibonacci(n);

    printf("O termo de número %d é igual a %d\n", n, resultado);

    return 0;

}

int fibonacci(int indice) {

    //casos base, dois primeiros termos
    if (indice == 1 || indice == 2) {
        return 1;
    } else {    
        return fibonacci(indice - 1) + fibonacci(indice - 2);
    }

}
