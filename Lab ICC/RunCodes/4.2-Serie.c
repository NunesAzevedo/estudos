# include <stdio.h>

int main () {

    // Declara��o de vari�veis
    float
    soma = 0;

    int
    num[50],
    dem[50];

    // C�lculos
    for(int i = 0; i < 50; i++) {
        num[i] = 2*i + 1;
        dem[i] = i + 1;
        soma += (num[i]*1.0) / (dem[i]*1.0);
        //printf ("%d / %d\n", num[i], dem[i]); // print de teste
    }
    printf ("%f", soma); // Resposta final
}
