#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 30

int main() {

    FILE *arquivo = fopen("arquivo.dat", "wb"); //write binary

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    char texto[TAM_STRING] = "Hello World em binário\n";
    float salario = 1302.45;
    int vetor[5] = {10, 20, 30, 40, 50};

    fwrite(&salario, sizeof(float), 1, arquivo);
    fwrite(texto, sizeof(char), TAM_STRING, arquivo);
    fwrite(vetor, sizeof(int), 5, arquivo);

    fclose(arquivo);

    return 0;

}