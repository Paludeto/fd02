/**
 * @file ex04.c
 * @author Gabriel Paludeto
 * @brief 4) Considerando a estrutura atleta do exercício anterior, escreva
    um programa que leia um arquivo binário contendo os dados de
    cinco atletas. Calcule e exiba o nome do atleta mais alto e do
    mais velho.
 * @version 0.1
 * @date 2024-05-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ATLETAS 5
#define TAM_NOME 101

typedef struct Atleta {
    char nome[TAM_NOME];
    char esporte[TAM_NOME];
    int idade;
    float altura;
} Atleta;

int main() {
    
    Atleta atletas[NUM_ATLETAS];
    FILE *fp;
    char nome[TAM_NOME];

    printf("Digite o nome do arquivo .bin de que deseja ler os dados\n");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "rb");

    if (fp == NULL) {

        fprintf(stderr, "Erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);

    }
    
    fread(atletas, sizeof(Atleta), NUM_ATLETAS, fp);
    
    fclose(fp);
    
    Atleta *maisAlto = &atletas[0];
    for (int i = 1; i < NUM_ATLETAS; i++) {

        if (atletas[i].altura > maisAlto->altura) {
            maisAlto = &atletas[i];
        }

    }
    
    Atleta *maisVelho = &atletas[0];
    for (int i = 1; i < NUM_ATLETAS; i++) {

        if (atletas[i].idade > maisVelho->idade) {
            maisVelho = &atletas[i];
        }

    }
    
    printf("Atleta mais alto: %s\n", maisAlto->nome);
    printf("Atleta mais velho: %s\n", maisVelho->nome);
    
    return 0;

}