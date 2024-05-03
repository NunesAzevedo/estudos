#include <stdio.h>

int main() {

    int nota[100], menor, segunda_menor;
    // colocar valor inicial de 9999 para todas as entradas
    for (int i = 0; i < 100; i++) {
        nota [i] = 9999;
    }
    // colocar o valor das notas
    for (int i=0; i < 100; i++) {
        scanf("%d", &nota[i]);
        if (nota [i] < 0) {
            nota[i] = 9999;
            break;
        }
    }
    // Ordenar as notas
    for (int i = 0; i < 100; i++) {
        int aux, j;
        aux = nota[i];
        j= i -1;

        while (j>=0 && nota[j] > aux) {
            nota[j+1] = nota [j];
            j--;
        }
        nota[j+1] = aux;
    }

    printf("%d %d", nota[0], nota[1]);

}
