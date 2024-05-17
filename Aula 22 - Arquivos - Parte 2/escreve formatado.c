#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 30

int main() {

    FILE *arquivo = fopen("arquivo.dat", "wb"); 

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    char texto[TAM_STRING] = "Hello World\n";
    float salario = 1302.45;
    int vetor[5] = {10, 20, 30, 40, 50};

    fprintf(arquivo, "%s", texto);
    fprintf(arquivo, "%f\n", salario);
    for (int i = 0; i < 5; i++) {
        fprintf(arquivo, "%d ", vetor[i]);
    }

    fprintf(arquivo, "\n");

    fclose(arquivo);

    return 0;

}