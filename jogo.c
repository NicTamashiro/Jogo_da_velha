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

int main(){

    char tabuleiro[3][3];

    criar_tabuleiro(tabuleiro);

    cabecalho();

    return 0;
}