// 5.1	Scrivi un programma che scriva su un file un elenco di nomi, chiuda il file, lo riapra in
// lettura lo legga tutto e stampi ciò che ha letto.

#include <stdio.h>

#define N 50

int main() {
    FILE *fp;
    char parola[N];

    fp = fopen("5-01.txt", "w");
    if (fp == NULL) {
        printf("Il file non è stato aperto correttamente in scrittura\n");
        return 1;
    }

    fprintf(fp, "Francesco\n");
    fprintf(fp, "Paolo\n");
    fprintf(fp, "Emanuele\n");
    fprintf(fp, "Enrico\n");
    fprintf(fp, "Antonietta\n");
    fprintf(fp, "Arturo\n");
    fprintf(fp, "Carla\n");
    fprintf(fp, "Giorgio\n");
    fprintf(fp, "Eva");  // attento che se qui metti '\n' poi ti fa casino sull'ultima riga, o non lo metti o ne metti almeno 2

    fclose(fp);

    fp = fopen("5-01.txt", "r");
    if (fp == NULL) {
        printf("Il file non è stato aperto correttamente in lettura\n");
        return 1;
    }

    while (!feof(fp)) {
        
        // leggo una parola per volta
        // fscanf(fp, "%s", parola);
        // printf("%s ", parola);
        
        // leggo una riga per volta
        fgets(parola, N, fp);
        if (parola[0] != '\n') {
            printf("%s", parola); // notare che in parola compare anche '\n' come ultimo carattere, infatti va a capo

            // se vedi che stampa due volte l'ultimo nome vuol dire che hai aggiunto una riga vuota finale
        }
    }
    fclose(fp);

    return 0;
}