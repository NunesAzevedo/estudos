#include <stdio.h>
#include <stdlib.h>

// void merge (int a[], int p, int q, int r) {

//     // Dividindo o vetor inicial em 2
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     int L[n1], M[n2];

//     for (int i =0; i < n1; i++) {
//         L[i] = a[p + i];
    
//         for (int j = 0; j < n2; j++) {
//             M[j] = a[q + 1 + j];
//         }
//     }

//     int i = 0, j = 0, k = p;

//     while (i < n1 && j < n2) {
//         if ( L[i] <= M[j]) {
//             a[k] = L[i];
//             i++;
//         } else {
//             a[k] = M[j];
//             j++;
//         }
//         k++;
//     }

//     while (j < n2) {
//         a[k] = M[j];
//         j++;
//         k++;
//     }

// }

// void merge_sort (int a[], int l, int r) {
//     if (l < r) {
//         // m é o pivô
//         int m = l + (r - l) / 2;

//         merge_sort(a, l, m);
//         merge_sort(a, m + 1, r);

//         merge(a, l, m, r);
//     }
// }


int merge (int a[], int size_a, int b[], int size_b) {

    //size_a = sizeof(a) / sizeof( a[0] );
    //size_b = sizeof(b) / sizeof( b[0] );
    
    int c [size_a + size_b]; //Vetor em que serão "fundidos" os 2 vetores anteriores a ele
    
    int i = 0;
    int j = 0;

    while (i < size_a && j < size_b) { //Enquanto os 2 vetores tiverem elementos
        if (a[i] < b[j]) {
            c[i + j] = a [i];
            i++;
        } else {
            c [i + j] = b[j];
            j++;
        }
    }

    //Quando um dos vetores "esvaziar", preencher o resto com o que sobrou do outro
    if (i == size_a) {//Se a esvaziar "primeiro"
        for (j; j < size_b; j++) {
            c [i + j] = b[j];
        }
    }

    if (j == size_b) {//Se b esvaziar "primeiro"
        for (i; i < size_a; i++) {
            c [i + j] = a[i];
        }
    }
    
    return c [size_a + size_b];
}


int merge_sort (int a[], int size) {
    int size_left = size/2;
    int size_righ = size - (size/2);

    int left [size_left], right [size_righ]; //Dividir em 2 vetores

    //Fazer a divisão de cada um dos novos vetores
    //left [size_left] = merge_sort(left, sizeof(left) / sizeof(left[0]) );
    //right [size_righ] = merge_sort(right, sizeof(right) / sizeof(right[0]) );

    left [size_left] = merge_sort(left, size_left );
    right [size_righ] = merge_sort(right, size_righ );



    //return merge ( left, sizeof(left) / sizeof(left[0]), right, sizeof(right) / sizeof(right[0]) );
    return merge (left, size_left, right, size_righ);
}




















void swamp (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort (int a[], int n) {
    for (int step = 0; step < n -1; step++) {
        int min_idx = step;
        for (int i = step +1; i < n; i++) {
            if (a[i] < a[min_idx]) min_idx = i;
        }

        swamp(&a[min_idx], &a[step]);
    }
}





int main () {

    int a [5] = {8, 4, 3, 2, 9};
    int size = sizeof (a) / sizeof (a[0]);

    printf("\nAntes da ordenacao:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    merge_sort (a, size);
    //selection_sort(a, size);
    printf("\nDepois da ordenacao:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");


}
