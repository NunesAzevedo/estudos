#include <stdio.h>

int main () {

    FILE *arq;
    arq = fopen ("arquivo.txt", "w+");

    if (arq == NULL) printf ("\nErro abrindo o arquivo\n");

    char frase[10];
    gets (frase);
    fprintf (arq, "%s", frase);
    fgets (frase, 10, arq);
    printf ("%s", frase);
}
