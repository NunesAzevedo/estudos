#include <stdio.h>

int main () {

    // Declara��o de vari�veis

    float
    altura = 0,
    peso_ideal = 0;

    int sexo = 0; // 1 para mulheres e 2 para homens


    // Leitura dos dados

    scanf ("%f", &altura);
    scanf ("%d", &sexo);

    // C�lculos

    if (sexo == 2) { // Para Homens
        peso_ideal = 72.7*altura - 58;
    }

    if (sexo == 1) { //Para Mulheres
        peso_ideal = 62.1*altura -44.7;
    }

    if (sexo != 1 && sexo != 2) { // Entrada digitada com erro
        return;
    }

    // Impress�o do peso ideal

    printf ("%f", peso_ideal);
}
