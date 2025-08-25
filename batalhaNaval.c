#include <stdio.h>

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar sobreposição
int verificaSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (diagonal == 1) { // Diagonal crescente
            l += i;
            c += i;
        } else if (diagonal == -1) { // Diagonal decrescente
            l += i;
            c -= i;
        } else if (direcao == 0) { // Horizontal
            c += i;
        } else if (direcao == 1) { // Vertical
            l += i;
        }

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return 0; // Fora dos limites

        if (tabuleiro[l][c] == NAVIO)
            return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar navio
void posicionaNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == -1) {
            l += i;
            c -= i;
        } else if (direcao == 0) {
            c += i;
        } else if (direcao == 1) {
            l += i;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    // Inicializa o tabuleiro com água
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas e orientações dos navios
    int navios[4][4] = {
        {1, 2, 0, 0},  // Horizontal
        {4, 5, 1, 0},  // Vertical
        {0, 0, 0, 1},  // Diagonal crescente
        {0, 9, 0, -1}  // Diagonal decrescente
    };

    // Posiciona os navios com validação
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int direcao = navios[i][2];
        int diagonal = navios[i][3];

        if (verificaSobreposicao(tabuleiro, linha, coluna, direcao, diagonal)) {
            posicionaNavio(tabuleiro, linha, coluna, direcao, diagonal);
        } else {
            printf("Erro ao posicionar navio %d: coordenadas inválidas ou sobreposição.\n", i + 1);
        }
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
