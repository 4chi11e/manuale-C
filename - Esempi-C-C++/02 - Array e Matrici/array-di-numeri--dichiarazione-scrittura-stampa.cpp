#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main() {
    int i;
    srand(time(NULL));

    // vari modi di dichiarare e inizializzare un array
    
    // 1
    int v1[N]; 
    for(i = 0; i < N; i++){
        v1[i] = i; // così metto i numeri da 0 a 9
        v1[i] = i+1; // così metto i numeri da 1 a 10
        v1[i] = rand() % 90 + 10; // così metto numeri a caso tra 10 e 99
    }

    // 2
    int v2[] = {1,7,4,6,3}; // crea un array di dimensione 5 già inizializzato coi numeri indicati
    
    // 3
    int v3[10] = {1,7,4,6,3}; // crea un array di dimensione 10 con i primi 5 numeri già inizializzati coi numeri indicati

    // modifica e stampa di un elemento
    v3[0] = 2;
    v3[3] = v3[1];
    printf("v3[0]: %d\n", v3[0]);
    printf("v3[3]: %d\n\n", v3[3]);


    // vari modi per stampare un array

    // stampa dall'inizio alla fine
    printf("Stampa in ordine dall'inizio alla fine:\n");
    for(i = 0; i < N; i++){         // la prima posizione è 0, l'ultima N-1
        printf("%d ", v1[i]);
    }
    printf("\n\n");

    // stampa al contrario cioè dalla fine all'inizio
    printf("Stampa in ordine dall'inizio alla fine (in due modi diversi):\n");
    for(i = N-1; i >= 0; i--){      // parte dall'ultima posizione che è N-1
        printf("%d ", v1[i]);
    }
    printf("\n");
    // metodo alternativo
    for(i = 0; i < N; i++){      
        printf("%d ", v1[N-1-i]); // parte dall'ultima posizione a destra che è N-1 e poi ogni volta si sposta più a sinistra
    }
    printf("\n\n");

    // stampa da una posizione a ad una posizione b >= a
    int a = 2, b = 5;
    printf("Stampa dalla posizione %d alla posizione %d:\n", a, b);
    for(i = a; i <= b; i++){
        printf("%d ", v1[i]);
    }
    printf("\n\n");

    // stampa (inversa) da una posizione b ad una posizione a <= b
    printf("Stampa dalla posizione %d alla posizione %d in due modi:\n", b, a);
    // primo metodo più semplice
    for(i = b; i >= a; i--){
        printf("%d ", v1[i]);
    }
    printf("\n");
    // metodo alternativo
    for(i = 0; i <= b-a; i++){
        printf("%d ", v1[b-i]);
    }
    printf("\n\n");
}