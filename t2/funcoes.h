#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char caractere;
    int quantidade;
}estrutura;

//calcula a frequencia de cada caractere ASCII
void calculaFreq(int *hist, const char *string);
int countCharDiff(char *string);
void prencheContagem(char *string, estrutura *contagem);
