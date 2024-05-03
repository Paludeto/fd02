/**
 * @file ex01.c
 * @author Gabriel Paludeto
 * @date 2024-03-15
 * 
 * 1) Crie uma enumeração representando os meses do ano.
    Agora, escreva um programa que leia um valor inteiro do
    teclado e exiba o nome do mês correspondente e a
    quantidade de dias que ele possui. 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ} Meses;

int main (){

    // Definição de variáveis
    Meses meses;
    int n;
    char arrMeses[12][20] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio",
    "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    do
    {
        printf("Digite o número relativo ao um mês: ");
        scanf("%d", &n);

    } while (n < 1 || n > 12);

    meses = n;
    
    printf("O mês correspondente a %i é %s, ele possui", meses, arrMeses[meses - 1]);

    if (meses == FEV) {
        printf(" 28 dias\n");
    } else if ((meses % 2) == 1) {
        printf(" 31 dias\n");
    } else {
        printf(" 30 dias\n");
    }

    return 0;

}