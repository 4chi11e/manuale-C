#include <stdio.h>

int main() {
    int i;

    printf("Esempio col while:\n");
    i = 0;
    while (1) {
        if (i >= 10) {
            break;
        } else {
            printf("%d ", i);
        }
        i++;
    }

    printf("\n\nEsempio col for:\n");
    for (i = 0; i < 100; i++) {
        if (i >= 10) {
            break;
        } else {
            printf("%d ", i);
        }
    }
}