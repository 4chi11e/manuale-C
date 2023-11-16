// 1.
// Definisci una struct punto. Scrivi ed utilizza poi le
// funzioni:
// · Funzione per stampare una rappresentazione del punto (es. A(1,2))
// · Funzione per calcolare il punto medio
// · Funzione per calcolare la retta passante tra due
// punti. Dovrai anche definire la struct retta che contiene le informazioni
// necessarie ad identificare una retta e definire una funzione per stamparla in
// modo standard (y=mx+q)
// ·  Funzione che verifica se tre punti sono allineati.

#include <math.h>
#include <stdio.h>
#include <string.h>

#define M 50

typedef struct {
    float x;
    float y;
} punto;

typedef struct {
    float m;
    float q;
} retta;

float distanza(punto a, punto b) {
    // float dist;

    // dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    // return dist;

    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

punto puntoMedio(punto a, punto b) {
    punto m;
    m.x = (a.x + b.x) / 2.0;
    m.y = (a.y + b.y) / 2.0;
    return m;
}

void stampaPunto(punto p, char nome[]) {
    // char s[20] = "";
    // sprintf(s, "%s(%.2f, %.2f)", nome, p.x, p.y);
    // printf("%s", s);

    printf("%s(%.2f, %.2f)", nome, p.x, p.y);
}

void puntoToString(punto p, char nome[], char s[]) {
    sprintf(s, "%s(%.2f, %.2f)", nome, p.x, p.y);
}

retta rettaPerDuePunti(punto a, punto b) {
    retta r;
    r.m = (b.y - a.y) / (b.x - a.x);
    r.q = b.y - a.y - (r.m * (b.x - a.x));
    return r;

    // in realtà con le rette verticali non dovrebbe funzionare ma
    // semplifichiamo
}

void rettaToString(retta r, char s[]) {
    sprintf(s, "y = %.2f x + %.2f)", r.m, r.q);
}

int allineati(punto a, punto b, punto c) {
    retta r1 = rettaPerDuePunti(a, b);
    retta r2 = rettaPerDuePunti(b, c);
    if (r1.m == r2.m &&
        r1.q == r2.q) {  // in realtà c'è rischio di approssimazioni con i float
                         // quindi andrebbe fatto con un margine di errore e non
                         // con le uguaglianze semplici.
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char sa[M], sb[M], sc[M], sm[M], sr[M];
    punto a, b, c, m;
    retta r;
    a.x = 1;
    a.y = 1;
    b.x = 2;
    b.y = 2;
    // a.x = 2.25;
    // a.y = 3.5;
    // b.x = 1.1;
    // b.y = 2.7;
    c.x = 3.8;
    c.y = 5;

    m = puntoMedio(a, b);
    puntoToString(m, "M", sm);

    puntoToString(a, "A", sa);
    puntoToString(b, "B", sb);
    puntoToString(c, "C", sc);
    printf("%s, %s, %s\n", sa, sb, sc);

    printf("La distanza tra A(%.2f, %.2f) e B(%.2f, %.2f) e' %.2f\n\n", a.x,
           a.y, b.x, b.y, distanza(a, b));
    printf(
        "Il punto medio tra tra A(%.2f, %.2f) e B(%.2f, %.2f) e' M(%.2f, "
        "%.2f)\n\n",
        a.x, a.y, b.x, b.y, m.x, m.y);

    r = rettaPerDuePunti(a, b);
    rettaToString(r, sr);
    // printf("La retta passante per %s e %s e' %s\n", sa, sb, sr);
    printf("La retta passante per %s e %s e' %s\n", sa, sb, sr);

    if (allineati(a, b, c)) {
        printf("I punti %s, %s e %s sono allineati\n", sa, sb, sc);
    } else {
        printf("I punti %s, %s e %s non sono allineati\n", sa, sb, sc);
    }

    if (allineati(a, b, m)) {
        printf("I punti %s, %s e %s sono allineati\n", sa, sb, sm);
    } else {
        printf("I punti %s, %s e %s non sono allineati\n", sa, sb, sm);
    }
}