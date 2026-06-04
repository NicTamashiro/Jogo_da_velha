#ifndef JOGO_H
#define JOGO_H

#define MAX_NOME 51
#define TOTAL_CASAS 9

typedef struct {
    char nome[MAX_NOME];
    char simbolo;
} Jogador;

typedef struct {
    char casas[3][3];
    int jogos_restantes;
} Tabuleiro;

void cabecalho();
void registrar_jogadores(Jogador *j1, Jogador *j2);
void criar_tabuleiro(Tabuleiro *t);
void mostrar_tabuleiro(Tabuleiro *t);
void entrada(Tabuleiro *t, Jogador *atual);
int fazer_jogada(Tabuleiro *t, Jogador *atual, int linha, int coluna);
char verificar_vitoria(Tabuleiro *t);
void jogar(Jogador *j1, Jogador *j2);

#endif