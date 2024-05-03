#include <stdio.h>

int main () {

    int m[5][5];
    int maior = -1, x, y;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf ("%d", &m[i][j]);
            if (m[i][j] > maior) {
                maior = m[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("%d %d", x, y);
}
