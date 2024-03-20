/**
 * @file ex04.c
 * @author Gabriel Paludeto
 * @brief Faça um programa que controla o consumo de energia dos
    eletrodomésticos de uma casa e:
     Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras),
    potência (real, em kW) e tempo ativo por dia (real, em horas).
     Leia um tempo t (em dias), calcule e mostre o consumo total na casa e
    o consumo relativo de cada eletrodoméstico (consumo/consumo total)
    nesse período de tempo. Apresente este último dado em porcentagem.
 * @version 0.1
 * @date 2024-03-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_NOME 15
#define QUANTIA_ELETRODOMESTICOS 5  

typedef struct Eletrodomestico {
    char nome[TAMANHO_NOME];
    float potenciaKw, horas, consumoKwH;
} Eletrodomestico;

Eletrodomestico *criarEletrodomestico() {

    Eletrodomestico *novoEletrodomestico = (Eletrodomestico *)malloc(sizeof(Eletrodomestico));

    if (novoEletrodomestico == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        return NULL;
    }

    printf("Digite o nome do eletrodoméstico (máximo de 15 caracteres)\n");
    fgets(novoEletrodomestico->nome, TAMANHO_NOME, stdin);
    novoEletrodomestico->nome[strcspn(novoEletrodomestico->nome, "\n")] = '\0';

    printf("Digite a potência em kW do eletroméstico %s\n", novoEletrodomestico->nome);    
    scanf("%f", &novoEletrodomestico->potenciaKw);

    printf("Digite a quantidade de horas que o eletroméstico %s fica ativo\n", novoEletrodomestico->nome);    
    scanf("%f", &novoEletrodomestico->horas);

    setbuf(stdin, NULL);

    novoEletrodomestico->consumoKwH = novoEletrodomestico->potenciaKw * novoEletrodomestico->horas;

    return novoEletrodomestico;

}

void deletarEletrodomestico(Eletrodomestico *eletrodomestico) {

    if (eletrodomestico != NULL) {
        free(eletrodomestico);
    }

}

void mostrarConsumoRelativo(Eletrodomestico *eletrodomesticos[QUANTIA_ELETRODOMESTICOS], float consumoTotal, float dias) {

    for (int i = 0; i < QUANTIA_ELETRODOMESTICOS; i++) {
        float consumo = eletrodomesticos[i]->consumoKwH * dias;
        float percentualConsumo = (consumo / consumoTotal) * 100;
        printf("O consumo relativo de energia do eletrodoméstico %s é de %.2f%%\n", eletrodomesticos[i]->nome, percentualConsumo);
    }

}

int main() {

    float consumoTotal = 0;
    float dias;

    Eletrodomestico *eletrodomesticos[QUANTIA_ELETRODOMESTICOS];

    for (int i = 0; i < QUANTIA_ELETRODOMESTICOS; i++) {
        eletrodomesticos[i] = criarEletrodomestico();
        consumoTotal += eletrodomesticos[i]->consumoKwH;
    }

    printf("Digite a quantidade de dias em que os eletromésticos ficaram ativos\n");
    scanf("%f", &dias);

    consumoTotal *= dias;

    mostrarConsumoRelativo(eletrodomesticos, consumoTotal, dias);

    for (int i = 0; i < QUANTIA_ELETRODOMESTICOS; i++) {
        free(eletrodomesticos[i]);
    }

    return 0;

}