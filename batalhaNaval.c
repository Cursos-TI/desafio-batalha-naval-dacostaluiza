#include <stdio.h>

// Define constantes para o tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada elemento com espaço para legibilidade
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
    printf("\n"); // Linha extra para separar saídas
}

// Função para verificar se o navio cabe no tabuleiro e não se sobrepõe
int validarPosicao(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int tamanho, int horizontal) {
    if (horizontal) {
        // Verifica se o navio horizontal cabe no tabuleiro
        if (coluna + tamanho > TAM_TABULEIRO) return 0;
        // Verifica sobreposição
        for (int j = coluna; j < coluna + tamanho; j++) {
            if (tabuleiro[linha][j] != 0) return 0;
        }
    } else {
        // Verifica se o navio vertical cabe no tabuleiro
        if (linha + tamanho > TAM_TABULEIRO) return 0;
        // Verifica sobreposição
        for (int i = linha; i < linha + tamanho; i++) {
            if (tabuleiro[i][coluna] != 0) return 0;
        }
    }
    return 1; // Posição válida
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int tamanho, int horizontal) {
    if (horizontal) {
        // Posiciona navio horizontalmente
        for (int j = coluna; j < coluna + tamanho; j++) {
            tabuleiro[linha][j] = 3; // Marca posição do navio com 3
        }
    } else {
        // Posiciona navio verticalmente
        for (int i = linha; i < linha + tamanho; i++) {
            tabuleiro[i][coluna] = 3; // Marca posição do navio com 3
        }
    }
}

int main() {
    // Declaração do tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios definidas diretamente no código
    int linhaNavio1 = 2;    // Linha inicial do navio horizontal
    int colunaNavio1 = 3;   // Coluna inicial do navio horizontal
    int linhaNavio2 = 5;    // Linha inicial do navio vertical
    int colunaNavio2 = 7;   // Coluna inicial do navio vertical

    // Validação e posicionamento do navio horizontal
    if (validarPosicao(tabuleiro, linhaNavio1, colunaNavio1, TAM_NAVIO, 1)) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, TAM_NAVIO, 1);
    } else {
        printf("Erro: Posição inválida para o navio horizontal.\n");
        return 1;
    }

    // Validação e posicionamento do navio vertical
    if (validarPosicao(tabuleiro, linhaNavio2, colunaNavio2, TAM_NAVIO, 0)) {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, TAM_NAVIO, 0);
    } else {
        printf("Erro: Posição inválida para o navio vertical.\n");
        return 1;
    }

    // Exibe o tabuleiro com os navios posicionados
    printf("Tabuleiro com navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
