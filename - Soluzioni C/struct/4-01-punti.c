// 4.1	Scrivi un programma che definisca un punto e poi dati due punti scelti da te sia in grado,
// per mezzo di due apposite funzioni, di calcolare la distanza fra due punti e trovare il punto
// medio.

#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    float x;
    float y;
} punto;

float distanza(punto a, punto b)
{
    // float dist;

    // dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    // return dist;

    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

punto puntoMedio(punto a, punto b)
{
    punto m;
    m.x = (a.x + b.x) / 2.0;
    m.y = (a.y + b.y) / 2.0;
    return m;
}

int main()
{
    punto a, b, m;
    a.x = 3.4;
    a.y = 5.6;
    b.x = 6.7;
    b.y = 1.7;

    m = puntoMedio(a, b);

    printf("La distanza tra A(%.2f, %.2f) e B(%.2f, %.2f) e' %.2f\n\n", a.x, a.y, b.x, b.y,
        distanza(a, b));
    printf("Il punto medio tra tra A(%.2f, %.2f) e B(%.2f, %.2f) e' M(%.2f, %.2f)\n\n", a.x, a.y,
        b.x, b.y, m.x, m.y);
}