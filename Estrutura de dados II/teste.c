#include <stdio.h>

int main() {
    char anykey;

    int soma = 0;

    int n = 1;

    for (int i = 0; i <= n; i++) {
        soma = soma + i*i*i;
    }

    printf ("%d", soma);

    scanf("%c", &anykey);
    return 0;
}