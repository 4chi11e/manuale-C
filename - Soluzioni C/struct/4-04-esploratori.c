// 4.4  
// Completa il seguente programma in cui è stato
// dichiarato un array di stringhe in cui sono scritti nomi, cognomi e date di
// nascita e morte di esploratori famosi. Devi definire le strutture dati adeguate
// a contenere queste informazioni: una struct esploratore e un array di
// esploratori. Usa la funzione sscanf per leggere i dati dalla stringa dati e
// riempi le strutture dati da te definite. scrivi poi una serie di funzioni che
// lavorino sulle tue strutture dati:
// a. una funzione che stampa l'array di esploratori.
// b. una funzione che ordina l'array in ordine
// alfabetico secondo il nome degli esploratori
// c. una funzione che ordina l'array in ordine
// crescente secondo le date di nascita degli esploratori


// Consigli e indicazioni extra:
// d. La funzione sscanf l'abbiamo usata pochissimo
// in passato ma trovate facilmente online indicazioni su come si usa.
// e. Alcuni potrebbero trovare comodo definire una
// struttura dati contenente l'array degli esploratori insieme al numero di
// esploratori contenuti nell'array.

#include <stdio.h>
#include <string.h>

#define N 100
#define M 50

typedef struct {
    char nome[M];
    char cognome[M];
    int anno_nascita;
    int anno_morte;
} esploratore;

void stampaEsploratori(esploratore lista[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%2d. %s %s %d %d\n", i+1, lista[i].nome, lista[i].cognome,
               lista[i].anno_nascita, lista[i].anno_morte);
    }
}

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

void ordinaEsploratoriPerAnnoNascita(esploratore lista[], int n) {
    int i, j;
    esploratore tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (lista[j].anno_nascita > lista[j + 1].anno_nascita ||
                (lista[j].anno_nascita == lista[j + 1].anno_nascita &&
                 strcmp(lista[j].nome, lista[j + 1].nome) > 0)) {
                tmp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = tmp;
            }
        }
    }
}

int main() {
    char dati[15][50] = {
        "Marco Polo 1254 1324",           "Cristoforo Colombo 1451 1506",
        "Amerigo Vespucci 1454 1512",     "Francisco Pizarro 1475 1541",
        "Ferdinando Magellano 1480 1521", "Hernan Cortez 1485 1547",
        "Walter Raleigh 1552 1618",       "Henry Hudson 1570 1611",
        "James Cook 1728 1779",           "Charles Darwin 1809 1882",
        "Kit Carson 1809 1866",           "David Livingstone 1813 1873",
        "Charles Foucauld 1858 1916",     "Ronald Amundsen 1872 1928",
        "Ernest Shakleton 1874 1922",
    };
    int nesploratori = 15, i;

    esploratore esploratori[N];

    for (i = 0; i < nesploratori; i++) {
        sscanf(dati[i], "%s %s %d %d", esploratori[i].nome,
               esploratori[i].cognome, &esploratori[i].anno_nascita,
               &esploratori[i].anno_morte);
        // printf("%s %s %d %d\n", esploratori[i].nome,
        //        esploratori[i].cognome, esploratori[i].anno_nascita,
        //        esploratori[i].anno_morte);
    }

    printf("Lista originale:\n");
    stampaEsploratori(esploratori, nesploratori);

    printf("\nLista ordinata per nome:\n");
    ordinaEsploratoriPerNome(esploratori, nesploratori);
    stampaEsploratori(esploratori, nesploratori);

    printf("\nLista ordinata per anno di nascita:\n");
    ordinaEsploratoriPerAnnoNascita(esploratori, nesploratori);
    stampaEsploratori(esploratori, nesploratori);
}