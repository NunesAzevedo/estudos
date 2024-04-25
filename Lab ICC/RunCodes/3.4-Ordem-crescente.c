# include <stdio.h>

int main () {

    // Declaração de variáveis

    // Variáveis de entrada
    int
    A = 0, // Menor
    B = 0, // Do meio
    C = 0; // Maior

    // Variáveis auxiliares
    int
    A2 = 0,
    B2 = 0,
    C2 = 0;

    // Variável de status
    int status = 0; // 0: Não verificado ; 1: Verificado

    // Leitura dos valores
    scanf ("%d", &A);
    scanf ("%d", &B);
    scanf ("%d", &C);

    // Ordenação

    if (status == 0){
        if (A >= B && A >= C) { // Caso onde A é o maior
            C2 = A;
            if (B >= C) {
                B2 = B;
                A2 = C;
            }else {
                B2 = C;
                A2 = B;
            }
        }
    status = 1;
    }

    if (status == 0){
        if (B >= A && B >= C) { // Caso onde B é o maior
            C2 = B;
            if (A >= C) {
                B2 = A;
                A2 = C;
            }else {
                B2 = C;
                A2 = A;
            }
        }
    status = 1;
    }

    if (status == 0){
        if (C >= A && C >= B) { // Caso onde C é o maior
            C2 = C;
            if (A >= B) {
                B2 = A;
                A2 = B;
            }else {
                B2 = B;
                A2 = A;
            }
        }
    status = 1;
    }


    // Realocação das variáveis
    A = A2;
    B = B2;
    C = C2;

    A2 = 0;
    B2 = 0;
    C2 = 0;

    printf ("%d %d %d", A, B, C);
    return 0;
}
