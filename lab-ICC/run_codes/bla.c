#include <stdio.h>

int main () {

    for (int i = 0; i > -1; i++) {
        printf("%d ", i);
        if (i == 99) {
            break;
        }
    }

    return 0;
}