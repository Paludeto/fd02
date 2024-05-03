/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @brief Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do atleta, seu esporte, idade e altura. 
 * Agora, escreva um programa que leia os dados de cinco atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho.
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 21
#define TAM_ARRAY 5

typedef struct Atleta {
    char nome[TAM_NOME];
    char esporte[TAM_NOME];
    int idade;
    float altura;
} Atleta;

Atleta *retornaMaisAlto(Atleta atletas[TAM_ARRAY]) {

    float alturaMaxima = atletas[0].altura;
    Atleta *maisAlto;

    for (int i = 0; i < TAM_ARRAY; i++) {
        if (atletas[i].altura > alturaMaxima) {
            maisAlto = &atletas[i];
        }
    }

    return maisAlto;

}

Atleta *retornaMaisVelho(Atleta atletas[TAM_ARRAY]) {

    float idadeMaxima = atletas[0].idade;
    Atleta *maisVelho;

    for (int i = 0; i < TAM_ARRAY; i++) {
        if (atletas[i].idade > idadeMaxima) {
            maisVelho = &atletas[i];
        }
    }

    return maisVelho;

}

void registraAtletas(Atleta atletas[TAM_ARRAY]) {

    for (int i = 0; i < TAM_ARRAY; i++) {

        printf("Digite o nome do atleta número %d\n", i + 1);
        fgets(atletas[i].nome, TAM_NOME, stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")] = '\0';
        
        printf("Digite o esporte do atleta %s\n", atletas[i].nome);
        fgets(atletas[i].esporte, TAM_NOME, stdin);
        atletas[i].esporte[strcspn(atletas[i].esporte, "\n")] = '\0';

        printf("Digite a idade do atleta %s\n", atletas[i].nome);
        scanf("%d", &atletas[i].idade);

        printf("Digite a altura do atleta %s\n", atletas[i].nome);
        scanf("%f", &atletas[i].altura);

        setbuf(stdin, NULL);

    }

}

void exibeAtletas(Atleta atletas[TAM_ARRAY]) {

    for (int i = 0; i < TAM_ARRAY; i++) {

        printf("Nome: %s\n", atletas[i].nome);
        printf("Esporte: %s\n", atletas[i].esporte);
        printf("Idade: %d\n", atletas[i].idade);
        printf("Altura: %.2f\n", atletas[i].altura);

    }

}

void bubbleSort(Atleta atletas[TAM_ARRAY]) {

    for (int i = 0; i < TAM_ARRAY - 1; i++) {
        for (int j = 0; j < TAM_ARRAY - i - 1; j++) {
            if (atletas[j].idade > atletas[j + 1].idade) {
                Atleta temp = atletas[j];
                atletas[j] = atletas[j + 1];
                atletas[j + 1] = temp;
            }
        }
    }

}

int main() {

    Atleta atletas[TAM_ARRAY];
    registraAtletas(atletas);

    Atleta *enderecoMaisAlto = retornaMaisAlto(atletas);
    Atleta *enderecoMaisVelho = retornaMaisVelho(atletas);

    printf("Atleta mais alto: %s\n", enderecoMaisAlto->nome);
    printf("Atleta mais velho: %s\n\n", enderecoMaisVelho->nome);

    printf("Não-sortido: \n");
    exibeAtletas(atletas);
    printf("\n");

    printf("Sortido por idade: \n");
    bubbleSort(atletas);
    exibeAtletas(atletas);

    return 0;

}