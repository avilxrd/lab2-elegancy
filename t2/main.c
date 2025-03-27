#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int main(){
    char arq[] = "arquivo.txt";
    int count = 0;
    int recorrencia[128];
    char c;
    unsigned char charTeste;
    FILE *f = fopen(arq, "r");
    if(f == NULL) printf("erro ao abrir o arquivo");
    else{
        printf("arquivo aberto com sucesso\n");
        while((c = fgetc(f)) != EOF) count++; // conta quantos caracteres tem no arquivo
        fseek(f, 0, SEEK_SET); // volta pro comeco do arquivo

        char string[count];

        int i = 0;
        while((c = fgetc(f)) != EOF){
            string[i] = c;
            i++;
        } 

        string[i] = '\0';

        printf("o arquivo tem %d caracteres\n", count);
        
        printf("%s\n", string);

        calcular(recorrencia, string);
        for(charTeste = ' '; charTeste <= '~'; charTeste++)
            printf("%c = %d\n", charTeste, recorrencia[charTeste]);
    }

    fclose(f);
    return 0;
}