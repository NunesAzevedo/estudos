#include <stdio.h>

float aritmetica (float x, float y, float z) {
    float media;

    media = ( x + y + z) / 3;

    return media;
}

float ponderada (float x, float y, float z) {
    float media;
    media = ( 5*x + 3*y + 2*z) / (5 + 2 + 2);

    return media;
}

float harmonica (float x, float y, float z) {
    float media;

    media = 3 /( (1/x) + (1/y) + (1/z) );

    return media;
}


int main () {
    char opc;
    float x, y, z, media;

    printf("\nDigite as notas:\n");

    // Leitura das notas
    do{
    printf("\nPrimeira nota:\t");
    scanf("%f", &x);
    } while (x < 0.0);

    do {
    printf("\nSegunda nota:\t");
    scanf("%f", &y);
    } while (y < 0.0);

    do{
    printf("\nTerceira nota:\t");
    scanf("%f", &z);
    } while (z < 0.0);

    // Leitura da escolha da média
    do {
        printf("\n****** Selecione a media: ******\n");
        printf("\nDigite A: para media Aritmetica\n");
        printf("\nDigite P: para media Ponderada\n");
        printf("\nDigite H: para media Harmonica\n");
        scanf("%c", &opc);
    } while ( opc != 'A' && opc != 'P' && opc != 'H' );


    switch (opc) {

        case 'A':
            media = aritmetica(x, y, z);
            printf("\nA media do aluno e:\t %f\n", media);
            break;
    
        case 'P':
            media = ponderada(x, y, z);
            printf("\nA media do aluno e:\t %f\n", media);
            break;

        case 'H':
            media = harmonica(x ,y ,z);
            printf("\nA media do aluno e:\t %f\n", media);
            break;

        default:
            printf("\n****** Opcao invalida ******\n");
            break;
    }

    return 0;    
}
