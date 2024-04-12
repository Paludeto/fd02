/**
 * @file ex03.c
 * @author Gabriel Paludeto
 * @brief Elabore uma função que receba como parâmetro um valor inteiro n e gere como saída um triângulo lateral formado por asteriscos conforme o exemplo a seguir, 
 * em que usamos n = 4:
    *
    **
    ***
    ****
    ***
    **
    *
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void imprimeTriangulo(int n) {
   
   for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j < i; j++) {
         printf("*");
      }
      printf("\n");
   }

   for (int i = n; i > 0; i--) {
      for (int j = 0; j < i; j++) {
         printf("*");
      }
      printf("\n");
   }

}

int main() {

   int n;
   printf("Digite o valor desejado para a altura de um triângulo lateral\n");
   scanf("%d", &n);

   imprimeTriangulo(n);

   return 0;

}