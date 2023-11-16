// 5.8	Scrivi una funzione parametrica in grado di modificare un file di testo di nome
// "5-08.txt" letto da disco in modo tale che, se l'ultimo elemento della linea è una virgola, la
// linea successiva venga eliminata

#include <stdio.h>
#include <string.h>

#define N 1000
#define M 100

int main() { 
    char righe[N][M];
    int nrighe, i;
    FILE *fp;

    fp = fopen("5-08.txt", "r");
    if (fp == NULL) {
        printf("File in lettura non trovato\n");
        return 1;
    }

    for (nrighe = 0; nrighe < N && !feof(fp); nrighe++) {
        fgets(righe[nrighe], M, fp);
    }

    fclose(fp);

    fp = fopen("5-08-out.txt", "w");
    if (fp == NULL) {
        printf("Errore nell'apertura in scrittura\n");
        return 1;
    }

    for (i = 0; i < nrighe; i++) {
        fprintf(fp, "%s", righe[i]);
        while(righe[i][strlen(righe[i])-2] == ',') {
            i++;
        }
    }
    fclose(fp);

}