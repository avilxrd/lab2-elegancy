#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CARTAS_BARALHO 52 //numero máximo de cartas em um baralho
#define NUM_PILHAS 7      //numero de pilhas de jogo
#define MAX_CARTAS 13     //maximo de cartas em uma pilha

//estrutura da carta
typedef struct{
    int valor;
    int naipe;
    bool visivel;
}Carta;

//funcoes de inicializacao

//inicializa com 0 qualquer pilha de cartas
void inicializa_pilha(int tamanho_pilha, Carta pilha[tamanho_pilha]){
    for (int i=0; i<tamanho_pilha; i++){
        pilha[i].valor = 0;
        pilha[i].naipe = 0;
        pilha[i].visivel = false;
    }
}

void preenche_baralho(Carta *baralho){
    for (int i=0; i<NUM_PILHAS; i++){
        for (int j=0; j<MAX_CARTAS; j++){
            baralho[i].naipe = i;
            baralho[i].valor = j;
            baralho[i].visivel = true;
        }
    }
}

void trocar_cartas(Carta *a, Carta *b){
    Carta temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void embaralhar(Carta *baralho){
    srand(time(NULL));
    for (int i=0; i<CARTAS_BARALHO; i++){
        int random = rand()%52;
        trocar_cartas(&baralho[i], &baralho[random]);
    }
}

void distribuir_cartas(Carta *baralho, Carta pilhas_jogo[NUM_PILHAS][MAX_CARTAS]){
    int contador=0;
    
    for (int i=0; i<NUM_PILHAS; i++){
        for (int j=0; j<=i; j++){
            pilhas_jogo[i][j] = baralho[contador];
            baralho[contador].valor = 0;
            baralho[contador].visivel = false;
            contador++; 
        }
    }
}

void inicializa_jogo(Carta baralho[CARTAS_BARALHO], Carta pilhas_jogo[NUM_PILHAS][MAX_CARTAS], Carta pilhas_finais[4][MAX_CARTAS]){
    for (int i=0; i<NUM_PILHAS; i++) inicializa_pilha(MAX_CARTAS, pilhas_jogo[i]); //inicializa com 0 as pilhas de jogo
    for (int i=0; i<4; i++) inicializa_pilha(MAX_CARTAS, pilhas_finais[i]);        //inicializa com 0 as pilhas finais
    preenche_baralho(baralho);
    embaralhar(baralho);
    distribuir_cartas(baralho, pilhas_jogo);
}

//funcoes de processamento

//selecionar uma instrução a ser seguida
int selecionar_jogada(Carta baralho[CARTAS_BARALHO], Carta descarte[CARTAS_BARALHO]){
    
    //verificar se alguma carta do descarte esta visivel
    bool visivel=false;
    for (int i=0; i<CARTAS_BARALHO; i++){
        if (descarte[i].visivel == true){
            visivel = true;
            break;
        }
    }

    //verifica se o baralho esta vazio
    bool baralho_vazio=false;
    for (int i=0; i<CARTAS_BARALHO; i++){
        if (baralho[i].valor != 0) baralho_vazio = true;
    }

    printf("\nSelecione a sua jogada!");
    printf("\n(1-7) Selecionar uma pilha");
    printf("\t(8) Comprar do Baralho");
    
    if (visivel == true) printf("\t(9) Pegar do baralho");
    if (baralho_vazio == true) printf("\t(10) Restituir baralho");

}

//funcoes da interface
void mostra_pilhas_jogo(Carta pilhas_jogo[NUM_PILHAS][MAX_CARTAS]){
    for (int i=0; i<NUM_PILHAS; i++){
        printf("\nPilha %d: ", i+1);
        for (int j=0; j<MAX_CARTAS; j++){
            if (pilhas_jogo[i][j].visivel == true) printf("%d%d ", pilhas_jogo[i][j].valor, pilhas_jogo[i][j].naipe);
            else printf("[ ] ");
        }
    }
    printf("\n\n");
}

int main(){
    Carta baralho[CARTAS_BARALHO]; 
    Carta pilhas_jogo[NUM_PILHAS][MAX_CARTAS];
    Carta pilhas_finais[4][MAX_CARTAS];

    inicializa_jogo(baralho, pilhas_jogo, pilhas_finais);
    mostra_pilhas_jogo(pilhas_jogo);

}
