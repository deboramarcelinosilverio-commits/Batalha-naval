#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    printf("=== BATALHA NAVAL - NIVEL NOVATO ===\n\n");
    
    // 1. Declaração e inicialização do tabuleiro (0 = água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // 2. Posicionamento dos navios (coordenadas fixas no código)
    
    // Navio 1 - Horizontal (linha 2, coluna 3)
    int navio1_linha = 2;
    int navio1_coluna = 3;
    
    // Valida se o navio horizontal cabe no tabuleiro
    if (navio1_coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int j = navio1_coluna; j < navio1_coluna + TAMANHO_NAVIO; j++) {
            tabuleiro[navio1_linha][j] = 3; // 3 = navio
        }
    } else {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }
    
    // Navio 2 - Vertical (linha 5, coluna 7)
    int navio2_linha = 5;
    int navio2_coluna = 7;
    
    // Valida se o navio vertical cabe no tabuleiro
    if (navio2_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = navio2_linha; i < navio2_linha + TAMANHO_NAVIO; i++) {
            tabuleiro[i][navio2_coluna] = 3; // 3 = navio
        }
    } else {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }
    
    // 3. Validação de sobreposição (verifica se algum navio sobrepôs outro)
    int contador_navios = 0;
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 3) {
                contador_navios++;
            }
        }
    }
    
    // Deve ter exatamente 6 posições de navio (2 navios × 3 posições)
    if (contador_navios != 6) {
        printf("Erro: Navios se sobrepoem!\n");
        return 1;
    }
    
    // 4. Exibição do tabuleiro
    printf("Tabuleiro 10x10 - (0 = Agua, 3 = Navio)\n\n");
    
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
    
    // 5. Informações dos navios posicionados
    printf("\n=== NAVIOS POSICIONADOS ===\n");
    printf("Navio 1 (Horizontal): Linha %d, Coluna %d a %d\n", 
           navio1_linha, navio1_coluna, navio1_coluna + TAMANHO_NAVIO - 1);
    printf("Navio 2 (Vertical): Coluna %d, Linha %d a %d\n", 
           navio2_coluna, navio2_linha, navio2_linha + TAMANHO_NAVIO - 1);
    
    printf("\n=== POSICIONAMENTO CONCLUIDO ===\n");
    return 0;
}
