#include <stdio.h>

int main () {
    //Declaracao de variaveis
    int
    hora_inicial = 0,
    minuto_inicial = 0,
    segundo_inicial = 0,
    duracao = 0,

    hora_final = 0,
    minuto_final = 0,
    segundo_final = 0;

    //Leitura dos dados
    scanf ("%d", &hora_inicial);
    scanf ("%d", &minuto_inicial);
    scanf ("%d", &segundo_inicial);
    scanf ("%d", &duracao);

    //Calculos
/*
    hora_final = (hora_inicial*60*60 + duracao) / (60*60);
    minuto_final = (minuto_inicial*60 + (duracao - (hora_final - hora_inicial)*60*60) ) /60;
    segundo_final = segundo_inicial + (duracao - (hora_final - hora_inicial)*6060 - (minuto_final - minuto_inicial)*60 );
*/

    segundo_final = segundo_inicial + duracao;
    minuto_final = ( minuto_inicial*60 + (duracao - (segundo_final - segundo_inicial)) ) /60;
    hora_final = hora_inicial*60*60 + duracao;

    //Saida
    printf ("%d %d %d", hora_final, minuto_final, segundo_final);
}
