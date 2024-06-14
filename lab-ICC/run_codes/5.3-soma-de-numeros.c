#include <stdio.h>

int main() {

    int x, y, somatorio = 0;

    // Lê x e y
    scanf("%d", &x);
    scanf("%d", &y);

    // Se y for menor que x, eles trocam de valor
    if (y < x) {
        int aux;
        aux = y;
        y = x;
        x = aux;
    }

    for(int i = x; i <= y; i++) {
        somatorio += i;
    }


    printf("%d", somatorio);


    return 0;
}