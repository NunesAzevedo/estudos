#include <stdio.h>

int main () {

    FILE *arq;

    int n;

    arq = fopen ("test.txt", "w+"); // Cria, ou sobscreve o arquivo existente, permitindo a sua escrita
    if (arq == NULL ) printf ("\nErro abrindo o arquivo.\n");

    for (int i = 0; i < 5; i++) {
        scanf ("%d", &n);
        fprintf (arq, "%d\n", n);
    }

    fclose (arq);

}