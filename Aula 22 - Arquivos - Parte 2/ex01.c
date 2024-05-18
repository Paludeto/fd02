/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @brief 1) Faça um programa que gere 100 números aleatórios. Esse
    programa deverá, em seguida,armazenar esses números em um
    arquivo binário.
 * @version 0.1
 * @date 2024-05-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_NUMEROS 100
#define TAM_NOME 101

int main() {
   
    int numeros[NUM_NUMEROS];
    char nome[TAM_NOME];
    FILE *fp;

    srand(time(NULL));

    for (int i = 0; i < NUM_NUMEROS; i++) {
        numeros[i] = rand() % 100;
    }

    printf("Digite o nome do arquivo .bin em que você vai escrever\n");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    fp = fopen(nome, "wb");

    if (fp == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);
    }
    
    fwrite(numeros, sizeof(int), NUM_NUMEROS, fp);
    
    fclose(fp);
    
    return 0;

}