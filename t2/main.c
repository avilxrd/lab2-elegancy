#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(){
    char arq[] = "arquivo.txt";
    int count = 0;
    char c;
    FILE *f = fopen(arq, "r");
    if(f == NULL) printf("erro ao abrir o arquivo");
    else{
        printf("arquivo aberto com sucesso\n");
        while((c = fgetc(f)) != EOF) count++; // conta quantos caracteres tem no arquivo
        fseek(f, 0, SEEK_SET); // volta pro comeco do arquivo
        printf("o arquivo tem %d caracteres\n", count);

        char string[count];
        // laco que passa os caracteres do arquivo para a string + '\0' que fecha a string
        int i = 0;
        while((c = fgetc(f)) != EOF){
            string[i] = c;
            i++;
        }
        string[i] = '\0';
        printf("%s\n", string);

        int countChar = countCharDiff(string);
        printf("o arquivo tem %d caracteres diferentes\n", countChar);

        estrutura contagem[countChar];
        prencheContagem(string, contagem);
        for(int i = 0; i < countChar; i++) printf("%c = %d\n", contagem[i].caractere, contagem[i].quantidade);

    }

    fclose(f);
    return 0;
}