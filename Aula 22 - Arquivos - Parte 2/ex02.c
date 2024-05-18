/**
 * @file ex02.c
 * @author Gabriel Paludeto
 * @brief 2) Elabore um programa que leia um arquivo binário contendo
    100 números. Mostre na tela a soma desses números.
 * @version 0.1
 * @date 2024-05-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NUMEROS 100
#define TAM_NOME 101

int main() {

    char nome[TAM_NOME];
    int numeros[NUM_NUMEROS];
    double soma = 0;

    printf("Digite o nome do arquivo .bin de que deseja ler os números\n");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
  
    FILE *file = fopen(nome, "rb");

    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);
    }
    
    fread(numeros, sizeof(int), NUM_NUMEROS, file);
    
    fclose(file);
    
    for (int i = 0; i < NUM_NUMEROS; i++) {
        soma += numeros[i];
    }
    
    printf("Soma dos números: %.2f\n", soma);
    
    return 0;

}