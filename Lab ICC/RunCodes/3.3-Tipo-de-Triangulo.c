# include <stdio.h>

int main () {

    // Declaração de variáveis

    // Lados do triângulo
    float
    lado_1 = 0,
    lado_2 = 0,
    lado_3 = 0;

    int status = 0; // status do triângulo

    /*
    status:
    0: Inválido
    1: Isósceles
    2: Equilátero
    3: Escaleno
    */

    // Leitura dos dados

    scanf ("%f", &lado_1);
    scanf ("%f", &lado_2);
    scanf ("%f", &lado_3);

    // Cálculos

    //Verificação se o triângulo é Isósceles
    if (
        lado_1 == lado_2 ||
        lado_1 == lado_3 ||
        lado_2 == lado_3
    ) {
        status = 1;
    }

    // Verificação se o triângulo é equilátero
    if (lado_1 == lado_2 && lado_1 == lado_3) {
        status = 2;
    }

    // Verificação se o triângulo é escaleno
    if (status == 0) {
        status = 3;
    }


    // Verificação de existência do triângulo
    if (
    !(
    lado_1 < (lado_2 + lado_3) &&
    lado_2 < (lado_1 + lado_3) &&
    lado_3 < (lado_1 + lado_2)
      )
    ) {
        status = 0;
    }


    // Impressão do resultado
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
