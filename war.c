#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Definições do Tabuleiro (Campo de Jogo)
#define CAMPO_LARGURA 12
#define CAMPO_ALTURA 18

// Matriz do Campo: 0 = Vazio, >0 = Bloco Fixo (tipo de peça)
int Campo[CAMPO_ALTURA][CAMPO_LARGURA];

// Peças (Tetrominós) - Uma lista de 7 peças com suas rotações
// Neste exemplo, usamos apenas uma forma simples (a peça quadrada 'O' e a peça 'I')
// Para um jogo completo, você precisaria de todas as 7 formas e 4 rotações para cada.
char *Pecas[2] = {
    "###.####", // Peça 'I' (4x2)
    "##..##.."  // Peça 'O' (2x2)
};

// Variáveis do Jogo
int PeçaAtual = 0;
int RotaçãoAtual = 0;
int PosX = CAMPO_LARGURA / 2 - 2;
int PosY = 0;
int Pontos = 0;
bool FimDeJogo = false;

// --- FUNÇÕES AUXILIARES ---

// Retorna o valor de um bloco da peça em uma dada rotação (simulada)
int GetBloco(int r, int c, int Peça, int Rotação) {
    // Para simplificar, neste exemplo as peças são 4x4 (max de um tetrominó)
    // O índice da matriz da peça seria: r * 4 + c
    return 1; // Simplificado
}

// Inicializa o Campo de Jogo (paredes e fundo)
void InicializarCampo() {
    for (int y = 0; y < CAMPO_ALTURA; y++) {
        for (int x = 0; x < CAMPO_LARGURA; x++) {
            // Desenha as paredes laterais e o fundo
            if (x == 0 || x == CAMPO_LARGURA - 1 || y == CAMPO_ALTURA - 1) {
                Campo[y][x] = 9; // 9 = Parede
            } else {
                Campo[y][x] = 0; // 0 = Vazio
            }
        }
    }
}

// Desenha o Campo e a Peça no console
void DesenharJogo() {
    // Limpa o console (dependente do SO, 'cls' para Windows, 'clear' para Linux/Mac)
    system("cls || clear");

    printf("--- Tetris em C ---\n");
    printf("Pontos: %d\n", Pontos);

    for (int y = 0; y < CAMPO_ALTURA; y++) {
        for (int x = 0; x < CAMPO_LARGURA; x++) {
            char caractere = ' ';

            if (Campo[y][x] == 9) {
                caractere = '#'; // Parede
            } else if (Campo[y][x] > 0) {
                caractere = '@'; // Bloco fixo
            } else {
                // Desenha a peça atual em queda
                // (Esta lógica é muito simplificada e precisa ser refeita para um jogo real)
                // if (x >= PosX && x < PosX + 4 && y >= PosY && y < PosY + 4 && GetBloco(y - PosY, x - PosX, PeçaAtual, RotaçãoAtual)) {
                //     caractere = '*'; // Bloco da peça caindo
                // } else {
                //     caractere = ' ';
                // }
                 caractere = ' ';
            }
            printf("%c ", caractere);
        }
        printf("\n");
    }

    if (FimDeJogo) {
        printf("\n!!! FIM DE JOGO !!!\n");
    }
}


// --- LOOP PRINCIPAL (JOGO) ---

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    InicializarCampo();
    // Neste exemplo simplificado, o loop principal é apenas para demonstrar
    // a estrutura, sem a lógica de queda e colisão.

    // A lógica de queda e colisão (Colisão/Fixar/Nova Peça/Limpar Linhas)
    // é a parte mais complexa e crucial que precisa ser implementada
    // na função principal do jogo.

    printf("Pressione ENTER para iniciar (ou Ctrl+C para sair)...\n");
    getchar();

    while (!FimDeJogo) {
        //
