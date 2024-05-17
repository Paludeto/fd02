/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @brief 1) Escreva um programa que leia do usuário o nome de um arquivo
    texto. Em seguida, mostre na tela quantas linhas esse arquivo possui.
 * @version 0.1
 * @date 2024-05-16
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
        if (caractere == '\n') {
            contador++;
        }
    }

    printf("O número de linhas no arquivo é igual a %d\n", contador);

    fclose(fp);

    return 0;

}