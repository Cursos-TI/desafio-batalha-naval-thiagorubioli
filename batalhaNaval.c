#include <stdio.h>

int main () {

    printf("\n>>>>> Jogo de Batalha Naval <<<<<\n\n");
    
    // Declaração e inicialização do vetor de letras (colunas)
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // Declaração e inicialização da matriz de 10x10 (tabuleiro)
    int tabuleiro[10][11] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Imprimindo a linha de letras (cabeçalho das colunas "A" até "J")
    printf("  ");
    for (int i = 0; i < 10; i++) {
        printf(" %c", letras[i]);
    }

    printf("\n");
      
    // Acessando e imprimindo o restante dos elementos da matriz (tabuleiro e navios)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 11; j++) {
            if (i == 3 && j > 3 && j < 7) // Adicionando um navio horizontal na linha 4, colunas D, E e F
            {
                printf("3 "); // Imprimindo o número "3" para representar a localização do navio horizontal

            } else if (j == 8 && i > 4 && i < 8) // Adicionando um navio vertical na coluna H, linhas 6, 7 e 8
            {
                printf("3 "); // Imprimindo o número "3" para representar a localização do navio vertical

            } else
            {
                if (i < 9 && j == 0)
                {
                    printf(" %d ", tabuleiro[i][j]); // Imprimindo o restante do tabuleiro com um espaço adicional antes das linhas 1-9
                } else
                {
                    printf("%d ", tabuleiro[i][j]); // Imprimindo a linha 10 sem espaço adicional para regularizar o tabuleiro
                }
            }
        }
        printf("\n");
    }

    return 0;

}