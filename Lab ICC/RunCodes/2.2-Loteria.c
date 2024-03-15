#include <stdio.h>

int main () {
    //Declaracao de variaveis
    float
    amigo1 = 0,
    amigo2 = 0,
    amigo3 = 0,
    premio = 0;

    //Leitura dos dados
    scanf ("%f", &premio);
    scanf ("%f", &amigo1);
    scanf ("%f", &amigo2);
    scanf ("%f", &amigo3);

    //Calculos
    float investimento_total = 0;

    investimento_total = amigo1 + amigo2 + amigo3;

    amigo1 = premio * (amigo1/investimento_total);
    amigo2 = premio * (amigo2/investimento_total);
    amigo3 = premio * (amigo3/investimento_total);

    //Saidas
    printf ("%f %f %f", amigo1, amigo2, amigo3);
}
