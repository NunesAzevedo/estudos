
#include <stdio.h>

void merge (float *a, int p, int m, int u, float *aux) {// vetor, primeira posição, posição do meio, ultima posição e vetor auxiliar

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

void merge_sort (float *a, int p, int u, float *aux) {

    if ( p < u ) {
        int m = (p + u) /2;

        merge_sort(a, p, m, aux);
        merge_sort(a, m + 1, u, aux);
        merge(a, p, m, u, aux);
    }
}




void swamp (float *a, float *b) {
    float aux = *a;
    *a = *b;
    *b = aux;
}

void selection_sort (float a[], int n) {
    for (int step = 0; step < n -1; step++) {
        int min_idx = step;
        for (int i = step +1; i < n; i++) {
            if (a[i] < a[min_idx]) min_idx = i;
        }

        swamp(&a[min_idx], &a[step]);
    }
}



struct aluno {
float *nota;      //a
float *reprovacoes; //b
char *nome;   //c
};



int main () {
    
    int T, N, M, x;

    do { //T == 1: Selection sort / T == 2: Merge sort 
        scanf("%d", &T);
    } while (!(T == 1 || T == 2));

    scanf("%d %d", &N, &M); //Alunos que aplicaram e Bolsas disponíveis

    struct aluno aluno[N];
    struct aluno aux[N];
    struct aluno aux2[N];
    struct aluno aprovados[M];


    // Leitura dos alunos
    for (int i = 0; i < N; i++) {
        scanf("%f %f %s", &aluno[i].nota, &aluno[i].reprovacoes, &aluno[i].nome);
    }
    
    if (T == 1) {//selection sort
        selection_sort(aluno->nota, N); // Ordena por nota
        selection_sort(aluno->reprovacoes, N); // Ordena por reprovções
        for (int i = 0; i < N; i++) {
            aux[i].reprovacoes = aluno[N - i].reprovacoes;
        }

        swamp(aluno->reprovacoes, aux->reprovacoes); // Ordena decrescente por reprovacoes

        if (N > M) {
            for (int i = 0; i < M; i++) {
                aprovados[i] = aluno[i];
                x = M;
            }
        } else {
            for (int i = 0; i < N; i++) {
                aprovados[i] = aluno[i];
                x = N;
            }
        }

        printf("\n%d\n", x);
        for (int i = 0; i < x; i++) {
        printf("\n%s\n", aluno[i].nome);
        }
    }

        if (T == 2) {//merge sort
        merge_sort(aluno->nota, 0, N, aux2); // Ordena por nota
        merge_sort(aluno->reprovacoes, 0, N, aux2); // Ordena por reprovções
        for (int i = 0; i < N; i++) { // Inverte a ordem
            aux[i].reprovacoes = aluno[N - i].reprovacoes;
        }
        
        swamp(aluno->reprovacoes, aux->reprovacoes); // Ordena decrescente por reprovacoes

        if (N > M) {
            for (int i = 0; i < M; i++) {
                aprovados[i] = aluno[i];
                x = M;
            }
        } else {
            for (int i = 0; i < N; i++) {
                aprovados[i] = aluno[i];
                x = N;
            }
        }

        printf("\n%d\n", x);
        for (int i = 0; i < x; i++) {
        printf("\n%s\n", aluno[i].nome);
        }
    }



}