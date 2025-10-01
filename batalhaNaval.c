#include <stdio.h>

#include <stdio.h>

#define LINHA 10
#define COLUNA 10

int main() {

    printf("\n>>>>> Jogo de Batalha Naval <<<<<\n\n");
    
    int matriz[LINHA][COLUNA];

    // Inicializar toda a matriz com água (0)
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            matriz[i][j] = 0;
        }
    }

    // Posicionar navio horizontal
    for (int j = 4; j <= 6; j++) {
        matriz[3][j] = 3;
    }

    // Posicionar navio vertical
    for (int i = 0; i <= 2; i++) {
        matriz[i][8] = 3;
    }

    // Posicionar navio diagonal
    for (int i = 5; i <= 7; i++) {
        matriz[i][i - 3] = 3;
    }

    // Posicionar cruz
    for (int i = 0; i <= 4; i++) { // Eixo vertical
        matriz[i][2] = 5;
        for (int j = 0; j <= 4; j++) { // Eixo horizontal
        matriz[2][j] = 5;
        }
    }

    // Posicionar cone
    for (int i = 6; i <= 8; i++) {
        matriz[i][2] = 5;
        for (int j = 0; j <= 4; j++) {
            if (j < 4 && j > 0 && i == 7) {
                matriz[i][j] = 5;
            } else if (j < 5 && j >= 0 && i == 8) {
                matriz[i][j] = 5;
            }
        }
    }
    
    // Posicionar octaedro (linhas 6-10, centro coluna H)
    int centro_octaedro = 7;  // Coluna H (índice 7)
    int linha_inicial_octaedro = 5;  // Linha 6 (índice 5)

    for (int i = 0; i <= 4; i++) {  // 5 linhas do octaedro (0 a 4)
        int linha_atual = linha_inicial_octaedro + i;
        
        // Calcular largura: cresce até o meio, depois diminui
        int largura;
        if (i <= 2) {
            // Fase de expansão: 1, 3, 5
            largura = 1 + (i * 2);
        } else {
            // Fase de contração: 3, 1
            largura = 1 + ((4 - i) * 2);
        }
        
        // Calcular deslocamento do centro
        int deslocamento = (largura - 1) / 2;
        
        // Preencher a linha
        for (int j = centro_octaedro - deslocamento; j <= centro_octaedro + deslocamento; j++) {
            matriz[linha_atual][j] = 5;
        }
    }

    // Imprimir cabeçalho com letras
    printf("   ");
    for (int i = 0; i < COLUNA; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");

    // Imprimir tabuleiro
    for (int i = 0; i < LINHA; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}