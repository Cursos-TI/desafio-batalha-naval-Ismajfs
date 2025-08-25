#include <stdio.h>

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para construir matriz Cone
void construirCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para construir matriz Cruz
void construirCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para construir matriz Octaedro
void construirOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para aplicar matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int matriz[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origemLinha - TAM_HAB / 2 + i;
            int colunaTab = origemColuna - TAM_HAB / 2 + j;

            // Verifica se está dentro dos limites
            if (linhaTab >= 0 && linhaTab < TAM_TAB && colunaTab >= 0 && colunaTab < TAM_TAB) {
                // Aplica habilidade se não for navio
                if (matriz[i][j] == 1 && tabuleiro[linhaTab][colunaTab] != NAVIO)
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
            }
        }
    }
}

int main() {
    // Inicializa tabuleiro com água
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};

    // Posiciona navios fixos
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    tabuleiro[5][5] = NAVIO;
    tabuleiro[6][5] = NAVIO;
    tabuleiro[7][5] = NAVIO;

    // Matrizes de habilidade
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // Construção dinâmica das matrizes
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplicação das habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);       // Cone centrado em (4,4)
    aplicarHabilidade(tabuleiro, cruz, 7, 2);       // Cruz centrada em (7,2)
    aplicarHabilidade(tabuleiro, octaedro, 6, 7);   // Octaedro centrado em (6,7)

    // Exibe tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
