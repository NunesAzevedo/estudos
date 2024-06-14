#include <stdio.h>

int  TAM = 5; // Tamanho do vetor

int main () {

    int A[TAM],  B[TAM], S[TAM];

    // Leitura de A
    for (int i = 0; i < TAM; i++) {
        scanf("%d", &A[i]);
    }

    // Leitura de B
        for (int i = 0; i < TAM; i++) {
        scanf("%d", &B[i]);
    }

    // Calculo do vetor S
    for (int i = 0; i < TAM; i++) {
        S[i] = A[i] + B[i];
    }

    // Impressão de S
    for (int i = 0; i < TAM; i++) {
        printf("%d\n", S[i]);
    }

    return 0;
}