#include <stdio.h>
#include <string.h>

// metodo C
typedef struct {
    float x;
    float y;
} punto;

int main() {
    punto a, b;
    a.x = 3.4;
    a.y = 5.6;
    b.x = 6.7;
    b.y = 1.7;
    printf("A(%.1f, %.1f), B(%.1f, %.1f)\n\n", a.x, a.y, b.x, b.y);

    // questa è la modalità C++ senza typedef (se lo metto qui è valido solo nel main)
    struct persona {
        char nome[30];
        char cognome[30];
        punto posizione;
    } p1, p2;
    
    strcpy(p1.nome, "Francesco");
    strcpy(p1.cognome, "Tormene");
    p1.posizione = a;

    strcpy(p2.nome, "Riccardo");
    strcpy(p2.cognome, "Corti");
    p2.posizione = b;

    printf("%s %s si trova nel punto (%.1f, %.1f)\n", p1.nome, p1.cognome,
           p1.posizione.x, p1.posizione.y);
    printf("%s %s si trova nel punto (%.1f, %.1f)\n\n", p2.nome, p2.cognome,
           p2.posizione.x, p2.posizione.y);



    persona p3;
    strcpy(p3.nome, "Emanuele");
    strcpy(p3.cognome, "Tormene");
    p3.posizione = a;
    printf("%s %s si trova nel punto (%.1f, %.1f)\n\n", p3.nome, p3.cognome,
           p3.posizione.x, p3.posizione.y);
}