#include <stdio.h>

int main(){

    // Declaração das variáveis para o jogo de Batalha Naval
    int tabuleiro [10] [10]; // tabuleiro com 10 posições
    int linha;
    int coluna;
    int navio1[3] = {3, 3, 3};
    int navio2 [3] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linha_h = 2, coluna_h = 4; // início do navio 1 (horizontal)
    int linha_v = 5, coluna_v = 7; // início do navio 2 (vertical)

    // Inicializa o tabuleiro com água (0)

    for (int linha = 0; linha < 10; linha++){
        for (int coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Posição dos navios 1 e 2 (horizontal e vertical)
    if (coluna_h + 3 <= 10){
        for (int i = 0; i < 3; i++){
            tabuleiro[linha_h][coluna_h + i] = navio1[i];
        }
    }

    if (linha_h + 3 <= 10){
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_v + i][coluna_v] == 0) {
                tabuleiro[linha_v + i][coluna_v] = navio2[i];
            }
        }
    }


    // Exibindo o Tabuleiro

    printf("\n ==== TABULEIRO BATALHA NAVAL ==== \n");
    printf(" \n ");
    for (int linha = 0; linha < 10; linha++){
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("[%d]", tabuleiro[linha][coluna]);
        }
        printf("\n");  // Quebra de linha ao final de cada linha da matriz
    }

    


    
    return 0;

}