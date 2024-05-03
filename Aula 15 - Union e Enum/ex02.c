/**
 * @file ex02.c
 * @author Gabriel Paludeto
 * @brief Crie um programa de cadastro que receba, armazene, e
    em seguida, exiba os dados de 5 pessoas.
     Cada pessoa possui: nome, idade, peso, data de nascimento,
    brasileiro ou estrangeiro. Caso seja Brasileiro, armazene o CPF,
    caso estrangeiro, armazene o passaporte.
     Regra: Utilize structs, typedef, union e enum.
 * @version 0.1
 * @date 2024-03-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 21
#define TAM_ARRAY 5

typedef enum Nacionalidade {
    BRASILEIRO,
    ESTRANGEIRO
} Nacionalidade;

typedef union Cadastro {
    int cpf;
    int passaporte;
} Cadastro;

typedef struct Data {
    int dia, mes, ano;
} Data;

typedef struct Pessoa {
    char nome[TAM_MAX];
    int idade;
    Data dataNascimento;
    Nacionalidade nacionalidade;
    Cadastro cadastro;
    float peso;
} Pessoa;

int main() {

    Pessoa pessoas[TAM_ARRAY];

    for (int i = 0; i < TAM_ARRAY; i++) {

        printf("Digite o nome da pessoa de número %d\n", i + 1);
        fgets(pessoas[i].nome, TAM_MAX, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

        printf("Digite a idade de %s\n", pessoas[i].nome);
        scanf("%d", &pessoas[i].idade);

        printf("Digite a data de nascimento da pessoa no formato DD/MM/AAAA\n");
        scanf("%d/%d/%d", &pessoas[i].dataNascimento.dia, &pessoas[i].dataNascimento.mes, &pessoas[i].dataNascimento.ano);
        
        int n;
        do {
            printf("Digite a nacionalidade de %s, 0 para brasileiro e 1 para estrangeiro\n", pessoas[i].nome);
            scanf("%d", &n);
        } while (n != 0 && n != 1);

        if (pessoas[i].nacionalidade == BRASILEIRO) {
            printf("Digite o CPF de %s\n", pessoas[i].nome);
            scanf("%d", &pessoas[i].cadastro.cpf);
        } else {
            printf("Digite o cadastro de %s\n", pessoas[i].nome);
            scanf("%d", &pessoas[i].cadastro.passaporte);
        }
        
        printf("Digite o peso de %s\n", pessoas[i].nome);
        scanf("%f", &pessoas[i].peso);

        setbuf(stdin, NULL);

    }   

    for (int i = 0; i < TAM_ARRAY; i++) {

        printf("Nome: %s\n", pessoas[i].nome);

        if (pessoas[i].nacionalidade == BRASILEIRO) {
            printf("Nacionalidade: BRASILEIRO\n");
            printf("CPF: %d\n", pessoas[i].cadastro.cpf);
        } else {
            printf("Nacionalidade: ESTRANGEIRO\n");
            printf("CPF: %d\n", pessoas[i].cadastro.passaporte);
        }

        printf("Data de nascimento: %02d/%02d/%02d\n", pessoas[i].dataNascimento.dia, pessoas[i].dataNascimento.mes, pessoas[i].dataNascimento.ano);
        printf("Peso: %.2f\n", pessoas[i].peso);

    }

    return 0;

}