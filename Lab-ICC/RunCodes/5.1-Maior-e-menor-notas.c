#include <stdio.h>

int main () {

    int nota = 0, maior = -1, menor = 999;
    while (nota >= 0) {
        scanf("%d", &nota);
        
        if (nota >=0 && nota >= maior) {
            maior = nota;
        } 
        if (nota >=0 && nota <= menor) {
        menor = nota;
        }
    }

    printf("%d %d", maior, menor);
}