/**
 * @file ex03.c
 * @author Gabriel Paludeto
 * @brief 3) Crie um Sistema de Gerenciamento de Bandas seguindo os seguintes
    passos:
     a) Defina uma estrutura que irá representar bandas de música. Essa estrutura deve
    ter o nome da banda, que tipo de música ela toca, o número de integrantes e em que
    posição do ranking essa banda está dentre as suas 5 bandas favoritas;
     b) Crie uma função para preencher as 5 estruturas de bandas criadas no exemplo
    passado. Após criar e preencher, exiba todas as informações das bandas/estruturas.
     c) Crie uma função que peça ao usuário um número de 1 até 5. Em seguida, seu
    programa deve exibir informações da banda cuja posição no seu ranking é a que foi
    solicitada pelo usuário;
     d) Crie uma função que peça ao usuário um tipo de música e exiba as bandas com
    esse tipo de música no seu ranking.
     e) Crie uma função que peça o nome de uma banda ao usuário e diga se ela está
    entre suas bandas favoritas ou não;
     f) Agora junte tudo e crie um menu com as opções de preencher as estruturas e
    todas as opções das questões passadas.
 * @version 0.1
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_STRING 21
#define TAM_ARRAY 5

typedef struct Banda {
    char nome[TAM_STRING];
    char tipoMusica[TAM_STRING];
    int quantiaIntegrantes;
    int posicaoRanking;
} Banda;

void preencheBandas(Banda *bandas, int tamanhoArray) {

    for (int i = 0; i < tamanhoArray; i++) {

        bool nomeRepetido, rankingRepetido;

        do {

            nomeRepetido = false;

            printf("Digite o nome da banda\n");
            fgets(bandas[i].nome, TAM_STRING, stdin);
            bandas[i].nome[strcspn(bandas[i].nome, "\n")] = '\0';

            for (int j = 0; j < i; j++) {
                if (strcasecmp(bandas[i].nome, bandas[j].nome) == 0) {
                    printf("Banda com esse nome já existe\n");
                    nomeRepetido = true;
                    break;
                }
            }

        } while (nomeRepetido);
        
        
        printf("Digite o gênero musical de %s\n", bandas[i].nome);
        fgets(bandas[i].tipoMusica, TAM_STRING, stdin);
        bandas[i].tipoMusica[strcspn(bandas[i].tipoMusica, "\n")] = '\0';

        printf("Digite a quantia de integrantes da banda %s\n", bandas[i].nome);
        scanf("%d", &bandas[i].quantiaIntegrantes);

        do {
            
            rankingRepetido = false;

            printf("Digite o ranking de 1 - 5 da banda %s\n", bandas[i].nome);
            scanf("%d", &bandas[i].posicaoRanking);

            for (int j = 0; j < i; j++) {
                if (bandas[j].posicaoRanking == bandas[i].posicaoRanking) {
                    printf("Digite uma posição válida\n");
                    rankingRepetido = true;
                    break;
                }
            }
            
        } while (bandas[i].posicaoRanking < 1 || bandas[i].posicaoRanking > 5 || rankingRepetido);

        printf("\n");

        setbuf(stdin, NULL);

    }

}

void imprimeBanda(Banda *banda) {

    printf("Nome da banda: %-24s || ", banda->nome);
    printf("Gênero musical: %-14s || ", banda->tipoMusica);
    printf("Quantidade de integrantes: %2d || ", banda->quantiaIntegrantes);
    printf("Posição no ranking: %d\n\n", banda->posicaoRanking);

}

void imprimeBandas(Banda *bandas, int tamanhoArray) {

    for (int i = 0; i < tamanhoArray; i++) {
        imprimeBanda(&bandas[i]);
    }

}

void buscaRanking(Banda *bandas, int tamanhoArray) {

    int posicao;

    do {
        printf("Digite uma posição a ser buscada\n\n");
        scanf("%d", &posicao);
    } while (posicao < 1 || posicao > 5);

    for (int i = 0; i < tamanhoArray; i++) {
        if (posicao == bandas[i].posicaoRanking) {
            imprimeBanda(&bandas[i]);
        }
    }

}

void buscaTipo(Banda *bandas, int tamanhoArray) {

    bool encontrado = false;
    char tipo[TAM_STRING];

    printf("Digite o tipo musical a ser buscado\n\n");
    fgets(tipo, TAM_STRING, stdin);
    tipo[strcspn(tipo, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < tamanhoArray; i++) {
        if (strcasecmp(tipo, bandas[i].tipoMusica) == 0) {
            imprimeBanda(&bandas[i]);
            encontrado = true;
        }
    }

    if (!encontrado) {
        printf("Tipo musical não encontrado\n\n");
    }

}

void buscaNome(Banda *bandas, int tamanhoArray) {

    bool encontrado = false;
    char nome[TAM_STRING];

    printf("Digite o nome da banda a ser buscado\n\n");
    fgets(nome, TAM_STRING, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < tamanhoArray; i++) {
        if (strcasecmp(nome, bandas[i].nome) == 0) {
            imprimeBanda(&bandas[i]);
            encontrado = true;
        }
    }

    if (!encontrado) {
        printf("Banda não encontrada\n\n");
    }

}

int main() {

    Banda bandas[TAM_ARRAY];
    int opcao = 0;
    bool preenchido = false;

    do {

        printf("Escolha uma opção:\n");
        printf("1 - Preencher bandas\n");
        printf("2 - Buscar por ranking\n");
        printf("3 - Buscar por gênero\n");
        printf("4 - Buscar por nome\n");
        printf("5 - Exibir todas as bandas\n");
        printf("6 - Sair\n\n");

        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch (opcao) {

            case 1:
                preencheBandas(bandas, TAM_ARRAY);
                preenchido = true;
                break;
            case 2:
                if (preenchido) {
                    buscaRanking(bandas, TAM_ARRAY);
                } else {
                    printf("Preencha as bandas!\n\n");
                }
                break;
            case 3:
                if (preenchido) {
                    buscaTipo(bandas, TAM_ARRAY);
                } else {
                    printf("Preencha as bandas!\n");
                }
                break;
            case 4:
                if (preenchido) {
                    buscaNome(bandas, TAM_ARRAY);
                } else {
                    printf("Preencha as bandas!\n\n");
                }
                break;
            case 5:
                if (preenchido) {
                    imprimeBandas(bandas, TAM_ARRAY);
                } else {
                    printf("Preencha as bandas!\n\n");
                }
                break;
            case 6:
                opcao = 6;
                break;
            default:
                printf("Digite uma opção válida\n");
                break;
        }

    } while (opcao != 6);

    return 0;

}