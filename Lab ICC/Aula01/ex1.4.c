#include <stdio.h>

int main () {

    //Database
    float
    valor_lata = 20,
    area_lata = 5,
    hora_trabalho = 30,
    area_pintada_por_hora = 10;


    //Declaração de variáveis
    int
    num_paredes = 0;

    float
    altura = 0,
    largura = 0;


    //Começo do programa

    //Coleta de dados pelo usuário
    printf ("\nALtura da parede: \n"); scanf("%2.f", &altura);
    printf ("\nLargura da parede: \n"); scanf ("%2.f", &largura);
    printf("\nNúmero de paredes: \n"); scanf("%d", &num_paredes);

    //Cálculo do orçamento
    float
    area_pintada = 0,
    custo_total = 0;

    int
    numero_de_latas = 0;

    area_pintada = altura * largura * num_paredes;

    //numero_de_latas = 

}