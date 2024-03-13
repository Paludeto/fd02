/**
 * @file ex03.c
 * @author Gabriel Paludeto
 * @brief Construa uma estrutura aluno com nome, curso e 4 notas,
    média e situação. Leia as informações nome, curso e notas do
    teclado, calcule a média e armazene a situação do aluno.
     media ≥ 7 → Aprovado;
     3 ≤ media < 7 → Exame;
     media < 3 → Reprovado;
 * @version 0.1
 * @date 2024-03-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_NOME 21
#define QUANTIA_NOTAS 4

enum {
    APROVADO,
    EXAME,
    REPROVADO
};

typedef struct Aluno {
    char nome[TAMANHO_NOME];
    float notas[QUANTIA_NOTAS];
    float media;
    int situacao;
} Aluno;

Aluno *criaAluno() {

    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));

    if (novoAluno == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        return NULL;
    }

    printf("Digite o nome do aluno\n");
    fgets(novoAluno->nome, TAMANHO_NOME, stdin);
    novoAluno->nome[strcspn(novoAluno->nome, "\n")] = '\0';
    novoAluno->media = 0;

    for (int i = 0; i < QUANTIA_NOTAS; i++) {
        printf("Digite a nota de número %d\n", i + 1);
        scanf("%f", &novoAluno->notas[i]);
        novoAluno->media += novoAluno->notas[i];
    }

    novoAluno->media = novoAluno->media / QUANTIA_NOTAS;

    if (novoAluno->media >= 7) {
        novoAluno->situacao = APROVADO;
    } else if (novoAluno->media >= 3) {
        novoAluno->situacao = EXAME;
    } else {
        novoAluno->situacao = REPROVADO;
    }

    return novoAluno;

}

void deletaAluno(Aluno *aluno) {

    if (aluno != NULL) {
        free(aluno);
    }

}

void checaSituacao(Aluno *aluno) {
    
    if (aluno->situacao == APROVADO) {
        printf("Aprovado\n");
    } else if (aluno->situacao == EXAME) {
        printf("Exame\n");
    } else {
        printf("Reprovado\n");
    }

}

void imprimeInformacoes(Aluno *aluno) {

    printf("DADOS DO ALUNO\n");
    printf("Nome: %s\n", aluno->nome);
    printf("Média: %.2f\n", aluno->media);
    checaSituacao(aluno);

}

int main() {

    Aluno *aluno = criaAluno();
    imprimeInformacoes(aluno);
    deletaAluno(aluno);


    return 0;

}