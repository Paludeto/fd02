#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ATLETAS 5
#define TAM_NOME 101

typedef struct Atleta {
    char nome[TAM_NOME];
    char esporte[TAM_NOME];
    int idade;
    float altura;
} Atleta;

int main() {
    
    Atleta atletas[NUM_ATLETAS];
    char nome[TAM_NOME];
    FILE *fp;

    printf("Digite o nome do arquivo .bin em que deseja escrever os dados\n");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "wb");

    if (fp == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Digite os dados de 5 atletas:\n");

    for (int i = 0; i < NUM_ATLETAS; i++) {

        printf("Atleta %d:\n", i + 1);

        printf("Nome: ");
        fgets(atletas[i].nome, TAM_NOME, stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")] = '\0';

        printf("Esporte: ");
        fgets(atletas[i].esporte, TAM_NOME, stdin);
        atletas[i].esporte[strcspn(atletas[i].esporte, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &atletas[i].idade);

        printf("Altura: ");
        scanf("%f", &atletas[i].altura);

        setbuf(stdin, NULL);

    }
  
    fwrite(atletas, sizeof(Atleta), NUM_ATLETAS, fp);
   
    fclose(fp);
    
    return 0;

}