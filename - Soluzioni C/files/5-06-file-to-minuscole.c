// Scrivi un programma che legga un file di testo e che aggiunga alla fine di
// tale file, dopo un paio di righe vuote, lo stesso testo modificato in modo
// che tutte le lettere siano minuscole. Il file di testo iniziale generalo tu
// come vuoi. Attento a fare in modo che se il programma viene eseguito più
// volte, le righe da considerare sono solo quelle iniziali.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define M 100

int main() {
    FILE *fpr, *fpa;
    char lettera, riga[M];
    int righevuote, i;

    fpr = fopen("5-06-testo.txt", "r");
    if (fpr == NULL) {
        printf("Il file non è stato aperto correttamente\n");
        return 1;
    }
    fpa = fopen("5-06-testo.txt", "a");
    if (fpa == NULL) {
        printf("Il file non è stato aperto correttamente\n");
        return 2;
    }

    fprintf(fpa, "\n\n\n");
    righevuote = 0;
    while(!feof(fpr) && righevuote < 2) {
        fgets(riga, M, fpr);
        if (riga[0] == '\n') {
            righevuote += 1;
        } else {
            righevuote = 0;
            for (i = 0; i < strlen(riga); i++) {
                lettera = tolower(riga[i]);
                // printf("%c", lettera);
                fprintf(fpa, "%c", lettera);
            }
        }
    }
    fclose(fpr);
    fclose(fpa);

}