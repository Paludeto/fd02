/**
 * @file ex05.c
 * @author Gabriel Paludeto
 * @brief 5) Crie uma estrutura representando um ranking. Essa
    estrutura deve conter o nome do jogador e sua pontuação.
    Em seguida, escreva um programa que leia os dados de 5
    jogadores e os armazene em um arquivo utilizando a
    técnica de Dados formatados.
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
    char nome[TAM_NOME];
    int pontuacao;
} Jogador;

int main() {
    
    Jogador jogadores[NUM_JOGADORES];
    FILE *fp;
    char nome[TAM_NOME];

    printf("Digite o nome do arquivo .txt em que deseja escrever os dados\n");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "w");

    if (fp == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Digite os dados de 5 jogadores:\n");

    for (int i = 0; i < NUM_JOGADORES; i++) {
        printf("Jogador %d:\n", i + 1);
        printf("Nome: ");

        fgets(jogadores[i].nome, TAM_NOME, stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = '\0';

        printf("Pontuação: ");
        scanf("%d", &jogadores[i].pontuacao);

        while (jogadores[i].pontuacao < 0) {
            printf("Digite uma pontuação positiva!\n");
            scanf("%d", &jogadores[i].pontuacao);   
        }

        setbuf(stdin, NULL);
    }
    
    for (int i = 0; i < NUM_JOGADORES; i++) {
        fprintf(fp, "%s %d\n", jogadores[i].nome, jogadores[i].pontuacao);
    }
    
    fclose(fp);
    
    return 0;

}