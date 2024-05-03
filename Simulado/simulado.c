/**
 * @file simulado.c
 * @author Gabriel Paludeto
 * @brief Você foi contratado pela Riot Games para elaborar partes do sistema sistema de Ranking do League of Legends. Para isso:

    a) Defina um tipo e estrutura para salvar os dados de jogadores para um Ranking.
    Cada jogador possui: nome, vitórias, derrotas, tier(nível) e pontos.

    Os tiers são: Bronze, Prata, Ouro, Platina, Diamante e Desafiante. Para organizar os níveis utilize uma enumeração.

    b) Receba do teclado e armazene os dados de 6 jogadores. Não devem ser permitidos valores negativos, novos valores devem ser solicitados caso necessário.

    c) Exiba uma tabela alinhada com o nome e a taxa de vitórias (winrate) de cada jogador
    winrate = vitórias / (vitórias+derrotas) * 100.
    Cada calculo deve ser feito por meio de uma função adicional que recebe o número de vitórias e derrotas via cópia e retorna o winrate.

    d) Exiba uma tabela com os líderes (maior número de pontos) de cada um dos níveis. Para isso, faça uma função extra que receba um tier e retorne uma estrutura do tipo Jogador com os dados do líder.

    e) Faça a busca de um jogador pelo nome digitado. A busca deve ser feita por uma função adicional que recebe o nome e retorna os dados de vitórias, derrotas, tier e pontos via referência.

    f) Utilizando uma função recursiva, calcule a soma de todas as partidas (vitórias e derrotas) de todos os jogadores.

    Cada um dos itens de B a E deve ser implementada em uma função diferente.
    Não é permitido o uso de variáveis globais.
    Nas funções extras, caso necessário, utilize parâmetros adicionais.

    Texto de resposta Questão 1
 * @version 0.1
 * @date 2024-04-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_STRING 21
#define TAMANHO_ARRAY 6

typedef enum {BRONZE = 1, PRATA, OURO, PLATINA, DIAMANTE, DESAFIANTE, NIVEL_INVALIDO} Tier;

typedef struct Player {
    char nome[TAMANHO_STRING];
    int vitorias, derrotas, pontos;
    Tier nivel;
} Player;

void recebeJogadores(Player jogadores[TAMANHO_ARRAY]) {

    for (int i = 0; i < TAMANHO_ARRAY; i++) {

        printf("Digite o nome do jogador de número %d\n", i + 1);
        fgets(jogadores[i].nome, TAMANHO_STRING, stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = '\0';

        printf("Digite o número de vitórias de %s\n", jogadores[i].nome);
        scanf("%d", &jogadores[i].vitorias);

        while (jogadores[i].vitorias < 0) {
            printf("Digite um número não-negativo de vitórias\n");
            scanf("%d", &jogadores[i].vitorias);
        }

        printf("Digite o número de derrotas de %s\n", jogadores[i].nome);
        scanf("%d", &jogadores[i].derrotas);

        while (jogadores[i].derrotas < 0) {
            printf("Digite um número não-negativo de derrotas\n");
            scanf("%d", &jogadores[i].derrotas);
        }

        printf("Digite o nível (tier) do jogador %s\n", jogadores[i].nome);
        printf("1 - BRONZE\n2 - PRATA\n3 - OURO\n4 - PLATINA\n5 - DIAMANTE\n6 - DESAFIANTE\n");

        scanf("%d", &jogadores[i].nivel);

        while (jogadores[i].nivel < 1 || jogadores[i].nivel > 6) {
            printf("Digite um valor entre 1 e 6\n");
            scanf("%d", &jogadores[i].nivel);
        }

        printf("Digite o número de pontos de %s\n", jogadores[i].nome);
        scanf("%d", &jogadores[i].pontos);

        while (jogadores[i].pontos < 0) {
            printf("Digite um número não-negativo de pontos\n");
            scanf("%d", &jogadores[i].pontos);
        }

        setbuf(stdin, NULL);

    }

}

float calculaWinRate(Player jogador) {

    return (float) jogador.vitorias / (jogador.vitorias + jogador.derrotas) * 100;

}

void mostraElo(Player jogador) {
    
    printf("Elo: ");
    switch (jogador.nivel) {
        case BRONZE:
            printf("BRONZE |\t");
            break;
        case PRATA: 
            printf("PRATA |\t");
            break;
        case OURO:
            printf("OURO |\t");
            break;
        case PLATINA: 
            printf("PLATINA |\t");
            break;
        case DIAMANTE: 
            printf("DIAMANTE |\t");
            break;
        case DESAFIANTE:
            printf("DESAFIANTE |\t");
            break;
        default:
            break;
    }

}

void exibeJogador(Player jogador) {

    printf("Nome: %-5s |\t", jogador.nome);
    mostraElo(jogador);
    printf("Vitórias: %-5d |\t", jogador.vitorias);
    printf("Derrotas: %-5d |\t", jogador.derrotas);
    printf("Pontos: %-5d |\t", jogador.pontos);
    printf("Win-rate: %-5.2f%% |\t\n", calculaWinRate(jogador));

}

void exibeJogadores(Player jogadores[TAMANHO_ARRAY]) {

    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        exibeJogador(jogadores[i]);
    }

}

void tabelaWinRate(Player jogadores[TAMANHO_ARRAY]) {

    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Nome: %-10s |\t", jogadores[i].nome);
        printf("Win-rate: %-10.2f%% |\t\n", calculaWinRate(jogadores[i]));
    }

}

Player retornaLider(Tier nivel, Player jogadores[TAMANHO_ARRAY]) {

    Player lider;
    bool encontrado = false;

    for (int i = 0; i < TAMANHO_ARRAY; i++) {

        if (jogadores[i].nivel == nivel) {
            lider = jogadores[i];
            encontrado = true;
        }

    }

    if (encontrado) {
        for (int j = 0; j < TAMANHO_ARRAY; j++) {
            if ((jogadores[j].pontos > lider.pontos) && (jogadores[j].nivel == nivel)) {
                lider = jogadores[j];
            }
        }

        return lider;

    } else {
        printf("Jogador não encontrado\n");
        Player naoEncontrado;
        naoEncontrado.nivel = NIVEL_INVALIDO;
        return naoEncontrado;
    }

} 

void retornaLideres(Player jogadores[TAMANHO_ARRAY]) {

      for (int i = BRONZE; i <= DESAFIANTE; i++) {
        if (retornaLider(i, jogadores).nivel != NIVEL_INVALIDO) {
            Player lider = retornaLider(i, jogadores);
            exibeJogador(lider);
        }
    }

}

void buscaJogador(Player jogadores[TAMANHO_ARRAY], Player *jogadorReferencia, char nomeBuscado[TAMANHO_STRING]) {

    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        if (strcmp(jogadores[i].nome, nomeBuscado) == 0) {
            strcpy(jogadorReferencia->nome, jogadores[i].nome);
            jogadorReferencia->vitorias = jogadores[i].vitorias;
            jogadorReferencia->derrotas = jogadores[i].derrotas;
            jogadorReferencia->pontos = jogadores[i].pontos;
            jogadorReferencia->nivel = jogadores[i].nivel;
        }
    }

}

int somaPartidas(int n, Player jogadores[TAMANHO_ARRAY]) {

    if (n == 0) {
        return jogadores[n].derrotas + jogadores[n].vitorias;
    } else {
        return jogadores[n].derrotas + jogadores[n].vitorias + somaPartidas(n - 1, jogadores);
    }

}

int main() {

    Player jogadores[TAMANHO_ARRAY];
    Player jogadorGenerico = {"", 0, 0, 0, NIVEL_INVALIDO};
    Player *jogadorReferencia = &jogadorGenerico;
    char nomeBuscado[TAMANHO_STRING];

    recebeJogadores(jogadores);
    tabelaWinRate(jogadores);
    retornaLideres(jogadores);

    printf("Digite o nome do jogador a ser buscado\n");
    fgets(nomeBuscado, TAMANHO_STRING, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';
    setbuf(stdin, NULL);

    buscaJogador(jogadores, jogadorReferencia, nomeBuscado);

    if (jogadorReferencia->nivel != NIVEL_INVALIDO) {
        exibeJogador(*jogadorReferencia);
    } else {
        printf("Jogador não encontrado\n");
    }
    
    int totalPartidas = somaPartidas(TAMANHO_ARRAY, jogadores);
    printf("Total de partidas: %d\n", totalPartidas);

    return 0;

}