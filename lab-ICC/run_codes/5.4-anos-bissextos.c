#include <stdio.h>

int main() {

    int ano_inicial;
    int ano_final;

    scanf("%d", &ano_inicial);
    scanf("%d", &ano_final);

    // for (int i = ano_inicial; i <= ano_final; i++) {
    //     if ( i % 4 == 0 && i % 100 != 0) {// Verifica se o ano eh bissexto
    //         printf("%d\n", i);
    //     }
    //     if ( i % 100 == 0)
    // }

    for (int i = ano_inicial; i <= ano_final; i++) {

        if ( i % 4 == 0) { // Etapa 1

            if ( i % 100 == 0) { // Etapa 2

                if (i % 400 == 0) { // Etapa 3
                    printf("%d\n", i); // Eh bissexto
                }

            }
            else {

                printf("%d\n", i); // Eh bissexto
                
            }
        }
    }


    return 0;
}