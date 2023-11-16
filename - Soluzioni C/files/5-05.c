// Scrivi un programma che legga un file di testo
// e che scriva in un secondo file, lo stesso testo modificato in modo che tutte
// le lettere siano minuscole. Il file di testo iniziale generalo tu come vuoi.

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fpr, *fpw;
    char lettera;

    fpr = fopen("5-05-in.txt", "r");
    if (fpr == NULL) {
        printf("File non trovato\n\n");
        return 1;
    }

    fpw = fopen("5-05-out.txt", "w");
    if (fpw == NULL) {
        printf("File non trovato\n\n");
        return 1;
    }

    while (!feof(fpr)) {
        fscanf(fpr, "%c", &lettera);
        lettera = tolower(lettera);
        printf("%c", lettera);
        fprintf(fpw, "%c", lettera);
    }





}