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

#define TAMANHO_NOME 15
#define QUANTIA_ELETRODOMESTICOS 5  

typedef struct Eletrodomestico {
    char nome[TAMANHO_NOME];
    float potenciaKw, horas, consumoKwH;
} Eletrodomestico;

void mostrarConsumoRelativo(Eletrodomestico eletrodomesticos[QUANTIA_ELETRODOMESTICOS], float consumoTotal, float dias) {

    for (int i = 0; i < QUANTIA_ELETRODOMESTICOS; i++) {
        float consumo = eletrodomesticos[i].consumoKwH * dias;
        float percentualConsumo = (consumo / consumoTotal) * 100;
        printf("O consumo relativo de energia do eletrodoméstico %s é de %.2f%%\n", eletrodomesticos[i].nome, percentualConsumo);
    }

}

int main() {

    float consumoTotal = 0;
    float dias;

    Eletrodomestico eletrodomesticos[QUANTIA_ELETRODOMESTICOS];

    for (int i = 0; i < QUANTIA_ELETRODOMESTICOS; i++) {
        printf("Digite o nome do eletrodoméstico de número %d\n", i + 1);
        fgets(eletrodomesticos[i].nome, TAMANHO_NOME, stdin);
        eletrodomesticos[i].nome[strcspn(eletrodomesticos[i].nome, "\n")] = '\0';

        printf("Digite a potência, em kW, do eletrodoméstico %s\n", eletrodomesticos[i].nome);
        scanf("%f", &eletrodomesticos[i].potenciaKw);

        printf("Digite a quantidade de tempo, em horas, que o eletrodoméstico %s fica ligado por dia\n", eletrodomesticos[i].nome);
        scanf("%f", &eletrodomesticos[i].horas);

        setbuf(stdin, NULL);

        eletrodomesticos[i].consumoKwH = eletrodomesticos[i].horas * eletrodomesticos[i].potenciaKw;

        consumoTotal += eletrodomesticos[i].consumoKwH;
    }

    printf("Digite uma quantidade de dias\n");
    scanf("%f", &dias);
    setbuf(stdin, NULL);

    consumoTotal *= dias;

    mostrarConsumoRelativo(eletrodomesticos, consumoTotal, dias);

    return 0;

}