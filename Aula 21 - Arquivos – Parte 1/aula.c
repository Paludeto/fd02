#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 100

int main() {

    FILE *fp = fopen("arquivo.txt", "a");

    char texto[TAM_STRING];

    if (fp == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo\n");
        exit(EXIT_FAILURE);
    } 

    for (int i = 0; i < 5; i++) {

        printf("Digite o nome %d\n", i + 1);
        fgets(texto, TAM_STRING, stdin);
        setbuf(stdin, NULL);

        int resultado = fputs(texto, fp);

        if (resultado == EOF) {
            perror("Erro na gravação\n");
        }

    }

    fclose(fp);

    return 0;

}