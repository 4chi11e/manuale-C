// Scrivi e usa una funzione che legga un file e scriva in un altro file tutte le parole del primo
// file in ordine alfabetico

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 1000
#define M 100

int generaFileOrdinato(char nomefileinput[], char nomefileoutput[]) {
    FILE *fp;
    char parole[N][M];
    char tmp[M], parola1[M], parola2[M];
    int nparole;
    int i, j, k;

    fp = fopen(nomefileinput, "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 0;
    }

    for (nparole = 0; !feof(fp) && nparole < N; nparole++) {
        fscanf(fp, "%s", parole[nparole]);
    }
    fclose(fp);

    for (i = 0; i < nparole - 1; i++) {
        for (j = 0; j < nparole - 1 - i; j++) {
            strcpy(parola1, parole[j]);
            for (k = 0; k < strlen(parola1); k++) {
                parola1[k] = tolower(parola1[k]);
            }
            strcpy(parola2, parole[j+1]);
            for (k = 0; k < strlen(parola2); k++) {
                parola2[k] = tolower(parola2[k]);
            }
            if (strcmp(parola1, parola2) > 0) {
                strcpy(tmp, parole[j]);
                strcpy(parole[j], parole[j+1]);
                strcpy(parole[j+1], tmp);
            }
        }
    }

    fp = fopen(nomefileoutput, "w");
    if (fp == NULL) {
        printf("Errore apertura file in scrittura\n");
        return 0;
    }

    for (i = 0; i < nparole; i++) {
        fprintf(fp, "%s\n", parole[i]);
    }
}

int main() {
    generaFileOrdinato("5-04-in.txt", "5-04-out.txt");
    

}