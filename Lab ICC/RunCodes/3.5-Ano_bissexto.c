# include <stdio.h>

int main () {

    // Declara��o de vari�veis
    int
    ano = 0;


    // Leitura dos dados
    scanf ("%d", &ano);

    // Verifica��o se o ano � bissexto
    if ( ano%400 == 0 || ( ano%4 == 0 && ano%100 != 0) ) {// Se o ano for bissexto
        printf ("Sim");
    } else printf ("Nao");
}

