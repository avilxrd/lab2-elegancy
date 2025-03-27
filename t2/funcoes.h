#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char caractere;
    int quantidade;
}estrutura;

// para mais informacoes sobre as funcoes - checar o arquivo funcoes.c

void calculaFreq(int *hist, const char *string);
int countCharDiff(char *string);
void prencheContagem(char *string, estrutura *contagem);
int comparQuants(const void *a, const void *b);
int divQuants(estrutura *contagem, int count);