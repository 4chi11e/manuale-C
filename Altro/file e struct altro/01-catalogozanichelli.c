// leggo e carico in una struttura i dati presi dal catalogo zanichelli, per ora mi fermo a codice, autori e titolo.
// poi ordino tutto per titolo e ristampo in un altro file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <algorithm>

#define MAXAUTORI 20
#define LUNGMAXRIGA 1000
#define LUNGMAXSTRINGA 100
#define MAXNUMLIBRI 10

typedef struct {
    char isbn[15];
    char autori[MAXAUTORI][LUNGMAXSTRINGA];
    int nautori;
    char titolo[LUNGMAXSTRINGA];
    int anno;
} libro;

void libroToString(libro l, char *stringa) {
    int i;

    strcpy(stringa, "");
    sprintf(stringa, "%s\t\"", l.isbn);
    for (i = 0; i < l.nautori; i++) {
        sprintf(stringa, "%s%s", stringa, l.autori[i]);
        if (i < l.nautori - 1) {
            sprintf(stringa, "%s-", stringa);
        }
    }
    sprintf(stringa, "%s\"", stringa);
    sprintf(stringa, "%s\t\"%s\"", stringa, l.titolo);
    sprintf(stringa, "%s\t%d", stringa, l.anno);
}

int confrontoTitolo(const void * a, const void * b) {
    return strcmp(((libro*)a)->titolo, ((libro*)b)->titolo);
}

void ordinaPerTitolo(libro elenco[], int nlibri) {
    // sort(elenco, elenco+nlibri, confrontoTitolo);
    qsort(elenco, nlibri, sizeof(libro), confrontoTitolo);
}

int main() {
    FILE *fp;
    libro elenco[MAXNUMLIBRI];
    char riga[LUNGMAXRIGA];
    char strautori[LUNGMAXRIGA];
    char resto[LUNGMAXRIGA];
    char prec[LUNGMAXRIGA];
    char *pezzo;
    char lettera;
    int nlibri, i;

    // printf("Inizio\n\n");

    fp = fopen("CatalogoZanichelli.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    // prima riga con le instestazioni
    fgets(riga, LUNGMAXRIGA, fp);
    // printf("%s\n", riga);

    for (nlibri = 0, fgets(riga, LUNGMAXRIGA, fp);
         !feof(fp) && nlibri < MAXNUMLIBRI;
         nlibri++, fgets(riga, LUNGMAXRIGA, fp)) {
        
        // printf("%s", riga);

        // isbn
        pezzo = strtok(riga, "\t\"");
        strcpy(elenco[nlibri].isbn, pezzo);

        // autori
        pezzo = strtok(NULL, "\"");
        strcpy(strautori, pezzo);
        // pezzo = strtok(NULL, "\t");
        pezzo = strtok(NULL, "\n");
        strcpy(resto, pezzo);

        pezzo = strtok(strautori, "-");
        for (elenco[nlibri].nautori = 0; pezzo != NULL;
             elenco[nlibri].nautori += 1) {
            strcpy(elenco[nlibri].autori[elenco[nlibri].nautori], pezzo);
            pezzo = strtok(NULL, "-");
        }

        // titolo
        pezzo = strtok(resto, "\"\t");
        // pezzo = strtok(NULL, "\"\t");
        strcpy(elenco[nlibri].titolo, pezzo);

        // anno
        pezzo = strtok(NULL, "\t");
        while (pezzo != NULL) {
            strcpy(prec, pezzo);
            pezzo = strtok(NULL, "\t");
        }
        strcpy(resto, prec);
        pezzo = strtok(resto, ", \"");
        while (pezzo != NULL) {
            strcpy(prec, pezzo);
            pezzo = strtok(NULL, ", \"");
        }
        printf("%s\n", prec);
        sscanf(prec, "%d", &(elenco[nlibri].anno));

        // stampo i dati per vedere se li ho letti bene
        // libroToString(elenco[nlibri], riga);
        // printf("%s%s\n\n", riga, resto);
    }
    fclose(fp);

    ordinaPerTitolo(elenco, nlibri);

    fp = fopen("CatalogoZanichelli-ordinato.txt", "w");
    if (fp == NULL) {
        printf("Errore nell'apertura in scrittura\n");
        return 1;
    }

    for (i = 0; i < nlibri; i++) {
        libroToString(elenco[i], riga);
        fprintf(fp, "%s\n", riga);
    }

    fclose(fp);
}