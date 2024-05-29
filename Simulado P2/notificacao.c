#include "notificacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Notificacao *criaVetor(int n) {
    
    Notificacao *vetorNotificacoes = malloc(n * sizeof(Notificacao));

    if (vetorNotificacoes == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    return vetorNotificacoes;
}

void recebeNotificacoes(Notificacao **vetorNotificacoes, int *numUsado) {

    int tamanhoVetor = 5;
    *vetorNotificacoes = (Notificacao*)malloc(tamanhoVetor * sizeof(Notificacao));

    if (*vetorNotificacoes == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    while (1) {

        if (*numUsado >= tamanhoVetor) {
            tamanhoVetor += 5; 
            *vetorNotificacoes = realloc(*vetorNotificacoes, tamanhoVetor * sizeof(Notificacao));
            if (*vetorNotificacoes == NULL) {
                fprintf(stderr, "Erro de alocação de memória\n");
                exit(EXIT_FAILURE);
            }
        }

        printf("Digite o nome do país\n");
        fgets((*vetorNotificacoes)[*numUsado].pais, TAM_STRING, stdin);
        (*vetorNotificacoes)[*numUsado].pais[strcspn((*vetorNotificacoes)[*numUsado].pais, "\n")] = '\0';

       
        if (strcmp((*vetorNotificacoes)[*numUsado].pais, "fim") == 0) {  
            break;
        }

        printf("Digite o nome da cidade\n");
        fgets((*vetorNotificacoes)[*numUsado].cidade, TAM_STRING, stdin);
        (*vetorNotificacoes)[*numUsado].cidade[strcspn((*vetorNotificacoes)[*numUsado].cidade, "\n")] = '\0';

        printf("Digite a quantidade de servidores ativos\n");
        scanf("%d", &(*vetorNotificacoes)[*numUsado].serversUp);

        printf("Digite a quantidade de servidores inativos\n");
        scanf("%d", &(*vetorNotificacoes)[*numUsado].serversDown);

        setbuf(stdin, NULL);

        (*numUsado)++;

    }

    return;

}

int calculaRate(Notificacao notificacao) {

    return notificacao.serversUp / notificacao.serversDown;

}