#include <stdlib.h>  // Para usar a função abs()
#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para criar matriz de habilidade CONE
void criarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= i && j < TAM_HABILIDADE - i) {
                matriz[i][j] = 1; // Área do cone
            } else {
                matriz[i][j] = 0; // Fora do cone
            }
        }
    }
}

// Função para criar matriz de habilidade CRUZ
void criarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = 1; // Linha ou coluna central
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade OCTAEDRO
void criarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int dist_i = abs(i - centro);
            int dist_j = abs(j - centro);
            if (dist_i + dist_j <= centro) {
                matriz[i][j] = 1; // Dentro do octaedro
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para aplicar habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                      int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                      int centro_linha, int centro_coluna) {
    int offset = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tab_i = centro_linha - offset + i;
            int tab_j = centro_coluna - offset + j;
            
            // Verifica se está dentro do tabuleiro
            if (tab_i >= 0 && tab_i < TAM_TABULEIRO && 
                tab_j >= 0 && tab_j < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[tab_i][tab_j] = HABILIDADE;
                }
            }
        }
    }
}

// Função para exibir matriz de habilidade
void exibirHabilidade(int matriz[TAM_HABILIDADE][TAM_HABILIDADE], const char* nome) {
    printf("\n=== MATRIZ %s ===\n", nome);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para exibir tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n=== TABULEIRO COM HABILIDADES ===\n");
    printf("(0 = Agua, 3 = Navio, 5 = Habilidade)\n\n");
    
    printf("    ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n    ");
    for (int j = 0; j < TAM_TABULEIRO * 2; j++) {
        printf("-");
    }
    printf("\n");
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("=== BATALHA NAVAL - NIVEL MESTRE ===\n");
    printf("=== HABILIDADES ESPECIAIS ===\n\n");
    
    // 1. Inicialização do tabuleiro com navios
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa com água
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    
    // Posiciona alguns navios para demonstração
    tabuleiro[2][3] = NAVIO; tabuleiro[2][4] = NAVIO; tabuleiro[2][5] = NAVIO;
    tabuleiro[5][7] = NAVIO; tabuleiro[6][7] = NAVIO; tabuleiro[7][7] = NAVIO;
    tabuleiro[8][2] = NAVIO; tabuleiro[8][3] = NAVIO; tabuleiro[8][4] = NAVIO;
    
    // 2. Criação das matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    // Exibe as matrizes de habilidade
    exibirHabilidade(cone, "CONE");
    exibirHabilidade(cruz, "CRUZ");
    exibirHabilidade(octaedro, "OCTAEDRO");
    
    // 3. Aplicação das habilidades no tabuleiro
    printf("\n=== APLICANDO HABILIDADES ===\n");
    
    // Cone centrado em (2, 4)
    printf("Aplicando CONE em (2,4)...\n");
    aplicarHabilidade(tabuleiro, cone, 2, 4);
    
    // Cruz centrada em (6, 6)
    printf("Aplicando CRUZ em (6,6)...\n");
    aplicarHabilidade(tabuleiro, cruz, 6, 6);
    
    // Octaedro centrado em (8, 3)
    printf("Aplicando OCTAEDRO em (8,3)...\n");
    aplicarHabilidade(tabuleiro, octaedro, 8, 3);
    
    // 4. Exibição do tabuleiro final
    exibirTabuleiro(tabuleiro);
    
    // 5. Legenda e informações
    printf("\n=== LEGENDA ===\n");
    printf("0 - Agua\n");
    printf("3 - Navio\n");
    printf("5 - Area afetada por habilidade\n");
    
    printf("\n=== CENTROS DAS HABILIDADES ===\n");
    printf("CONE: (2,4)\n");
    printf("CRUZ: (6,6)\n");
    printf("OCTAEDRO: (8,3)\n");
    
    printf("\n=== MISSAO CUMPRIDA! ===\n");
    return 0;
}
