# Jogo da Velha
 
Jogo da velha para dois jogadores no terminal, escrito em C.
 
---
 
## Estrutura do projeto
 
```
.
├── jogo.c      # Implementação de todas as funções
├── jogo.h      # Structs, constantes e protótipos
└── README.md
```
 
---
 
## Como compilar e executar
 
```bash
gcc jogo.c -o jogo
./jogo
```
 
---
 
## Como jogar
 
1. Informe o nome dos dois jogadores.
2. O jogador 1 usa `X` e o jogador 2 usa `O`.
3. A cada turno, digite a **linha** e a **coluna** da jogada (valores de `0` a `2`), separados por espaço.
O tabuleiro segue a seguinte numeração:
 
```
 col → 0   1   2
linha
  0   [0,0][0,1][0,2]
  1   [1,0][1,1][1,2]
  2   [2,0][2,1][2,2]
```
 
Exemplo de saída:
 
```
 X | O | X
---+---+---
   | X |  
---+---+---
 O |   | X
```
 
---
 
## Estruturas
 
### `Jogador`
```c
typedef struct {
    char nome[51];  // nome do jogador (até 50 caracteres)
    char simbolo;   // 'X' ou 'O'
} Jogador;
```
 
### `Tabuleiro`
```c
typedef struct {
    char casas[3][3];      // grade 3x3
    int jogos_restantes;   // começa em 9, decrementa a cada jogada
} Tabuleiro;
```
 
---
 
## Funções
 
| Função | Descrição |
|---|---|
| `cabecalho()` | Exibe o título do jogo |
| `registrar_jogadores()` | Lê os nomes dos dois jogadores |
| `criar_tabuleiro()` | Inicializa todas as casas com espaço |
| `mostrar_tabuleiro()` | Imprime o tabuleiro no terminal |
| `entrada()` | Lê e valida a jogada do jogador atual |
| `fazer_jogada()` | Aplica a jogada no tabuleiro, retorna `1` se sucesso |
| `verificar_vitoria()` | Retorna o símbolo do vencedor ou `' '` se não houver |
| `joga()` | Loop principal da partida |
 
---
 
## Condições de fim de jogo
 
- **Vitória:** um jogador completa uma linha, coluna ou diagonal.
- **Velha:** todas as 9 casas preenchidas sem vencedor.