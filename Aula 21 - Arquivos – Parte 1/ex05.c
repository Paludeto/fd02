/**
 * @file ex05.c
 * @author Gabriel Paludeto
 * @brief 5) Elabore um programa para calcular e exibir o número de
    vezes que cada letra ocorre dentro de um arquivo texto.
    Ignore as letras com acento. O usuário deverá informar o
    nome do arquivo.
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
    char caractereAtual, caractereBuscado;
    int contador = 0;
    FILE *fp;

    printf("Digite o nome do arquivo de texto que você deseja abrir\n");
    fgets(nome, TAMANHO_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o caractere a ser buscado\n");
    scanf("%c", &caractereBuscado);

    fp = fopen(nome, "r");
    
    if (fp == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    while ((caractereAtual = fgetc(fp)) != EOF) {
        if (caractereAtual == caractereBuscado) {
            contador++;
        }
    }

    printf("O número de caracteres '%c' no arquivo é igual a %d\n", caractereBuscado, contador);

    fclose(fp);

    return 0;

}