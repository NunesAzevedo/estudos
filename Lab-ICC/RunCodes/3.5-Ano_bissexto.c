# include <stdio.h>

int main () {

    // Declaração de variáveis
    int
    ano = 0;


    // Leitura dos dados
    scanf ("%d", &ano);

    // Verificação se o ano é bissexto
    if ( ano%400 == 0 || ( ano%4 == 0 && ano%100 != 0) ) {// Se o ano for bissexto
        printf ("Sim");
    } else printf ("Nao");
}

