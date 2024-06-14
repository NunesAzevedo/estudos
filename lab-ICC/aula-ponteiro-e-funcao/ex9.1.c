#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    int *v1 = (int*)( malloc(10 * sizeof(int) ) );

    if (v1 == NULL) {
        printf("Erro ao fazer alocacao");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
    scanf("%d",&v1[i]);
    }

    int *v2 = (int*)(malloc(20*sizeof(int)));

    if (v2 == NULL) {
        printf("Erro ao fazer alocacao");
        return 1;
    }    

    memcpy(v2, v1, 10*sizeof(int));


    for (int i = 10; i < 20; i++) {
    scanf("%d",&v2[i]);
    }

    printf("\n");
    for (int i = 0; i < 20; i++){
        printf("%d ", v2[i]);
    }

    free(v1);

    printf("\n");
    for (int i = 0; i < 20; i++){
        printf("%d ", v2[i]);
    }

    free(v2);

    printf("\n");
    for (int i = 0; i < 20; i++){
        printf("%d ", v2[i]);
    }
    printf("\n");
    return 0;
}


