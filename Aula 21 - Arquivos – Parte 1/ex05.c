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
#include <ctype.h>

#define TAMANHO_NOME 21
#define NUM_CARACTERES 26

int ehLetra(char c) {

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 0;
    } else {
        return 1;
    }

}

int main() {

    char caractereAtual;
    char nome[TAMANHO_NOME];
    int contaCaracteres[NUM_CARACTERES] = {0};
    FILE *fp;

    printf("Digite o nome do arquivo de texto que você deseja abrir\n");
    fgets(nome, TAMANHO_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "r");
    
    if (fp == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    while ((caractereAtual = fgetc(fp)) != EOF) {
        if (ehLetra(caractereAtual) == 0) {
            caractereAtual = tolower(caractereAtual);
            contaCaracteres[caractereAtual - 'a']++;
        }
    } 

    printf("Contagem de letras:\n");

    for (int i = 0; i < NUM_CARACTERES; i++) {
        printf("%c: %d\n", 'a' + i, contaCaracteres[i]);
    }

    fclose(fp);

    return 0;

}