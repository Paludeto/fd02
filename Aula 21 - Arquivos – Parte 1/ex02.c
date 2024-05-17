/**
 * @file ex02.c
 * @author Gabriel Paludeto
 * @brief 2) Escreva um programa que leia do usuário os nomes de dois
    arquivos texto. Crie um terceiro arquivo texto com o conteúdo dos
    dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do
    segundo).
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
#define NUM_ARQUIVOS 3

int main() {

    char nome1[TAMANHO_NOME], nome2[TAMANHO_NOME], nome3[TAMANHO_NOME];
    char caractere;
    FILE *fp1, *fp2, *fp3;

    printf("Digite o nome do arquivo de texto que você deseja abrir\n");
    fgets(nome1, TAMANHO_NOME, stdin);
    nome1[strcspn(nome1, "\n")] = '\0';

    fp1 = fopen(nome1, "r");

    printf("Digite o nome do segundo arquivo de texto que você deseja abrir\n");
    fgets(nome2, TAMANHO_NOME, stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    fp2 = fopen(nome2, "r");

    printf("Digite o nome do terceiro arquivo de texto que você deseja abrir ou criar\n");
    fgets(nome3, TAMANHO_NOME, stdin);
    nome3[strcspn(nome3, "\n")] = '\0';

    fp3 = fopen(nome3, "w");
    
    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "Erro ao abrir os arquivos!\n");
        exit(EXIT_FAILURE);
    }

    while ((caractere = fgetc(fp1)) != EOF) {
        fputc(caractere, fp3);
    }

    fputc('\n', fp3);

    while ((caractere = fgetc(fp2)) != EOF) {
        fputc(caractere, fp3);
    }

    setbuf(stdin, NULL);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;


}