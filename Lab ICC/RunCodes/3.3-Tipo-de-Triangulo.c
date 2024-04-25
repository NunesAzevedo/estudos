# include <stdio.h>

int main () {

    // Declara��o de vari�veis

    // Lados do tri�ngulo
    float
    lado_1 = 0,
    lado_2 = 0,
    lado_3 = 0;

    int status = 0; // status do tri�ngulo

    /*
    status:
    0: Inv�lido
    1: Is�sceles
    2: Equil�tero
    3: Escaleno
    */

    // Leitura dos dados

    scanf ("%f", &lado_1);
    scanf ("%f", &lado_2);
    scanf ("%f", &lado_3);

    // C�lculos

    //Verifica��o se o tri�ngulo � Is�sceles
    if (
        lado_1 == lado_2 ||
        lado_1 == lado_3 ||
        lado_2 == lado_3
    ) {
        status = 1;
    }

    // Verifica��o se o tri�ngulo � equil�tero
    if (lado_1 == lado_2 && lado_1 == lado_3) {
        status = 2;
    }

    // Verifica��o se o tri�ngulo � escaleno
    if (status == 0) {
        status = 3;
    }


    // Verifica��o de exist�ncia do tri�ngulo
    if (
    !(
    lado_1 < (lado_2 + lado_3) &&
    lado_2 < (lado_1 + lado_3) &&
    lado_3 < (lado_1 + lado_2)
      )
    ) {
        status = 0;
    }


    // Impress�o do resultado
    switch (status) {
    case 0:
        printf ("Invalido");
        break;

    case 1:
        printf ("Isosceles");
        break;

    case 2:
        printf ("Equilatero");
        break;

    case 3:
        printf ("Escaleno");
        break;

    default:
        printf ("Invalido");
        break;
    }
}
