// Scrivi un programma che legga i dati contenuti in un
// file di testo (testo riportato di seguito) e li inserisca in opportune
// strutture dati che rappresentino il registro dei voti per una materia. Il
// programma deve poi calcolare la media dei voti per ogni singolo studente e
// aggiungerla alla struttura dati (che quindi conterrà anche una variabile
// media). Il programma deve mostrare tutti i dati raccolti e calcolati sullo
// schermo e salvarli in un secondo file di testo.

#include <stdio.h>

#define N 30
#define M 50

typedef struct {
    char cognome[M];
    float voti[N];
    int nvoti;
    float media;
} studente;

int main() {
    FILE *fp;
    studente registro[N];
    int nstudenti = 0, i;

    fp = fopen("5-11-voti.txt", "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    for (nstudenti = 0; nstudenti < N && !feof(fp); nstudenti++) {
        fscanf(fp, "%s %f %f %f", registro[nstudenti].cognome,
               &registro[nstudenti].voti[0], &registro[nstudenti].voti[1],
               &registro[nstudenti].voti[2]);
        registro[nstudenti].media = (registro[nstudenti].voti[0] + registro[nstudenti].voti[1] +
               registro[nstudenti].voti[2]) / 3.0;
        printf("%s: %.2f\n", registro[nstudenti].cognome, registro[nstudenti].media);
    }
    fclose(fp);

    fp = fopen("5-11-voti-finale.txt", "w");
    if (fp == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    for (i = 0; i < nstudenti; i++) {
        fprintf(fp, "%s: %.2f\n", registro[i].cognome, registro[i].media);
    }
    fclose(fp);
}