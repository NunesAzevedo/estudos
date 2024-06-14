#include <stdio.h>
#include <stdlib.h>

int main () {

    int quantidade_de_alunos;
    float soma = 0.0, media = 0.0;

    scanf("%d", &quantidade_de_alunos);

    float *notas = (float*)malloc(quantidade_de_alunos*sizeof(float));
    if (notas == NULL) {
        printf("Ero ao alocar a memoria");
        return 1;
    }

    for (int i = 0; i < quantidade_de_alunos; i++) {
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / (quantidade_de_alunos*1.0);

    printf("%f", media);

    free(notas);
    

    return 0;
}