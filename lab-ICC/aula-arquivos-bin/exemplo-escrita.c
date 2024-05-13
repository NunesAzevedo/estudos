#include <stdio.h>

void main (){
    FILE *arq;
    int veta[5]={1,3,5,7,9}, vetb[5], i;


    arq = fopen("test.bin", "wb+");
    if(arq==NULL) printf("\nErro abrindo arquivo.\n");

    fwrite(&veta, sizeof(int), 5, arq);
    fseek(arq , 0, SEEK_SET);
    fread(&vetb, sizeof(int), 5, arq);fread(&vetb, sizeof(int), 5, arq);
    for(i=0; i<5; i++)
    printf("Vetb[%i]: %i\n", i, vetb[i]);
    getchar();
    fclose(arq);
}