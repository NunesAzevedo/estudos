#include <stdio.h>

int main () {

    int nota_alta = 0, nota_baixa = 0;
    float nota = 0, media = 0;
    float porc_aprov = 0;
    int i = 0;
   
    for (;;) {
        scanf("%f", &nota);
        if (nota < 0) break;
        if (nota < 5.0) nota_baixa++;
        if (nota >= 5.0) nota_alta++;

        media += nota;
    }
    media = (media*1.0 ) / (nota_alta*1.0 + nota_baixa*1.0);

    porc_aprov = (nota_alta*1.0 * 100) / (nota_alta*1.0 + nota_baixa*1.0);

    printf("%d %d %f %f %f", nota_baixa, nota_alta, media, porc_aprov);
}