#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
}

// Função para posicionar navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar navio vertical
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para criar matriz de habilidade em Cone
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // Lógica para criar formato de cone
            if (linha + coluna >= TAMANHO_HABILIDADE - 1 && 
                linha - coluna <= TAMANHO_HABILIDADE/2 && 
                coluna - linha <= TAMANHO_HABILIDADE/2) {
                habilidade[linha][coluna] = 1;
            } else {
                habilidade[linha][coluna] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade em Cruz
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // Lógica para criar formato de cruz
            if (linha == TAMANHO_HABILIDADE/2 || 
                coluna == TAMANHO_HABILIDADE/2) {
                habilidade[linha][coluna] = 1;
            } else {
                habilidade[linha][coluna] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade em Octaedro
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // Lógica para criar formato de octaedro
            if ((linha == TAMANHO_HABILIDADE/2 || 
                 coluna == TAMANHO_HABILIDADE/2) && 
                (linha + coluna >= TAMANHO_HABILIDADE/2 && 
                 linha + coluna <= TAMANHO_HABILIDADE * 3/2)) {
                habilidade[linha][coluna] = 1;
            } else {
                habilidade[linha][coluna] = 0;
            }
        }
    }
}

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
                       int origem_linha, int origem_coluna) {
    int offset = TAMANHO_HABILIDADE / 2;
    
    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            int tab_linha = origem_linha - offset + linha;
            int tab_coluna = origem_coluna - offset + coluna;
            
            // Verificar limites do tabuleiro
            if (tab_linha >= 0 && tab_linha < TAMANHO_TABULEIRO &&
                tab_coluna >= 0 && tab_coluna < TAMANHO_TABULEIRO) {
                
                // Aplicar área de efeito
                if (habilidade[linha][coluna] == 1) {
                    // Não sobrescrever navios
                    if (tabuleiro[tab_linha][tab_coluna] != 3) {
                        tabuleiro[tab_linha][tab_coluna] = 5;
                    }
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval com Habilidades:\n");
    
    // Imprimir cabeçalho de colunas
    printf("  ");
    for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
        printf("%d ", coluna);
    }
    printf("\n");

    // Imprimir tabuleiro
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        // Imprimir número da linha
        printf("%d ", linha);
        
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    // Inicializar tabuleiro
    inicializarTabuleiro(tabuleiro);
    
    // Posicionar navios
    posicionarNavioHorizontal(tabuleiro, 2, 3);
    posicionarNavioVertical(tabuleiro, 5, 7);
    
    // Criar matrizes de habilidades
    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);
    
    // Aplicar habilidades em diferentes pontos do tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, 4, 4);
    aplicarHabilidade(tabuleiro, habilidadeCruz, 6, 6);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 8, 8);
    
    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);
    
    return 0;
}