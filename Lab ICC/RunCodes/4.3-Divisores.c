# include <stdio.h>

int main () {

    // Declara��o de vari�veis

    //Valor de entrada: positivo e inteiro
    int n;

    // Leitura dos valores
    scanf ("%d", &n);

    // C�lculo dos divisores
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) printf ("%d\n", i);
    }
}
