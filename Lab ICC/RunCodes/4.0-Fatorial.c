# include <stdio.h>

int main () {

    // Declara��o de vari�veis
    int
    n = 0,
    fat = 1;

    // Leitura dos dados
    scanf ("%d", &n);

    // Calculo do fatorial
    if (n != 0) {
        for (int i = 0; i < n; i++) {
            fat *= n - i;
        }
    }
    printf ("%d", fat);
}
