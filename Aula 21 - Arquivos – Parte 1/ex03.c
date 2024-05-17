/**
 * @file ex03.c
 * @author Gabriel Paludeto 
 * @brief 
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

int main() {

    char caractere;
    char nome1[TAMANHO_NOME];
    char nome2[TAMANHO_NOME];
    FILE *fp1, *fp2;

    printf("Digite o nome do arquivo a ser aberto\n");
    fgets(nome1, TAMANHO_NOME, stdin);
    nome1[strcspn(nome1, "\n")] = '\0';

    printf("Digite o nome do arquivo destino\n");
    fgets(nome2, TAMANHO_NOME, stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    fp1 = fopen(nome1, "r");
    fp2 = fopen(nome2, "w");

    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "Erro ao abrir arquivos!\n");
        exit(EXIT_FAILURE);
    }

    while ((caractere = fgetc(fp1)) != EOF) {
        fputc(toupper(caractere), fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;

}