/**
 * @file ex03.c
 * @author Gabriel Paludeto
 * @brief  3) Escreva uma função que receba como parâmetro dois vetores via referência( A e B)
    e o tamanho N. A função deve retornar o ponteiro para um vetor C de tamanho N
    alocado dinamicamente, em que:
    C[i] = A[i] * B[i]
 * @version 0.1
 * @date 2024-05-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int *retornaVetor(int *vetorA, int *vetorB, int n) {
    
    int *vetorC = malloc(n * sizeof(int));

    if (vetorC == NULL) {
        fprintf(stderr, "Alocação de memória falhou\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        vetorC[i] = vetorA[i] * vetorB[i];
    }

    return vetorC;

}

int main() {

    int n;

    printf("Digite o tamanho desejado para seus vetores\n");
    scanf("%d", &n);

    int *vetorA = (int *) malloc(n * sizeof(int));
    int *vetorB = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d do vetor A\n", i + 1);
        scanf("%d", &vetorA[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d do vetor B\n", i + 1);
        scanf("%d", &vetorB[i]);
    }

    int *vetorC = retornaVetor(vetorA, vetorB, n);

    printf("Vetor C:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", vetorC[i]);
    }

    printf("\n");

    free(vetorA);
    free(vetorB);
    free(vetorC);

    return 0;

}