#include <stdio.h>

void merge (int a[], int p, int q, int r) {

    // Dividindo o vetor inicial em 2
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    for (int i =0; i < n1; i++) {
        L[i] = a[p + i];
    
        for (int j = 0; j < n2; j++) {
            M[j] = a[q + 1 + j];
        }
    }

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if ( L[i] <= M[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = M[j];
            j++;
        }
        k++;
    }

    while (j < n2) {
        a[k] = M[j];
        j++;
        k++;
    }

}

void merge_sort (int a[], int l, int r) {
    if (l < r) {
        // m é o pivô
        int m = l + (r - l) / 2;

        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);

        merge(a, l, m, r);
    }
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
    int n = sizeof (a) / sizeof (a[0]);

    printf("\nAntes da ordenacao:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    //merge_sort (a, 0, n-1);
    selection_sort(a, n);
    printf("\nDepois da ordenacao:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");


}
