#include <stdio.h>

int raddoppiaNumero(int a) { return a * 2; }

// int raddoppiaDueNumeri(int a, int b) {
//     return a*2;
//     return b*2;
// }
// questa funzione non ha senso perchè non si possono mai restituire due valori
// (al massimo restituire una struttura dati ma lo vedremo più avanti)
// devo quindi ricorrere ad un trucco

// questa funzione non restituisce due numeri ma riesce a modificare
// direttamente i due numeri originali che si trovano nel main, per farlo usa
// due puntatori a quelle variabili
void raddoppiaDueNumeri(int *a, int *b) {
    // se in una dichiarazione metto un asterisco prima della variabile (o dopo
    // int) allora sto dichiarando un puntatore, in questo caso dei puntatori a
    // variabili intere

    // quando invece uso i puntatori se scrivessi solo a intenderei il putatore
    // a che in questo caso è la posizione in memoria della a passata dal main;
    // se invece scrivo *a intendo il valore contenuto nella posizione di
    // memoria a
    *a *= 2;
    *b *= 2;
}

int main() {
    int a = 2, b = 3;

    printf("%d\n", a);
    a = raddoppiaNumero(a);
    printf("%d\n", a);

    printf("---------\n");

    printf("%d - %d\n", a, b);
    raddoppiaDueNumeri(&a, &b);
    // la & prima di a e b mi serve per indicare che alla funzione non passo le
    // copie di a e b, ma passo i loro indirizzi in memoria, che finiranno nei
    // puntatori dichiarati come parametri della funzione.
    // è la stessa cosa che faccio quando uso la funzione scanf la quale ha
    // bisogno di modificare la variabile in modo che contenga quello che scrivo
    // con la tastiera
    printf("%d - %d\n", a, b);
}