#include <stdio.h>

int main () {
    //Declaracao de variaveis
    // int
    // hora_inicial = 0,
    // minuto_inicial = 0,
    // segundo_inicial = 0,
    // duracao = 0,

    // hora_final = 0,
    // minuto_final = 0,
    // segundo_final = 0;

    int
    hora = 0,
    minuto = 0,
    segundo = 0,
    duracao = 0,
    
    tempo = 0;

    //Leitura dos dados
    scanf ("%d", &hora);
    scanf ("%d", &minuto);
    scanf ("%d", &segundo);
    scanf ("%d", &duracao);

    //Calculos
/*
    hora_final = (hora_inicial*60*60 + duracao) / (60*60);
    minuto_final = (minuto_inicial*60 + (duracao - (hora_final - hora_inicial)*60*60) ) /60;
    segundo_final = segundo_inicial + (duracao - (hora_final - hora_inicial)*6060 - (minuto_final - minuto_inicial)*60 );
*/

    // segundo_final = segundo_inicial + duracao;
    // minuto_final = ( minuto_inicial*60 + (duracao - (segundo_final - segundo_inicial)) ) /60;
    // hora_final = hora_inicial*60*60 + duracao;

    tempo = hora*3600 + minuto*60 + segundo + duracao; //Converter o tempo total em segundos

    //Converter o tempo total em horas, minutos e segundos
    hora += tempo/3600;
    minuto += tempo/60 - tempo%3600;
    segundo += tempo - tempo%60 - tempo%3600;

    //Saida
    printf ("%d %d %d", hora, minuto, segundo);
}
