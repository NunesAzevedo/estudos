#include <stdio.h>

int main () {
    // Declaração de variaveis
    int
    horas = 0,
    minutos = 0,
    segundos = 0,
    duracao = 0,

    tempo = 0;

    // Leitura dos dados
    scanf("%d", &horas);
    scanf("%d", &minutos);
    scanf("%d", &segundos);
    scanf("%d", &duracao);

    // Cálculos

    // Conversão do tempo horiginal em segundos
    tempo = horas*3600 + minutos*60 + segundos;
    tempo += duracao; // Somando o tempo original com a duracao

    // Conversao do tempo final em horas, minutos e segundos
    horas = tempo / 3600;
    tempo -= horas*3600; // Removendo os segundos que formaram as horas

    minutos = tempo/60;
    tempo -= minutos*60; // Removendo os segundos que formaram os minutos

    segundos = tempo; // Os segundos serãoo o que sobrou após tirar as horas e os minutos

    printf("%d %d %d", horas, minutos, segundos);
}
