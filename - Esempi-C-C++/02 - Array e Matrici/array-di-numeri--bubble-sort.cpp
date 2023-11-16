#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int i, j, tmp, v[N], scambiato;
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
    scambiato = 1;
    for (i = 0; i < N - 1 && scambiato; i++) {
        scambiato = 0;
        for (j = 0; j < N - 1 - i; j++) {
            if (v[j] > v[j + 1]) {          // così ordina in ordine crescente, se si cambia > con < si ottiene decrescente
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                scambiato = 1;
            }
        }
    }

    printf("Stampa dopo l'ordinamento:\n");
    for (i = 0; i < N; i++) {  
        printf("%d ", v[i]);
    }
    printf("\n\n");
}