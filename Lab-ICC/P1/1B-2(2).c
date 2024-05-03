#include <stdio.h>

int main () {

    int nota = 0, menor = 99, segunda_menor = 99;
    int count = 0;

    for(;;) {
        //printf("\n");
        scanf("%d", &nota);
        count++;
        //printf("\ncount: %d\n", count);
        if (nota < 0){
            if (count == 1) {


                menor = 0;
                segunda_menor = 0;
                break;


            }else if (count == 2){

                int aux;
                aux = menor;
                segunda_menor = menor;
                menor = 0;
                break;


            }else {


                break;

            }

            break;
        }else{

            if (count == 1) {
                menor = nota;


            } else if (count == 2) {

                if (nota < menor){
                    menor = nota;
                } else if (nota > menor) {

                    segunda_menor = nota;
                }


            }





            if (nota < menor) {
                menor = nota;
            }else{


                if ( (nota < segunda_menor) && ( nota > menor ) ) {
                    segunda_menor = nota;


                }
            }


        }

    printf("\nMenor: %d\n", menor);
    printf("\nSegunda menor: %d\n", segunda_menor);
    }
    //printf("\n");
    //printf("\nresulado: ");
    printf("%d %d", menor, segunda_menor);
}
