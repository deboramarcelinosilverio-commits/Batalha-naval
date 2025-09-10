#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NUM_NAVIOS 4

int main() {
    printf("=== BATALHA NAVAL - NIVEL AVENTUREIRO ===\n\n");
    
    // 1. Declaração e inicialização do tabuleiro (0 = água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // 2. Posicionamento dos quatro navios (coordenadas fixas no código)
    
    // Navio 1 - Horizontal (linha 1, coluna 2)
    int navio1_linha = 1;
    int navio1_coluna = 2;
    printf("Posicionando Navio 1 (Horizontal)...\n");
    for (int j = navio1_coluna; j < navio1_coluna + TAMANHO_NAVIO; j++) {
        tabuleiro[navio1_linha][j] = 3;
    }
    
    // Navio 2 - Vertical (linha 4, coluna 8)
    int navio2_linha = 4;
    int navio2_coluna = 8;
    printf("Posicionando Navio 2 (Vertical)...\n");
    for (int i = navio2_linha; i < navio2_linha + TAMANHO_NAVIO; i++) {
        tabuleiro[i][navio2_coluna] = 3;
    }
    
    // Navio 3 - Diagonal Principal (linha 6, coluna 1)
    int navio3_linha = 6;
    int navio3_coluna = 1;
    printf("Posicionando Navio 3 (Diagonal Principal)...\n");
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[navio3_linha + k][navio3_coluna + k] = 3;
    }
    
    // Navio 4 - Diagonal Secundária (linha 2, coluna 6)
    int navio4_linha = 2;
    int navio4_coluna = 6;
    printf("Posicionando Navio 4 (Diagonal Secundária)...\n");
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[navio4_linha + k][navio4_coluna - k] = 3;
    }
    
    // 3. Validação de sobreposição e limites
    int contador_navios = 0;
    int erro_sobreposicao = 0;
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 3) {
                contador_navios++;
                // Verifica se há sobreposição (valor maior que 3 indica sobreposição)
                if (tabuleiro[i][j] > 3) {
                    erro_sobreposicao = 1;
                }
            }
        }
    }
    
    // Deve ter exatamente 12 posições de navio (4 navios × 3 posições)
    if (contador_navios != 12) {
        printf("Erro: Navios fora dos limites do tabuleiro!\n");
        return 1;
    }
    
    if (erro_sobreposicao) {
        printf("Erro: Navios se sobrepoem!\n");
        return 1;
    }
    
    // 4. Exibição do tabuleiro
    printf("\n=== TABULEIRO COMPLETO 10x10 ===\n");
    printf("(0 = Agua, 3 = Navio)\n\n");
    
    // Imprime coordenadas das colunas
    printf("    ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    // Imprime linha separadora
    printf("    ");
    for (int j = 0; j < TAMANHO_TABULEIRO * 2; j++) {
        printf("-");
    }
    printf("\n");
    
    // Imprime tabuleiro com coordenadas das linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i); // Coordenada da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    // 5. Informações detalhadas dos navios
    printf("\n=== INFORMAÇÕES DOS NAVIOS ===\n");
    printf("Navio 1 (Horizontal): Linha %d, Colunas %d-%d\n", 
           navio1_linha, navio1_coluna, navio1_coluna + TAMANHO_NAVIO - 1);
    printf("Navio 2 (Vertical): Coluna %d, Linhas %d-%d\n", 
           navio2_coluna, navio2_linha, navio2_linha + TAMANHO_NAVIO - 1);
    printf("Navio 3 (Diagonal Principal): Inicio (%d,%d), Fim (%d,%d)\n",
           navio3_linha, navio3_coluna, 
           navio3_linha + TAMANHO_NAVIO - 1, navio3_coluna + TAMANHO_NAVIO - 1);
    printf("Navio 4 (Diagonal Secundária): Inicio (%d,%d), Fim (%d,%d)\n",
           navio4_linha, navio4_coluna,
           navio4_linha + TAMANHO_NAVIO - 1, navio4_coluna - TAMANHO_NAVIO + 1);
    
    printf("\n=== POSICIONAMENTO CONCLUIDO COM SUCESSO! ===\n");
    printf("Total de posicoes de navio: %d/12\n", contador_navios);
    
    return 0;
}
