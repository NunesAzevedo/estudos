#include <stdio.h>

int main () {
    //Coletar do usuario a quantidade de dias
    int dias = 0;
    scanf ("%d", &dias);

    //Calculos
    int semanas = 0;
    semanas = dias/7;
    dias = dias%7;

    printf ("%d %d", semanas, dias);
}
