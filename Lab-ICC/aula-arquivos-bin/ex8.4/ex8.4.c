#include <stdio.h>


typedef struct {
    int num_venda;
    char cliente[50];
    char produto[50];
    float valor;
} registro_de_vendas;


#define n 5

int main () {

    FILE *arq;
    registro_de_vendas vendas[n];
    int count = 0;

    int count_vendas = 0;
    printf("\nInsira os dados das vendas:\n");
    for (int i= 0; i < n; i++) {
        
        vendas->num_venda = count+1;

        printf("\nNome do cliente:\t");
        scanf("%s",vendas->cliente);

        printf("Produto:\t");
        scanf("%s", vendas->produto);

        printf("O valor do produto\t");
        scanf("%f", vendas->valor);
    }


    arq = fopen("vendas.bin", "wb+");

    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo\n");
        return 1;
    }

    fwrite(vendas, sizeof(vendas), 5, arq);
    fclose(arq);

    return 0;
}