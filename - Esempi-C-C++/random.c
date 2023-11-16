#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;

    srand(time(NULL));

    // estraggo e stampo numeri a caso tra 1 e 10 finchè non estraggo 10
    do {
        num = rand() % 10 + 1; // rand() % (max-min+1) + min
        printf("%d\n", num);
    } while (num != 10);
}