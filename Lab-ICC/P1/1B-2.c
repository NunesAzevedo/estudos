#include <stdio.h>

int main () {

    int nota = 0, menor, segunda_menor;

    scanf("%d", &nota);
    menor = nota;

    scanf("%d", &nota);

    if (nota > menor) {
        segunda_menor = nota;
    }else{
        int aux;
        aux = menor;
        menor = nota;
        segunda_menor = aux;
    }

    for(;;) {
        scanf("%d", &nota);
        if (nota < 0){
            break;
        }else{

            if (nota <= menor) {
                menor = nota;
            }else{
                if (nota<= segunda_menor) {
                    segunda_menor = nota;
                }
            }



        }
    }

    printf("%d %d", menor, segunda_menor);
}
