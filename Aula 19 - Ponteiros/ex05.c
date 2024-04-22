/**
 * @file ex05.c
 * @author Gabriel Paludeto
 * @brief Elabora uma função que receba duas strings como parâmetros e
    verifique se a segunda string está dentro da primeira. Para isso, utilize
    apenas aritmética de ponteiros.
 * @version 0.1
 * @date 2024-04-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO 21

bool isSubstring(char *string1, char *substring);

int main() {

    char string1[TAMANHO];
    char substring[TAMANHO];

    printf("Digite o valor da string principal\n");
    fgets(string1, TAMANHO, stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Digite o valor da substring que deseja verificar\n");
    fgets(substring, TAMANHO, stdin);
    substring[strcspn(substring, "\n")] = '\0';

    setbuf(stdin, NULL);

    if (isSubstring(string1, substring)) {
        printf("A string %s está contida em %s\n", substring, string1);
    } else {
        printf("A string %s não está contida em %s\n", substring, string1);
    }

    return 0;

}

bool isSubstring(char *string1, char *substring) {

    if (strlen(substring) > strlen(string1)) {
        return false;
    }

    while (*string1 != '\0') {

        char *p1 = string1;
        char *p2 = substring;

        while (tolower(*p1) == tolower(*p2) && *p2 != '\0') {
            p1++;
            p2++;
        }

        if (*p2 == '\0') {
            return true;
        }

        string1++;
    }

    return false;

}