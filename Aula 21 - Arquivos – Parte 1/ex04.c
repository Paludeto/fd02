/**
 * @file ex04.c
 * @author Gabriel Paludeto
 * @brief 4) Crie um programa para calcular e exibir o número de palavras
    contido em um arquivo texto. O usuário deverá informar o nome do
    arquivo.
 * @version 0.1
 * @date 2024-05-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_NOME 21

int main() {

    char nome[TAMANHO_NOME];
    char caractere;
    int contador = 1;
    FILE *fp;

    printf("Digite o nome do arquivo de texto que você deseja abrir\n");
    fgets(nome, TAMANHO_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "r");
    
    if (fp == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    while ((caractere = fgetc(fp)) != EOF) {
        if (caractere == ' ') {
            contador++;
        }
    }

    printf("O número de palavras no arquivo é igual a %d\n", contador);

    fclose(fp);

    return 0;

}