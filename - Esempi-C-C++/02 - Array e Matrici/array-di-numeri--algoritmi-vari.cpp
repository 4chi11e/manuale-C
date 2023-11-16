#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

#define N 10

// metto qui una funzione per stampare l'array per non dover sempre scrivere il codice negli esempi
void stampaArray(int v[], int n){
    printf("{");
    for(int i = 0; i < n - 1; i++){
        printf("%d, ", v[i]);
    }
    printf("%d}", v[n-1]);
}

// funzione per riempire un array di numeri casuali
void riempiCasualmente(int v[], int n, int min, int max){
    for(int i = 0; i < n - 1; i++){
        v[i] = rand() % (max-min+1) + min;
    }
}


int main() {
    int i, j, v[N];
    srand(time(NULL));

    riempiCasualmente(v, N, 0, 9);

    printf("Stampa in ordine dall'inizio alla fine:\n");
    stampaArray(v, N);
    printf("\n\n");


    // ---------------------------------------------------------------------------------------------------------------------------
    // Copiare un array

    int vCopia[N];

    // non posso assegnare direttamente un valore
    // vCopia = v;          // se decommenti dà errore

    // o copio gli elementi ad uno ad uno
    for(i = 0; i < N; i++){
        vCopia[i] = v[i];
    }
    printf("Copia dell'array copiando uno ad uno gli elementi:\n");
    stampaArray(vCopia, N);
    printf("\n\n");
    
    // oppure uso le funzioni della libreria
    
    // funzione C, se proprio bisogna rimanere sul C ok se no consiglio la versione C++, ci possono essere problemi col terzo parametro che indica il numeri di byte da copiare
    int vCopia2[N];
    memcpy(vCopia2, v, sizeof(v));      // la funzione fa parte della libreria string.h
    printf("Copia dell'array usando la funzione C memcpy:\n");        
    stampaArray(vCopia2, N);
    printf("\n\n");

    // funzione C++, la consiglio
    int vCopia3[N];
    std::copy(v, v+N, vCopia3);         // la funzione fa parte della libreria algorithm
    printf("Copia dell'array usando la funzione C++ copy:\n");       
    stampaArray(vCopia3, N);
    printf("\n\n");


    // ---------------------------------------------------------------------------------------------------------------------------
    // Cerco se un numero è presente nell'array

    printf("Cerco un numero: 5 e dico se e' presente:\n");
    int daCercare = 5;
    int trovato = 0;
    for(i = 0; i < N && !trovato; i++){    
        if(v[i] == daCercare){
            trovato = 1;
        }
    }
    if(trovato) {
        printf("%d e' contenuto nell'array", daCercare);
    } else {
        printf("%d non e' contenuto nell'array", daCercare);
    }
    printf("\n\n");


    // ---------------------------------------------------------------------------------------------------------------------------
    // dico la prima posizione di un numero nell'array

    printf("Cerco un numero: 5 e dico se e' presente e dove si trova per la prima volta:\n");
    daCercare = 5;
    int pos = -1;
    for(i = 0; i < N && pos < 0; i++){   // se non metto "&& pos" mi stampa l'ultima posizione di 5 nell'array 
        if(v[i] == daCercare){
            pos = i;
        }
    }
    if(pos >= 0) {
        printf("%d e' contenuto nell'array in posizione %d", daCercare, pos);
    } else {
        printf("%d non e' contenuto nell'array", daCercare);
    }
    printf("\n\n");


    // ---------------------------------------------------------------------------------------------------------------------------
    // conto quante volte è presente un numero nell'array

    printf("Cerco un numero: 5, e dico se e' presente. Se e' presente dico anche quante volte e' contenuto:\n");
    daCercare = 5;
    int occorrenze = 0;
    for(i = 0; i < N; i++){   // se non metto "&& pos" mi stampa l'ultima posizione di 5 nell'array 
        if(v[i] == daCercare){
            occorrenze += 1;
        }
    }
    if(occorrenze) {
        printf("%d e' contenuto nell'array %d volte", daCercare, occorrenze);
    } else {
        printf("%d non e' contenuto nell'array", daCercare);
    }
    
    printf("\n\n");


    // ---------------------------------------------------------------------------------------------------------------------------
    // cercare i valori massimi e minimi di un array
    printf("Ricerco il massimo e il minimo:\n");
    int min = v[0];
    int max = v[0];
    for (i = 1; i < N; i++){
        if(v[i] > max){
            max = v[i];
        }
        else if (v[i] < min){
            min = v[i];
        }
    }
    printf("min: %d\nmax: %d\n\n", min, max);
    
    
    // ---------------------------------------------------------------------------------------------------------------------------
    // calcolare la media
    float media = 0;
    for (i = 1; i < N; i++){
        media += v[i];
    }
    media /= N;
    printf("La media vale: %.2f\n\n", media);
    
    
    // ---------------------------------------------------------------------------------------------------------------------------
    // calcolo la mediana
    // per farlo prima devo ordinare l'array, ma siccome non voglio perdere l'originale uso una delle copie che mi sono fatto
    // per ordinare o uso un mio algoritmo o uso quello della libreria algorithm
    std::sort(vCopia, vCopia+N);
    printf("Stampo l'array ordinato:\n");
    stampaArray(vCopia, N);

    float mediana;
    if(N % 2 == 1){
        mediana = vCopia[N/2];
    }
    else{
        mediana = (vCopia[N/2 - 1] + vCopia[N/2]) / 2.0;    // ricordarsi di dividere per 2.0 e non 2 se no ho una divisione tra interi che viene troncata (3/2 diventa 1, 3/2.0 diventa 1.5)
    }

    printf("\nLa mediana vale: %.2f\n\n", mediana);


    // ---------------------------------------------------------------------------------------------------------------------------
    // moda di un array
    // in realtà se ci fossero più valori che compaiono con la massima frequenza si dovrebbe dire che la moda non esiste
    // per semplicità nel seguente esempio considereremo moda il numero più piccolo che compare con la massima frequenza
    // anche qui mi serve avere l'array ordinato, uso quello di prima. 
    // dò per scontato che N > 0
    int cont, maxCont = 0, moda;
    for(i = 0; i < N; i++){
        cont = 1;
        while(v[i] == v[i+1]){
            cont++;
            i++;
        }
        if(cont > maxCont){
            maxCont = cont;
            moda = v[i];
        }
    }
    printf("La moda vale: %d\n\n", moda);


    // ---------------------------------------------------------------------------------------------------------------------------
    // cerco la posizione (la prima, vedi commenti sotto) di una sequenza di numeri vx in un array più grande vy
    int dimvy = 30;
    int vy[dimvy];
    riempiCasualmente(vy, dimvy, 0, 4);

    int dimvx = 2;
    int vx[] = {1,2};

    printf("Array in cui cercare: ");
    stampaArray(vy, dimvy);
    printf("\nArray da cercare: ");
    stampaArray(vx, dimvx);
    printf("\n");
    
    int posvx = -1;
    for(i = 0; i < dimvy; i++){
        for(j = 0; j < dimvx && vx[j] == vy[i+j]; j++){
            // niente
        }
        if(j == dimvx){
            posvx = i;
            break;          // posso in alternativa mettere come condizione del ciclo sulle i: i < dimvy && posvx != -1
                            // oppure se non metto niente mi trova l'ultima posizione di vx in vy
        }
    }

    if(posvx == -1){
        printf("L'array da cercare non e' contenuto nell'array in cui cercare\n\n");
    }else{
        printf("L'array da cercare e' stato trovato nella posizione %d\n\n", posvx);
    }
    

}