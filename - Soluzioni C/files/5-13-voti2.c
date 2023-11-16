// Scrivi un programma che legga i dati contenuti in un
// file di testo (testo riportato di seguito) e li inserisca in opportune
// strutture dati che rappresentino il registro dei voti per una materia. Il
// programma deve poi calcolare la media dei voti per ogni singolo studente e
// aggiungerla alla struttura dati (che quindi conterrà anche una variabile
// media). Il programma deve mostrare tutti i dati raccolti e calcolati sullo
// schermo e salvarli in un secondo file di testo. Questa versione del programma
// è più difficile della precedente perché si può notare che i cognomi possono
// essere formati da più parole e sono separati dai voti da un “:”, inoltre il
// numero di voti varia per ogni studente.

#include <stdio.h>
#include <string.h>

#define N 30
#define M 50
#define K 100

typedef struct {
    char cognome[M];
    float voti[N];
    int nvoti;
    float media;
} studente;

int main() {
    FILE* fp;
    studente registro[N];
    char riga[K], pezzo[K];
    int nstudenti = 0, i;
    float somma;

    fp = fopen("5-13-voti2.txt", "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    for (nstudenti = 0; nstudenti < N && !feof(fp); nstudenti++) {
        fgets(riga, K, fp);
        char *pezzo = strtok(riga, ":");  // char* strtok(char sorgente[], char separatori[]);
        strcpy(registro[nstudenti].cognome, pezzo);
        printf("%s: ", pezzo);
        registro[nstudenti].nvoti = 0;
        somma = 0;
        pezzo = strtok(NULL, " ");
        for (i = 0; i < N && pezzo != NULL; i++, pezzo = strtok(NULL, " ")) {
            sscanf(pezzo, "%f", &registro[nstudenti].voti[i]);
            printf("%.2f ", registro[nstudenti].voti[i]);
            registro[nstudenti].nvoti += 1;
            somma +=  registro[nstudenti].voti[i];
        }
        registro[nstudenti].media = somma /  registro[nstudenti].nvoti;
        printf("\n");
    }
    fclose(fp);

    fp = fopen("5-13-voti2-finale.txt", "w");
    if (fp == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    for (i = 0; i < nstudenti; i++) {
        fprintf(fp, "%s: %.2f\n", registro[i].cognome, registro[i].media);
    }
    fclose(fp);
}