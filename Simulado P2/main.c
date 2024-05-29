/**
 * @file simuladop2.c
 * @author Gabriel Paludeto
 * @brief Na tarde de ontem, 06 de dezembro, alguns servidores da Amazon (AWS) pararam de funcionar. Com isso, diversos serviços ficaram indisponíveis. Dentre eles, os servidores da Riot responsáveis pelos jogos League of Legends, Valorant e Wild Rift.
    Você foi convocado em uma missão de emergência para ajudar a identificar os locais das falhas e gerar os relatórios para os técnicos responsáveis por reestabelecer os serviços.

    Para isso, a central da Amazon está recebendo as notificações de falhas ao redor do mundo. Você devera implementar um sistema para salvar e processar essas notificações. Para isso:

    a) (5 pontos) Aloque dinamicamente um vetor de Notificações de tamanho 5. Cada Notificação é uma estrutura que contém:
    * Pais (string tam: 20):
    * Cidade(string tam: 20):
    * Quantidade de Servidores UP - ativos (inteiro)
    * Quantidade de Servidores Down - com problemas (inteiro)

    Os países possíveis são: Brasil, EUA, França, Inglaterra, China e Japão

    b) (10 pontos) Receba os dados de diversas notificações de falhas e vá armazenando neste vetor de Notificações. A cada vez que o tamanho do vetor se tornar insuficiente, realoque seu tamanho aumentando o vetor em 5 unidades.
    Ao receber o valor "fim" como entrada de um pais, o sistema de entradas deverá parar e o vetor tamanho do vetor ajustado ao tamanho exato da quantidade de relatórios.

    c) (5 pontos) Salve os dados em um aquivo BINÁRIO chamado "notifications.dat". Feche o arquivo e libere a memória utilizada pelo vetor;

    d) (5 pontos) Abra o arquivo gerado anteriormente, carregue os dados em um vetor de Relatórios alocado dinamicamente.

    e) (5 pontos) Calcule o total de servidores ativos e com problemas em cada país. Exiba os dados na tela e gere um arquivo MODO TEXTO chamado "report.txt" no seguinte formato:
    PAIS       |  UP |DOWN |  RATE|
    Brasil     |   80|   30|   25%|
    EUA        |  200|   50|   20%|
    França     |   80|    5|    6%|
    Inglaterra |  100|   12|   11%|
    China      |  117|    3|    3%|
    Japão      |   45|    5|   10%| 


    Obs: Caso você tenha problemas com a alocação dinâmica, faça um vetor estático de tamanho 10 e prossiga nos códigos, você perderá os pontos dessa parte mas prosseguirá normalmente com a nota da parte de arquivos.

    Dados de exemplo:


    PAIS       |CIDADE      |UP  |DOWN |
    EUA        |New York    | 100|   30|
    Brasil     |Sao Paulo   |  50|   20|
    Inglaterra |Londres     |  70|    8|
    Brasil     |Brasilia    |  20|    5|
    Brasil     |Fortaleza   |  10|    5|
    Japão      |Tokyo       |  45|    5|
    EUA        |Boston      |  25|    5|
    EUA        |Los Angeles |  50|   10|
    França     |Paris       |  50|    4|
    China      |Pequim      | 117|    3|
    França     |Nice        |  30|    1|
    Londres    |Manchester  |  30|    4|
    EUA        |Orlando     |  25|    5|
 * @version 0.1
 * @date 2024-05-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "notificacao.h"

#define TAM_INICIAL 5

int main() {

    int numUsado = 0;

    Notificacao *vetorNotificacoes = criaVetor(TAM_INICIAL);

    FILE *fp;

    fp = fopen("arquivo.dat", "wb");

    if (fp == NULL) {
        fprintf(stderr, "Erro na alocação dinâmica\n");
        exit(EXIT_FAILURE);
    }

    recebeNotificacoes(&vetorNotificacoes, &numUsado);

    fwrite(vetorNotificacoes, sizeof(Notificacao), numUsado, fp);

    fclose(fp);
    free(vetorNotificacoes);

    Notificacao *relatorios = criaVetor(numUsado);

    fp = fopen("arquivo.dat", "rb");

    if (fp == NULL) {
        fprintf(stderr, "Erro na alocação dinâmica\n");
        exit(EXIT_FAILURE);
    }

    fread(relatorios, sizeof(Notificacao), numUsado, fp);

    fclose(fp);

    fp = fopen("arquivo.txt", "w");

    if (fp == NULL) {
        fprintf(stderr, "Erro na alocação dinâmica\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%-10s\t | %-10s\t | %-10s\t | %-10s\t | %-10s\t | \n", "PAIS", "CIDADE", "UP", "DOWN", "RATE");

    for (int i = 0; i < numUsado; i++) {
        fprintf(fp, "%-10s\t | ", relatorios[i].pais);
        fprintf(fp, "%-10s\t | ", relatorios[i].cidade);
        fprintf(fp, "%-10d\t | ", relatorios[i].serversUp);
        fprintf(fp, "%-10d\t | ", relatorios[i].serversDown);
        fprintf(fp, "%-10d%%\t | \n", calculaRate(relatorios[i]));
    }

    fclose(fp);

    free(relatorios);

    return 0;

}