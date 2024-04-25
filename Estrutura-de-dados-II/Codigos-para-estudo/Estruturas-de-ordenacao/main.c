#include <stdio.h>

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int aux, j;

        aux = a[i]; // Salva o valor que quero INSERIR no seu lugar certo
        j = i-1;

        while (j >= 0 && a[j] > aux ) { // Verifica se o número está em ordem com próximo
            a[j+1] = a[j]; // Coloca o valor maior pra frente
            j--;
        }
    a[j+1] = aux; // INSERE o valor no seu lugar correto da ordenação
    }
}

void bubble_sort (int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i-1; j++) {
            if (a[j] > a[j+1]) { // Troca de lugar, caso não estejam em ordem
                int aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }
}


void quick_sort (int a[], int n) {
    int i = 0, j = n-1;
    int pivo = a[n/2];

    while (i >= j) {
        while (a[i] > pivo){
            i++;
        }
        while (a[j] < pivo) {
            j--;
        }
        if (i <= j) {
            int aux = a[i];
            a[i] = a[j];
            a[j] = aux;

            i++;
            j--;
        }
    }

    if( j > 0){
        quick_sort(a, j+1);
    }
    if (i < n) {
        quick_sort(&a[i], n-i);
    }
        
    
}




int main () {
    int a[4] = {7, 1, 8, 5};
    int n = 4;

    printf("\nAntes:\t");
    for (int i = 0; i < n; i++) {
        printf ("%d ", a[i]);
    }    

    //insertion_sort(a, n);
    //bubble_sort(a, n);
    quick_sort(a, n);


    printf("\nDepois:\t");
    for (int i = 0; i < n; i++) {
        printf ("%d ", a[i]);
    }
    printf("\n\n");
    return 0;
}