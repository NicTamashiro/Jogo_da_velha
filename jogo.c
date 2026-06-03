#include <stdio.h>

void criar_tabuleiro(char tabuleiro[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void cabecalho(){
    printf("==============================\n");
    printf("  BEM VINDO AO JOGO DA VELHA\n");
    printf("==============================\n\n");
}

void registrar_jogadores(char * player1, char * player2){
    printf("Qual o nome do primeiro jogador: \n");
    scanf(" %50[^\n]", player1);
    printf("Qual o nome do segundo jogador: \n");
    scanf(" %50[^\n]", player2);
}

int main(){

    char tabuleiro[3][3];
    char player1[51];
    char player2[51];

    criar_tabuleiro(tabuleiro);

    cabecalho();

    registrar_jogadores(player1, player2);

    return 0;
}