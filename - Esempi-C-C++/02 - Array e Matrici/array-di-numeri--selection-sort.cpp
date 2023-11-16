#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int i, j, tmp, posmin, posmax, v[N];
    srand(time(NULL));

    for (i = 0; i < N; i++) {
        v[i] = rand() % 10;
    }

    printf("Stampa prima dell'ordinamento:\n");
    for (i = 0; i < N; i++) {  
        printf("%d ", v[i]);
    }
    printf("\n\n");

    // ordinamento
    for (i = 0; i < N - 1; i++) {
        posmin = i;
        for (j = i + 1; j < N; j++) {
            if (v[j] < v[posmin]) {         // così ordina in ordine crescente, se si cambia < con > si ottiene decrescente
                posmin = j;
            }
        }
        tmp = v[i];
        v[i] = v[posmin];
        v[posmin] = tmp;
    }

    printf("Stampa dopo l'ordinamento:\n");
    for (i = 0; i < N; i++) {  
        printf("%d ", v[i]);
    }
    printf("\n\n");
}