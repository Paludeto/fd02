/**
 * @file ex06.c
 * @author Gabriel Paludeto
 * @brief 6) Considere a funcaox abaixo. O que essa função faz? Escreva
    uma função não-recursiva que resolve o mesmo problema

    int funcaox(int a){
        if(a <= 0) return 0;
        else return a + funcaox(a-1);
    }//funcaox
    
 * @version 0.1
 * @date 2024-04-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int funcaox(int a);

int main() {

    int a, resultado;

    printf("Digite um valor inteiro\n");
    scanf("%d", &a);

    resultado = funcaox(a);

    printf("O resultado sobre o número %d é igual a %d\n", a, resultado);

    return 0; 
    
}

int funcaox(int a) {

    int somatorio = a;

    for (int i = a; i > 0; i--) {
        somatorio += i - 1;
    }

    return somatorio;

}
