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

    Horario novoHorario;
    novoHorario.hora = 20;
    novoHorario.minutos = 42;
    novoHorario.segundos = 42;

    Data novaData;
    novaData.dia = 01;
    novaData.mes = 02;
    novaData.ano = 2003;

    Compromisso novoCompromisso;
    strncpy(novoCompromisso.local, "UTFPR", TAMANHO_MAXIMO);
    strncpy(novoCompromisso.descricao, "Um compromisso", TAMANHO_MAXIMO);
    novoCompromisso.horario = novoHorario;
    novoCompromisso.data = novaData;

    printf("COMPROMISSO\n");
    printf("Local: %s\n", novoCompromisso.local);
    printf("Descrição: %s\n", novoCompromisso.descricao);
    printf("Horário: %d:%d:%d\n", novoCompromisso.horario.hora, novoCompromisso.horario.minutos, novoCompromisso.horario.segundos);
    printf("Data: %02d/%02d/%04d\n", novoCompromisso.data.dia, novoCompromisso.data.mes, novoCompromisso.data.ano);

    return 0;

}