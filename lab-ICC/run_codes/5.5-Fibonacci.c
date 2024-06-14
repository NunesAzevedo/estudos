#include <stdio.h>

// Função que calcula o Fibonacci
int fibonachos (int n) {

    int fiboncci;

    if (n == 0 || n == 1) {
        fiboncci = n;
        return fiboncci;
    }

    fiboncci = fibonachos(n - 1) + fibonachos(n - 2);
    return fiboncci;
}



int main() {

    // Declaração de variáveis
    int n;

    // Leitura de n
    scanf("%d", &n);

    // Impressão dos fibonachos
    for (int i = 0; i > -1; i++) {
        if (fibonachos(i) > n) {
            printf("%d", fibonachos(i));
            break;
        }
        printf("%d\n", fibonachos(i));
    }

    return 0;
}