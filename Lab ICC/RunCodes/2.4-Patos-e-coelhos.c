#include <stdio.h>

int main () {
    // Declaração de variáveis
    int
    cabeca = 0,
    pes = 0,
    pato = 0,
    coelho = 0;

    // Leitura dos dados
    scanf("%d", &cabeca);
    scanf("%d", &pes);

    //Calculos
    pato = 2*cabeca - (pes/2);
    coelho = (pes/2) - cabeca;

    printf("%d %d", pato, coelho);
}