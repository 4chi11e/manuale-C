// Scrivi e usa una funzione che conta il numero di caratteri contenuti in un file

#include <stdio.h>

int contaLettere(char nomefile[]) {
    FILE *fp;
    int n;
    char lettera;

    fp = fopen(nomefile, "r");
    if (fp == NULL) {
        return -1;
    }

    n = 0;
    while (!feof(fp)) {
        fscanf(fp, "%c", &lettera);
        if (lettera != '\n' && lettera != ' ') {
            n++;
        }
        // n++;
    }
    return n;
}
int main() {
    char nomefile[] = "5-02-conta_caratteri.txt";
    int nlettere = contaLettere(nomefile);
    if (nlettere < 0) {
        printf("Il file non esiste.\n");
    } else {
        printf("Il file %s contiene %d lettere\n", nomefile, nlettere);
    }
}