# include <stdio.h>

int main () {

    // Declara��o de vari�veis

    // Vari�veis de entrada
    int
    A = 0, // Menor
    B = 0, // Do meio
    C = 0; // Maior

    // Vari�veis auxiliares
    int
    A2 = 0,
    B2 = 0,
    C2 = 0;


    // Leitura dos valores
    scanf ("%d", &A);
    scanf ("%d", &B);
    scanf ("%d", &C);

    // Ordena��o

        if (A >= B && A >= C) { // Caso onde A � o maior
            C2 = A;
            if (B >= C) {
                B2 = B;
                A2 = C;
            }else {
                B2 = C;
                A2 = B;
            }
        }else if (B >= A && B >= C) { // Caso onde B � o maior
            C2 = B;
            if (A >= C) {
                B2 = A;
                A2 = C;
            }else {
                B2 = C;
                A2 = A;
            }
        } else if (C >= A && C >= B) { // Caso onde C � o maior
            C2 = C;
            if (A >= B) {
                B2 = A;
                A2 = B;
            }else {
                B2 = B;
                A2 = A;
            }
        }


    // Realoca��o das vari�veis
    A = A2;
    B = B2;
    C = C2;

    A2 = 0;
    B2 = 0;
    C2 = 0;

    printf ("%d %d %d", A, B, C);
    return 0;
}
