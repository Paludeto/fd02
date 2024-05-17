#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 30

int main() {

    FILE *arquivo = fopen("arquivo.dat", "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    char texto[TAM_STRING];
    float salario;
    int vetor[5];

    fread(&salario, sizeof(float), 1, arquivo);
    fread(texto, sizeof(char), TAM_STRING, arquivo);
    fread(vetor, sizeof(int), 5, arquivo);

    printf("Salário: %.2f\n", salario);
    printf("Texto: %s", texto);
    printf("Vetor: ");

    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    fclose(arquivo);

    return 0;

}