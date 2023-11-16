// 5.2	Scrivi una funzione che conta e restituisce il numero di righe di un file. Scrivi poi
// un'altra funzione che calcola per ogni riga il numero di parole contenute nella riga. I valori
// vanno inseriti in un array o un vettore da restituire al main.

#include <stdio.h>
#include <string.h>

#define N 200
#define MAXRIGHE 10000

int numeroRighe(char nomefile[]) {
    FILE* fp;
    char riga[N];
    int nrighe;

    fp = fopen(nomefile, "r");
    if (fp == NULL) {
        printf("Il file non è stato aperto correttamente in lettura\n");
        return 1;
    }

    for (nrighe = 0; !feof(fp) && nrighe < MAXRIGHE; nrighe++) {
        fgets(riga, N, fp);
    }

    return nrighe;
}

int numeroCaratteriPerRiga(char nomefile[], int nlettere[]) {
    FILE* fp;
    char riga[N];
    int nrighe;

    fp = fopen(nomefile, "r");
    if (fp == NULL) {
        printf("Il file non è stato aperto correttamente in lettura\n");
        return 1;
    }

    for (nrighe = 0; !feof(fp); nrighe++) {
        fgets(riga, N, fp);
        nlettere[nrighe] = strlen(riga) - 1; // metto -1 per togliere '\n' finale
    }

    return 0;
}

int numeroParolePerRiga(char nomefile[], int nparole[]) {
    FILE* fp;
    char riga[N];
    int nrighe;
    char *token;

    fp = fopen(nomefile, "r");
    if (fp == NULL) {
        printf("Il file non è stato aperto correttamente in lettura\n");
        return 1;
    }

    for (nrighe = 0; !feof(fp); nrighe++) {
        fgets(riga, N, fp);
        nparole[nrighe] = 0;

        if (riga[0] == '\n') {
            continue;
        }

        token = strtok(riga, " '");
        while (token != NULL) {
            token = strtok(NULL, " '");
            nparole[nrighe] += 1;
        }
    }

    return 0;
}

int main() {
    int nrighe, ncaratteri[MAXRIGHE], nparole[MAXRIGHE];
    int i;
    char nomefile[] = "5-03.txt";
    
    nrighe = numeroRighe(nomefile);
    numeroCaratteriPerRiga(nomefile, ncaratteri);

    printf("Le righe sono %d\n\n", nrighe);
    
    printf("per ogni riga e' presente il seguente numero di caratteri compresi spazi e punteggiatura ma non l'a capo:\n");

    for (i = 0; i < nrighe && i < MAXRIGHE; i++) {
        printf("%3d: %3d\n", i+1, ncaratteri[i]);
    }
    printf("\n\n");

    numeroParolePerRiga(nomefile, nparole);
    printf("per ogni riga e' presente il seguente numero di parole:\n");
    for (i = 0; i < nrighe && i < MAXRIGHE; i++) {
        printf("%3d: %2d\n", i+1, nparole[i]);
    }

    return 0;
}