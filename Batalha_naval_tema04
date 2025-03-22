#include <stdio.h>

// Constantes para facilitar a leitura do código
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração da matriz representando o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicialização do tabuleiro com valor 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Definindo as coordenadas iniciais para os navios
    // Navio horizontal começa na linha 2, coluna 1
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 1;

    // Navio vertical começa na linha 5, coluna 7
    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;

    // Posicionando o navio horizontal (validando se cabe no tabuleiro)
    if (coluna_navio_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = NAVIO;
            }
        } else {
            printf("Erro: Sobreposição detectada para o navio horizontal.\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Posicionando o navio vertical (validando se cabe no tabuleiro)
    if (linha_navio_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = NAVIO;
            }
        } else {
            printf("Erro: Sobreposição detectada para o navio vertical.\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // Exibindo o tabuleiro
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
