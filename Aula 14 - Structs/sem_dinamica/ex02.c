/**
 * @file ex02.c
 * @author Gabriel Paludeto
 * @brief Escreva um trecho de código para fazer a criação dos
    novos tipos de dados conforme solicitado abaixo:
     Horário: composto de hora, minutos e segundos.
     Data: composto de dia, mês e ano.
     Compromisso: local, horário e texto que descreve o
    compromisso.
 * @version 0.1
 * @date 2024-03-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 101

typedef struct Horario {
    int hora, minutos, segundos;
} Horario;

typedef struct Data {
    int dia, mes, ano;
} Data;

typedef struct Compromisso {
    char local[TAMANHO_MAXIMO];
    char descricao[TAMANHO_MAXIMO];
    Horario horario;
    Data data;
} Compromisso;

//sem malloc
int main() {

    Compromisso novoCompromisso;
    

    printf("COMPROMISSO\n");

    printf("Digite a descrição\n");
    fgets(novoCompromisso.descricao, TAMANHO_MAXIMO, stdin);
    novoCompromisso.descricao[strcspn(novoCompromisso.descricao, "\n")] = '\0';

    printf("Digite o local:\n");
    fgets(novoCompromisso.local, TAMANHO_MAXIMO, stdin);
    novoCompromisso.local[strcspn(novoCompromisso.local, "\n")] = '\0';

    printf("Digite a hora no formato HH:MM:SS\n");
    scanf("%d:%d:%d", &novoCompromisso.horario.hora, &novoCompromisso.horario.minutos, &novoCompromisso.horario.segundos);

    printf("Digite a data no formato DD/MM/AAAA\n");
    scanf("%d/%d/%d", &novoCompromisso.data.dia, &novoCompromisso.data.mes, &novoCompromisso.data.ano);

    printf("Descrição: %s\n", novoCompromisso.descricao);
    printf("Local: %s\n", novoCompromisso.local);
    printf("Horário: %02d:%02d:%02d\n", novoCompromisso.horario.hora, novoCompromisso.horario.minutos, novoCompromisso.horario.segundos);
    printf("Data: %02d/%02d/%04d\n", novoCompromisso.data.dia, novoCompromisso.data.mes, novoCompromisso.data.ano);

    return 0;

}