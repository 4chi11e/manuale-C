#include <stdio.h>

void stampaArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return; // in una funzione void non è obbligatorio ma può essere usato per
            // terminare immediatamente l'esecuzione della funzione
    printf("Non verrò mai stampato\n");
}


void bubbleSort(int v[], int N) {
    // per motivi spiegati di seguito potrei scrivere: void bubbleSort(int *v, int N)
    // puoi provare

    int i, j, scambiato, tmp;

    scambiato = 1;
    for (i = 0; i < N - 1 && scambiato; i++) {
        scambiato = 0;
        for (j = 0; j < N - 1 - i; j++) {
            if (v[j] > v[j + 1]) { // così ordina in ordine crescente, se si
                                   // cambia > con < si ottiene decrescente
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                scambiato = 1;
            }
        }
    }
}

int main() {
    int n = 5, v[] = {5, 1, 3, 2, 4};

    stampaArray(v, n);
    printf("\n");
    bubbleSort(v, n);
    // gli array non sono variabili normali, in realtà sono puntatori al primo
    // elemento dell'array quindi la funzione bubbleSort è in grado di
    // modificare i valori contenuti in v
    // in pratica dichiarare int v[] è come dichiarare int *v (circa)
    // e quando passo v non devo scrivere &v perchè v è già un puntatore
    stampaArray(v, n);
    printf("\n\n");

    // per chi volesse degli esempi più approfonditi di come funziona la cosa:
    printf("%d equivale a %d\n", v[0], *v);
    printf("%d equivale a %d\n", v[1], *(v + 1));
    printf("%d equivale a %d\n", v[2], *(v + 2));
    // ....
    // questo esempio fa anche capire perchè il C abbia bisogno di sapere il
    // tipo del puntatore, in questo caso int, perchè quando faccio v+1 o v[1],
    // il C deve essere in grado di spostarsi in avanti nella memoria di un
    // numero di byte equivalente alla dimensione di un int, infatti:
    printf("\n");
    printf("indirizzo di v[0] o v+0: %d\n", v);
    printf("indirizzo di v[1] o v+1: %d\n", v + 1);
    printf("indirizzo di v[2] o v+2: %d\n", v + 2);
    // i numeri curiosamente diminuiscono invece che aumentare perchè, per
    // motivi tecnici oscuri che ci risparmiamo, la memoria dello stack, il posto
    // in cui vengono allocate le variabili in memoria, viene usato al contrario.
}