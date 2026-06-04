#include <stdio.h>
#include "jogo.h"

void cabecalho(){
    printf("==============================\n");
    printf("  BEM VINDO AO JOGO DA VELHA  \n");
    printf("==============================\n\n");
}

void registrar_jogadores(Jogador *j1, Jogador *j2){
    printf("Nome do primeiro jogador (X): \n");
    scanf(" %50[^\n]", j1->nome);
    j1->simbolo = 'X';

    printf("Nome do segundo jogador (O): \n");
    scanf(" %50[^\n]", j2->nome);
    j2->simbolo = 'O';
}

void criar_tabuleiro(Tabuleiro *t){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            t->casas[i][j] = ' ';
        }
    }
    t->jogos_restantes = TOTAL_CASAS;
}

void mostrar_tabuleiro(Tabuleiro *t){
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf(" %c | %c | %c \n", t->casas[i][0], t->casas[i][1], t->casas[i][2]);
        if(i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void entrada(Tabuleiro *t, Jogador *atual){
    int linha, coluna, valido, jogou;

    do {
        printf("Vez de %s (%c)\n", atual->nome, atual->simbolo);

        do{
            printf("Linha e coluna (0 a 2): \n");
            valido = (scanf("%d %d", &linha, &coluna) == 2 && linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2);
            limpar_buffer();

            if(!valido) printf("Invalido. Digite dois numeros inteiros entre 0 e 2.\n");
        } while(!valido);

        jogou = fazer_jogada(t, atual, linha, coluna);

        if(!jogou) printf("Posicao ocupada, tente novamente.\n");

    } while(!jogou);
}

int fazer_jogada(Tabuleiro *t, Jogador *atual, int linha, int coluna){
    if(t->casas[linha][coluna] == ' '){
        t->casas[linha][coluna] = atual->simbolo;
        t->jogos_restantes--;
        return 1;
    }

    return 0;
}

char verificar_vitoria(Tabuleiro *t){

    for(int i = 0; i < 3; i++){
        if(t->casas[i][0] != ' ' && t->casas[i][0] == t->casas[i][1] && t->casas[i][1] == t->casas[i][2]) return t->casas[i][0];
        if(t->casas[0][i] != ' ' && t->casas[0][i] == t->casas[1][i] && t->casas[1][i] == t->casas[2][i]) return t->casas[0][i];
    }

    if(t->casas[0][0] != ' ' && t->casas[0][0] == t->casas[1][1] && t->casas[1][1] == t->casas[2][2]) return t->casas[0][0];
    if(t->casas[0][2] != ' ' && t->casas[0][2] == t->casas[1][1] && t->casas[1][1] == t->casas[2][0]) return t->casas[0][2];

    return ' ';
}

void joga(Jogador *j1, Jogador *j2){
    Tabuleiro t;
    criar_tabuleiro(&t);

    Jogador *jogadores[2] = {j1, j2};
    int turno = 0;
    char vencedor;

    do{
        mostrar_tabuleiro(&t);
        entrada(&t, jogadores[turno]);
        vencedor = verificar_vitoria(&t);
        turno = 1 - turno;

    } while(vencedor == ' ' && t.jogos_restantes != 0);

    mostrar_tabuleiro(&t);

    if(vencedor != ' ')
        printf("%s venceu!\n", jogadores[1 - turno]->nome);
    else
        printf("Deu Velha!\n");
}

int main(){

    Jogador j1,j2;

    cabecalho();
    registrar_jogadores(&j1, &j2);
    joga(&j1, &j2);

    return 0;
}