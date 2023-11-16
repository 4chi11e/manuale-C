// in questo secondo esempio faccio vedere cosa fare se possono variare anche il
// numero di frasi separate dai : in partica faccio lo stesso procedimento due
// volte, prima con le frasi separate da :, poi rifaccio tutto all'intero della
// singola frase coi numeri

#include <stdio.h>
#include <string.h>

#define N 100

int main() {
    char frase[] = "Frase di prova: con dei separatori: 1 2 3 4";
    // char frase_numeri[N];
    char parti[N][N];
    int numeri[N];
    int quanti, i;

    // qui devo prima legggere il numero massimo di frasi separate da : e mi
    // segno quante cose leggo in 'quanti'
    quanti = sscanf(frase, "%[^:]: %[^:]: %[^:]: %[^:]: %[^:]: %[^:]", parti[0],
                    parti[1], parti[2], parti[3], parti[4], parti[5]);
    printf("%d\n", quanti);
    for (i = 0; i < quanti - 1; i++) {
        printf("%s: ", parti[i]);
    }

    // poi prendo l'ultima frase e faccio la stessa cosa coi numeri
    quanti = sscanf(parti[quanti - 1], "%d %d %d %d %d", &numeri[0], &numeri[1],
                    &numeri[2], &numeri[3], &numeri[4]);
    for (i = 0; i < quanti; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");
}