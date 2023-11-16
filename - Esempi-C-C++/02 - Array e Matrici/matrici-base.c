#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define M 100

void riempiACaso(int matrice[N][M], int n, int m, int max){
    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            matrice[i][j] = rand() % (max+1);
        }
    }
}

void stampaMatrice(int matrice[N][M], int n, int m){
    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%2d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void stampaRiga(int matrice[N][M], int n, int m, int riga){
    int j;
    for(j = 0; j < m; j++){
        printf("%d ", matrice[riga][j]);
    }
}

void stampaColonna(int matrice[N][M], int n, int m, int colonna){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", matrice[i][colonna]);
    }
}

int main() {
    int n, m, max, i, j;
    int matrice[N][M];

    srand(time(NULL));

    // printf("Inserisci il numero di righe della tua matrice: ");
    // scanf("%d", &n);
    // while (n <= 0  || n > N){
    //     printf("Il numero deve essere maggiore di 0: ");
    //     scanf("%d", &n);
    // }
    // printf("Inserisci il numero di colonne della tua matrice: ");
    // scanf("%d", &m);
    // while (m <= 0 || m > M){
    //     printf("Il numero deve essere maggiore di 0 e minore di 100: ");
    //     scanf("%d", &m);
    // }

    // printf("Inserisci il valore massimo dei numeri da inserire nella matrice: ");
    // scanf("%d", &max);
    // while (max <= 0){
    //     printf("Il numero deve essere maggiore di 0: ");
    //     scanf("%d", &max);
    // }

    // adesso li metto a mano io
    n = 5;
    m = 6;
    max = 9;

    riempiACaso(matrice, n, m, max);
    stampaMatrice(matrice, n, m);

    stampaRiga(matrice, n, m, 2);
    printf("\n");
    stampaColonna(matrice, n, m, 2);
    printf("\n");
}