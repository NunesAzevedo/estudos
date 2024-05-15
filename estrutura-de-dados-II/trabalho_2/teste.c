#include <stdio.h>
#include <stdlib.h>



void merge (int *a, int p, int m, int u, int *aux) {// vetor, primeira posição, posição do meio, ultima posição e vetor auxiliar

    int m2 = m+1;
    int c = 0;

    while (p <= m && m2 <= u) {

        if ( a[p] <= a[m2] ) aux[c++] = a[p];
        else aux[c++] = a[m2++];
    }

    while (p <= m) {
        aux[c++] = a[p++];
    }

    while (m2 <= u) {
        aux[c++] = a[m2++];
    }

    for (int i = 0; i < c; i++) {
        a[p + 1] = aux[i];
    }
}

void merge_sort (int *a, int p, int u, int *aux) {

    if ( p < u ) {
        int m = (p + u) /2;

        merge_sort(a, p, m, aux);
        merge_sort(a, m + 1, u, aux);
        merge(a, p, m, u, aux);
    }
}






void swamp (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// void swamp (int a[], int b[], int size) {
//     // float aux = *a;
//     // *a = *b;
//     // *b = aux;

//     int aux[size] = a[size];
//     a[size] = b[size];
//     b[size] = aux[size];
// }

void selection_sort (int a[], int n) {
    for (int step = 0; step < n -1; step++) {
        int min_idx = step;
        for (int i = step +1; i < n; i++) {
            if (a[i] < a[min_idx]) min_idx = i;
        }

        swamp(&a[min_idx], &a[step], n);
    }
}





int main () {

    int a [5] = {8, 4, 3, 2, 9};
    int size = 5;
    int aux [5];

    printf("\nAntes da ordenacao:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
   // merge_sort(a, 0,size -1, aux);

    selection_sort(a, size);
    printf("\nDepois da ordenacao:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");


}
