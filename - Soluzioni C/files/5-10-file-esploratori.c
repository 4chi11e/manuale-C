#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 50

typedef struct {
    char nome[M];
    char cognome[M];
    int anno_nascita;
    int anno_morte;
} esploratore;

void ordinaEsploratoriPerNome(esploratore lista[], int n) {
    int i, j;
    esploratore tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0 ||
                (strcmp(lista[j].nome, lista[j + 1].nome) == 0 &&
                 strcmp(lista[j].cognome, lista[j + 1].cognome) > 0)) {
                tmp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = tmp;
            }
        }
    }
}

int main() {
    FILE* fp;
    esploratore lista[N];
    int nesploratori = 0, i;

    fp = fopen("5-10-file-esploratori.txt", "r");
    if (fp == NULL) {
        printf("Impossibile aprire il file\n");
        // system("pause");
        return 1;
    }

    for (nesploratori = 0; !feof(fp) && nesploratori < N; nesploratori += 1) {
        fscanf(fp, "%s %s %d %d", lista[nesploratori].nome,
               lista[nesploratori].cognome, &lista[nesploratori].anno_nascita,
               &lista[nesploratori].anno_morte);
               
        printf("%s %s %d %d\n", lista[nesploratori].nome,
               lista[nesploratori].cognome, lista[nesploratori].anno_nascita,
               lista[nesploratori].anno_morte);
    }
    fclose(fp);

    ordinaEsploratoriPerNome(lista, nesploratori);

    fp = fopen("5-10-file-esploratori-out.txt", "w");
    if (fp == NULL) {
        printf("Impossibile aprire il file\n");
        // system("pause");
        return 1;
    }

    for (i = 0; i < nesploratori; i++) {
        fprintf(fp, "%s %s %d %d\n", lista[i].nome, lista[i].cognome,
               lista[i].anno_nascita, lista[i].anno_morte);
    }
}