# include <stdio.h>

int main () {

    // Declara��o de vari�veis
    int
    x = 0,
    y = 0,
    pot = 1;

    // Leitura dos dados
    scanf ("%d", &x);
    scanf ("%d", &y);

    // C�lculos
    for (int i = 0; i < y; i++) {
        pot *= x;
    }

    printf ("%d", pot);
}
