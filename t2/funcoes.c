#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"
unsigned char charTeste;
int recorrencia[128];

// ve quanto cada caractere repete
void calculaFreq(int *rec, const char *string) {
    memset(rec, 0, 128 * sizeof(int));
    while(*string) rec[(unsigned char) *(string++)]++;
}

// conta quantos caracteres diferentes tem no arquivo
int countCharDiff(char *string){
    int i = 0;
    calculaFreq(recorrencia, string);
    
    for(charTeste = 0; charTeste < 128; charTeste++){
        if(recorrencia[charTeste] > 0) i++;
    }
    return i;
}

// vai concatenar para uma variavel so os caracteres e sua quantidade
void prencheContagem(char *string, estrutura *contagem){
    int pos = 0;
    calculaFreq(recorrencia, string);

    for(charTeste = 0; charTeste < 128; charTeste++){
        if(recorrencia[charTeste] > 0){
            contagem[pos].caractere = charTeste;
            contagem[pos].quantidade = recorrencia[charTeste];
            pos++;
        }
    }
}

int comparQuants(const void *a, const void *b){
    estrutura *elem1 = (estrutura *)a;
    estrutura *elem2 = (estrutura *)b;
    return elem2->quantidade - elem1->quantidade;
}

int divQuants(estrutura *contagem, int count){
    int half = 0, i = 0;

    while(half < (count / 2)){
        printf("ESTÁ SENDO SOMADO ATÉ A METADE: %c = %d\n", contagem[i].caractere, contagem[i].quantidade);
        half += contagem[i].quantidade;
        i++;
    }
    
    return half;
}