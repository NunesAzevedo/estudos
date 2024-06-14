#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, World!";
    char dest[50]; // Certifique-se de que o buffer de destino é grande o suficiente

    scanf("%s", dest);

    // Copiando a string de src para dest
    memcpy(dest, src, strlen(src) + 1); // Inclui o byte nulo de terminação

    // Imprimindo a string copiada
    printf("Destino: %s\n", dest);

    return 0;
}
