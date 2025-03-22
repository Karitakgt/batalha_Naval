#include <stdio.h>

// Constantes para fácil configuração e leitura
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se há sobreposição
int verifica_sobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha[i]][coluna[i]] == NAVIO) {
            return 1; // Sobreposição detectada
        }
    }
    return 0; // Sem sobreposição
}

// Função para posicionar navio no tabuleiro
void posiciona_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

int main() {
    // Declaração e inicialização do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // === NAVIO HORIZONTAL ===
    int linha_hor[TAMANHO_NAVIO] = {2, 2, 2}; // Linha fixa
    int coluna_hor[TAMANHO_NAVIO] = {1, 2, 3}; // Colunas crescentes

    if (!verifica_sobreposicao(tabuleiro, linha_hor, coluna_hor, TAMANHO_NAVIO)) {
        posiciona_navio(tabuleiro, linha_hor, coluna_hor, TAMANHO_NAVIO);
    } else {
        printf("Erro: Sobreposição detectada no navio horizontal.\n");
    }

    // === NAVIO VERTICAL ===
    int linha_ver[TAMANHO_NAVIO] = {5, 6, 7}; // Linhas crescentes
    int coluna_ver[TAMANHO_NAVIO] = {7, 7, 7}; // Coluna fixa

    if (!verifica_sobreposicao(tabuleiro, linha_ver, coluna_ver, TAMANHO_NAVIO)) {
        posiciona_navio(tabuleiro, linha_ver, coluna_ver, TAMANHO_NAVIO);
    } else {
        printf("Erro: Sobreposição detectada no navio vertical.\n");
    }

    // === NAVIO DIAGONAL PRINCIPAL (↘) ===
    int linha_diag1[TAMANHO_NAVIO] = {0, 1, 2};
    int coluna_diag1[TAMANHO_NAVIO] = {0, 1, 2};

    if (!verifica_sobreposicao(tabuleiro, linha_diag1, coluna_diag1, TAMANHO_NAVIO)) {
        posiciona_navio(tabuleiro, linha_diag1, coluna_diag1, TAMANHO_NAVIO);
    } else {
        printf("Erro: Sobreposição detectada no navio diagonal principal.\n");
    }

    // === NAVIO DIAGONAL SECUNDÁRIA (↙) ===
    int linha_diag2[TAMANHO_NAVIO] = {0, 1, 2};
    int coluna_diag2[TAMANHO_NAVIO] = {9, 8, 7};

    if (!verifica_sobreposicao(tabuleiro, linha_diag2, coluna_diag2, TAMANHO_NAVIO)) {
        posiciona_navio(tabuleiro, linha_diag2, coluna_diag2, TAMANHO_NAVIO);
    } else {
        printf("Erro: Sobreposição detectada no navio diagonal secundária.\n");
    }

    // === EXIBINDO O TABULEIRO ===
    printf("\nTabuleiro Final:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
