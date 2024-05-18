/**
 * @file ex06.c
 * @author Gabriel Paludeto
 * @brief 6) Considerando a estrutura ranking do exercício anterior,
    escreva um programa que leia o arquivo gerado contendo
    os dados dos 5 jogadores.
 * @version 0.1
 * @date 2024-05-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_JOGADORES 5
#define TAM_NOME 101

typedef struct Jogador {
    char nome[50];
    int pontuacao;
} Jogador;

int main() {
    
    Jogador jogadores[NUM_JOGADORES];
    FILE *fp;
    char nome[TAM_NOME];

    printf("Digite o nome do arquivo .txt em que deseja escrever os dados\n");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "r");

    if (fp == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < NUM_JOGADORES; i++) {
        fscanf(fp, "%s %d", jogadores[i].nome, &jogadores[i].pontuacao);
    }
    
    fclose(fp);
    
    printf("Dados dos jogadores lidos do arquivo:\n");
    for (int i = 0; i < NUM_JOGADORES; i++) {
        printf("Jogador %d:\n", i + 1);
        printf("Nome: %s\n", jogadores[i].nome);
        printf("Pontuação: %d\n", jogadores[i].pontuacao);
    }
    
    return 0;

}