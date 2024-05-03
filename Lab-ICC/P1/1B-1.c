#include <stdio.h>

int main () {

    float d, x, y, z;
    int bool;

    scanf ("%f", &d);
    scanf ("%f", &x);
    scanf ("%f", &y);
    scanf ("%f", &z);

    // Comparar as dimensoes
    if ((d <= x) && (d <= y)&& (d <= z) ) {
        bool = 1; // cabe na caixa
    } else {
        bool = 0;} // não cabe na caixa

    printf("%d", bool);

}
