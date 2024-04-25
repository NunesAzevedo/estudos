# include <stdio.h>

int main () {

    // Declaração de variáveis

    //Valor de entrada: positivo e inteiro
    int n;

    // Leitura dos valores
    scanf ("%d", &n);

    // Cálculo dos divisores
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) printf ("%d\n", i);
    }
}
