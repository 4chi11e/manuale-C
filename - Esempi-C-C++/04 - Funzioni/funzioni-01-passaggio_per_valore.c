#include <stdio.h>

// funzione somma che riceve due interi a, b e restituisce un intero. questi
// interi a, b non sono gli stessi del main, la funzione ha uno spazio di
// memoria separato.
int somma(int a, int b) {  //
    int risultato = a + b;
    a = 6;  // nota che questa modifica non modifica la a del main perchè sono
            // due variabili diverse
    return risultato;
    // il comando return interrompe l'esecuzione della funzione e restituisce al
    // massimo un valore. Per restituire più di un valore è necessario ricorrere
    // a metodi più complessi
}

int main() {
    int a = 5, y = 6;
    printf("%d + %d = %d\n\n", a, y, somma(a, y));
    printf("%d\n", a); // stampa 5 perchè solo la a di somma è stata modificata
}