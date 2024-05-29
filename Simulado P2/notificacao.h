#ifndef NOTIFICACAO_H
#define NOTIFICACAO_H

#define TAM_STRING 20

typedef struct {
    char pais[TAM_STRING];
    char cidade[TAM_STRING];
    int serversUp, serversDown;
} Notificacao;

Notificacao *criaVetor(int n);
void recebeNotificacoes(Notificacao **vetorNotificacoes, int *numUsado);
int calculaRate(Notificacao notificacao);

#endif