/**
 * @file ex06.c
 * @author Gabriel Paludeto
 * @brief  6) Elabore um programa no qual o usuário informe o nome
    de um arquivo texto e uma palavra, e o programa informe o
    número de vezes que aquela palavra aparece
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

#define TAMANHO_STRING 100
#define TAMANHO_BUFFER 1024

int main() {

    char nome[TAMANHO_STRING];
    char palavra[TAMANHO_STRING];
    char linha[1024];
    int contador = 0;
    FILE *fp;

    printf("Digite o nome do arquivo de texto que você deseja abrir\n");
    fgets(nome, TAMANHO_STRING, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite a palavra a ser buscada no arquivo\n");
    fgets(palavra, TAMANHO_STRING, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    fp = fopen(nome, "r");
    
    if (fp == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(linha, sizeof(linha), fp) != NULL) {

        int contadorPalavra = 0;
        char *pos = linha;

        //strstr() retorna um ponteiro para a primeira ocorrência da palavra na linha
        //itera até que não haja a palavra na linha
        while ((pos = strstr(pos, palavra)) != NULL) {
            contadorPalavra++;
            pos += strlen(palavra);
        }

        contador += contadorPalavra;

    }

    printf("O número de vezes em que a palavra '%s' aparece é igual a %d\n", palavra, contador);

    setbuf(stdin, NULL);
    fclose(fp);

    return 0;

}