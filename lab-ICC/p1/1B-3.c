#include <stdio.h>

int main () {

    int n;
    float pi = 0, den = 0;

    scanf("%d", &n);

    int sinal = -1;
    for (int i = 0; i < n; i++) {
       sinal = sinal*(-1);
       den = (2*i + 1);
       pi = pi + sinal*(4/den);

       //printf("sinal:\t %d\n", sinal);
       //printf("den:\t %f\n", den);
       //printf("pi:\t %f\n", pi);
       //printf("\n");
    }
    printf("%f", pi);
}
