// Leggi le informazioni riguardanti una serie di libri dal file allegato "5-12-scrittori.txt" e:
// a. carica i dati in un array di libri (definisci un'apposita struttura libro)
// b. ordina i libri per data di scrittura e riscrivili in un altro file nello stesso formato del
// file originale
// c. scrivi e usa una funzione che riceve i dati già caricati e che restituisce il
// libro più recente 
// d. scrivi e usa una funzione che restituisca il secolo in cui sono stati
// scritti più libri

#include <stdio.h>
#include <string.h>

#define N 200
#define M 100
#define SECOLI 21

typedef struct {
    char autore[M];
    char titolo[M];
    int anno;
} libro;

void stampaElenco(libro elenco[], int nlibri){
    int i;
    for (i = 0; i < nlibri; i++) {
        printf("%s;%s;%d\n", elenco[i].titolo, elenco[i].autore, elenco[i].anno);
    }
}

void ordinaPerData(libro elenco[], int nlibri) {
    int i, j;
    libro tmp;

    for (i = 0; i < nlibri - 1; i++) {
        for (j = 0; j < nlibri - 1 - i; j++) {
            if (elenco[j].anno > elenco[j+1].anno) {
                tmp = elenco[j];
                elenco[j] = elenco[j+1];
                elenco[j+1] = tmp;
            }
        }
    }
}

libro piuRecente(libro elenco[], int nlibri) {
    int maxi, i;

    maxi = 0;
    for (i = 1; i < nlibri; i++) {
        if (elenco[i].anno > elenco[maxi].anno){
            maxi = i;
        }
    }

    return elenco[maxi];
}

int secoloConPiuLibri(libro elenco[], int nlibri) {
    int secolo, maxsecolo;
    int libri_per_secolo[SECOLI];
    int i;

    for (i = 0; i < SECOLI; i++) {
        libri_per_secolo[i] = 0;
    }

    maxsecolo = 0;
    for (i = 0; i < nlibri; i++) {
        secolo = elenco[i].anno / 100;
        // printf("  %d ", secolo);
        libri_per_secolo[secolo] += 1;
        // printf("%2d\n", libri_per_secolo[secolo]);
        if (libri_per_secolo[secolo] > libri_per_secolo[maxsecolo]) {
            maxsecolo = secolo;
        }
    }

    return maxsecolo * 100;
}

int main() {
    FILE *fp;
    libro elenco[N];
    char riga[N];
    char *token;
    int nlibri;
    libro recente;

    fp = fopen("5-14-scrittori-in.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    for (nlibri = 0; !feof(fp) && nlibri < N; nlibri++) {
        fgets(riga, N, fp);
        if (riga[0] == '\n') {
            break;
        }
        // printf("%s", riga);
        token = strtok(riga, ";");
        strcpy(elenco[nlibri].titolo, token);
        token = strtok(NULL, ";");
        strcpy(elenco[nlibri].autore, token);
        token = strtok(NULL, ";");
        sscanf(token, "%d", &elenco[nlibri].anno);
    }

    // printf("\n%d\n\n", nlibri);
    stampaElenco(elenco, nlibri);

    ordinaPerData(elenco, nlibri);

    printf("\n\n");
    stampaElenco(elenco, nlibri);

    recente = piuRecente(elenco, nlibri);
    printf("\n\nIl libro piu' recente: %s, %s, %d\n\n", recente.titolo, recente.autore, recente.anno);

    printf("Il secolo col maggior numero di libri e': %d\n\n", secoloConPiuLibri(elenco, nlibri));
}