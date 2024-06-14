#include <stdio.h>
#include <stdlib.h>

int TAM = 10; // Tamanho do vetor

int main () {

    int A[TAM];
    int maior_diferenca;

    // Leitura de A
    for (int i = 0; i < TAM; i++) {
        scanf("%d", &A[i]);
    }

    // Calculo da maior diferenca
    maior_diferenca = A[1] - A[0]; // Set da diferença inicial
    for (int i = 0; i < TAM -1; i++) {
        if (abs(A[i+1] - A[i]) > maior_diferenca) {
            maior_diferenca = abs(A[i+1] - A[i]);
        }
    }

    printf("%d", maior_diferenca);

    return 0;
}