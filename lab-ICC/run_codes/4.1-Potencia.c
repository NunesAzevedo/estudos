# include <stdio.h>

int main () {

    // Declaração de variáveis
    int
    x = 0,
    y = 0,
    pot = 1;

    // Leitura dos dados
    scanf ("%d", &x);
    scanf ("%d", &y);

    // Cálculos
    for (int i = 0; i < y; i++) {
        pot *= x;
    }

    printf ("%d", pot);
}
