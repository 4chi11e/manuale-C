// 4.5	Scrivi e utilizza un insieme di funzioni da utilizzare per fare calcoli con le frazioni. In
// pratica devono essere definite le funzioni per fare almeno le 4 operazioni (magari anche altre
// operazioni). Deve anche essere fatta una funzione per effettuare la semplificazione delle
// frazioni (puoi decidere se creare e usare anche un'altra funzione mcd o utilizzare un altro
// metodo). Scrivi tutte queste funzioni in un file separato e poi utilizza queste funzioni per fare
// dei calcoli con le frazioni in un programma. In una prima versione del programma considera
// numeratore e denominatore come due variabili intere separate. In una seconda versione definisci
// invece una struct frazione che contiene numeratore e denominatore. Le funzioni dovranno essere
// modificate di conseguenza.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int num, den;
} frazione;

frazione semplificaSemplice(frazione f) {
    int i;
    frazione ris;
    for (i = 2;  i <= abs(f.num) && i <= abs(f.den); i++) {
        while (f.num % i == 0 && f.den % i == 0) {
            f.num /= i;
            f.den /= i;
        }
    }
    if (f.num == 0) {
        f.den = 1;
    }
    if (f.den < 0) {
        f.num *= -1;
        f.den *= -1;
    }
    return f;
}

void semplifica(frazione *f) {
    int i;
    for (i = 2;  i <= abs(f->num) && i <= abs(f->den); i++) {
        while (f->num % i == 0 && f->den % i == 0) {
            f->num /= i;
            f->den /= i;
        }
    }

    if (f->num == 0) {
        f->den = 1;
    }

    if (f->den < 0) {
        f->num *= -1;
        f->den *= -1;
    }
}

frazione somma(frazione f1, frazione f2) {
    frazione f3;
    f3.num = f1.num * f2.den + f2.num * f1.den;
    f3.den = f1.den * f2.den;
    semplifica(&f3);
    return f3;
}

void stampaFrazione(frazione f) {
    semplifica(&f);
    if (f.num == 0) {
        printf("%d", f.num);
    } else {
        printf("%d/%d", f.num, f.den);
    }
}

int main() {
    frazione f1, f2, f3;

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        f1.num = rand() % 21 - 10;
        do {
            f1.den = rand() % 121 - 60;
        } while (f1.den == 0);
        
        f2.num = rand() % 21 - 10;
        do {
            f2.den = rand() % 121 - 60;
        } while (f2.den == 0);

        f3 = somma(f1, f2);

        stampaFrazione(f1);
        printf(" + ");
        stampaFrazione(f2);
        printf(" = ");
        stampaFrazione(f3);
        printf("\n");
    }
}
