#include <stdio.h>

int main() {
    int i;
    int n = 10;

    // ciclo col while
    i = 0;
    while (i < n) {
        printf("%d ", i);
        i += 1;
    }

    printf("\n");

    // ciclo equivalente col for
    for (i = 0; i < n; i += 1) {
        printf("%d ", i);
    }

}