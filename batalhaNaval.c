#include <stdio.h>

#define LINHA 10
#define COLUNA 10

int main() {

    printf("\n>>>>> Jogo de Batalha Naval <<<<<\n\n");
    
    // Declaração e inicialização do vetor de letras (colunas) do tabuleiro
    char letras[LINHA];
    char letra_ini = 'A';

    // Declaração e inicialização da numeração das linhas do tabuleiro
    int linhas[LINHA];
    int linha_ini = 1;
    
    // Declaração da matriz de 10x10 (tabuleiro)
    int matriz[LINHA][COLUNA];

    // Imprimindo a linha de letras (cabeçalho das colunas "A" até "J")
    printf("   ");
    for (int i = 0; i < 10; i++) {
        letras[i] = letra_ini;
        letra_ini++;
        printf("%c ", letras[i]);
    }

    printf("\n");

    // Acessando e imprimindo tabuleiro com os navios posicionados
    for (int i = 0; i < LINHA; i++) {      // Loop externo para as linhas
        linhas[i] = linha_ini;
        linha_ini++;
        printf("%2d ", linhas[i]);
        for (int j = 0; j < COLUNA; j++) {  // Loop interno para as colunas
            if (i == 3 && j > 3 && j < 7) // Adicionando um navio horizontal na linha 4, colunas E, F e G
            {
                printf("3 "); // Imprimindo o número "3" para representar a localização do navio horizontal

            } else if (j == 8 && i > 4 && i < 8) // Adicionando um navio vertical na coluna I, linhas 6, 7 e 8
            {
                printf("3 "); // Imprimindo o número "3" para representar a localização do navio vertical

            } else if (i == j && j > 3 && j < 7) // Adicionando um navio diagonal nas linhas 5, 6 e 7, colunas E, F e G
            {
                printf("3 "); // Imprimindo o número "3" para representar a localização do navio diagonal

            } else
            {
            matriz[i][j] = 0;
            printf("%d ", matriz[i][j]); // Imprimindo o número "0" para representar água
            }
        }
        printf("\n");
    }
 
    return 0;
}