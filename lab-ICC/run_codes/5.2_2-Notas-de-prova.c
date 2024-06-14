#include <stdio.h>

float NOTA_DEFAULT = 9999; // Nota para setar inicialmente as notas não preenchidas
int NUMERO_MÁXIMO_DE_ALUNOS = 100; // Núnmero máximo de notas que podem ser cadastradas

int main() {

    float nota[NUMERO_MÁXIMO_DE_ALUNOS];
    int numero_de_alunos = 0;
    int alunos_com_nota_baixa = 0;
    int alunos_com_nota_alta = 0;
    float media_geral = 0;
    float porcentagem_alunos_nota_alta;


    // Colocar valor inicial igual ao valor da "NOTA_DEFAULT" para todas as entradas
    for (int i = 0; i < NUMERO_MÁXIMO_DE_ALUNOS; i++) {
        nota [i] = NOTA_DEFAULT;
    }

    // Lẽ o valor das notas até que apareça a primeira nota negativa, e conta quantos alunos tem de fato
    for (int i = 0; i < NUMERO_MÁXIMO_DE_ALUNOS; i++) {
        scanf("%f", &nota[i]);
        numero_de_alunos ++;
        if (nota [i] < 0) {
            nota[i] = NOTA_DEFAULT;
            numero_de_alunos--;
            break;
        }
    }

    // Ordenar as notas
    for (int i = 0; i < NUMERO_MÁXIMO_DE_ALUNOS; i++) {
        int j;
        float aux;

        aux = nota[i];
        j= i -1;

        while (j >= 0 && nota[j] > aux) {
            nota[j+1] = nota [j];
            j--;
        }
        nota[j+1] = aux;
    }


    // Contar quantos alunos tiveram notas baixas ou altas
    for (int i = 0; i < numero_de_alunos; i++) {
        if(nota[i] < 5) {
            alunos_com_nota_baixa++;
        } 
        else {
            alunos_com_nota_alta++;
        }

        media_geral += nota[i];
    }

    media_geral /= numero_de_alunos;
    porcentagem_alunos_nota_alta = (alunos_com_nota_alta * 100) / numero_de_alunos;

    printf("%d ", alunos_com_nota_alta);
    printf(" %d", alunos_com_nota_baixa);
    printf(" %.2f", media_geral);
    printf(" %.1f", porcentagem_alunos_nota_alta);
}
