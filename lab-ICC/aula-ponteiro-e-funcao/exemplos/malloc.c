#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, i;

    // Tamanho do array
    n = 5;

    // Alocação dinâmica de memória para n inteiros
    ptr = (int*)malloc(n * sizeof(int));

    // Verificação de alocação de memória
    if (ptr == NULL) {
        printf("Memória não alocada.\n");
        exit(0);
    }

    // Inicializando o array
    for (i = 0; i < n; ++i) {
        ptr[i] = i + 1;
    }

    // Exibindo os valores do array
    printf("Os elementos do array são: ");
    for (i = 0; i < n; ++i) {
        printf("%d ", ptr[i]);
    }

    // Liberando a memória alocada
    free(ptr);

    return 0;
}
