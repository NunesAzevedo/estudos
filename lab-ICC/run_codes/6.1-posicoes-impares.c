#include <stdio.h>

int TAM = 10; // Tamanho do vetor

int main () {

    // Declaração de variáveis
    int v[TAM], soma = 0;

    // Entrada dos valores do vetor
    for (int i = 0; i < TAM; i++) {
        scanf("%d", &v[i]);
        if (i % 2 !=0) { // Se a posição for ímpar, soma o valor
            soma += v[i];
        }
    }

    printf("%d\n", soma); // Saída da soma dos valores nas posições ímpares

    return 0;
}