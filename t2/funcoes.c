#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"

// ve quanto cada caractere repete
void calculaFreq(int *rec, const char *string) {
    memset(rec, 0, 128 * sizeof(int));
    while(*string) rec[(unsigned char) *(string++)]++;
}

// conta quantos caracteres diferentes tem no arquivo
int countCharDiff(char *string){
    int i = 0;
    unsigned char charTeste;
    int recorrencia[128];
    calculaFreq(recorrencia, string);
    
    for(charTeste = 0; charTeste < 128; charTeste++){
        if(recorrencia[charTeste] > 0){
            printf("%c = %d\n", charTeste, recorrencia[charTeste]);
            i++;
        }
    }
    return i;
}

// vai concatenar para uma variavel so os caracteres e sua quantidade
void prencheContagem(char *string, estrutura *contagem){
    int pos = 0;
    unsigned char charTeste;
    int recorrencia[128];
    calculaFreq(recorrencia, string);

    for(charTeste = 0; charTeste < 128; charTeste++){
        if(recorrencia[charTeste] > 0){
            contagem[pos].caractere = charTeste;
            contagem[pos].quantidade = recorrencia[charTeste];
            pos++;
        }
    }
}
