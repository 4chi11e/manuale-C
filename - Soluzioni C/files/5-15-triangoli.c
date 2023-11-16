// 5.17	Scrivi un programma che sia in grado di leggere da file i dati riportati di seguito e
// salvarli in opportune strutture dati (punto e triangolo). Il programma deve poi stampare sia su
// schermo che in un altro file i dati riguardanti ogni triangolo e se esso è scaleno, isoscele o
// equilatero. Per decidere il tipo di triangolo devono essere usate tre diverse funzioni che
// controllano ognuna se il triangolo passato come parametro è di uno dei tre tipi richiesti.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float soglia = 0.01;

typedef struct {
    float x, y;
} punto;

typedef struct {
    punto a, b, c;
} triangolo;

float distanza(punto a, punto b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int equilatero(triangolo t)
{
    float a = distanza(t.a, t.b);
    float b = distanza(t.b, t.c);
    float c = distanza(t.c, t.a);

    // return a == b && b == c;

    printf("\na: %f b: %f c: %f \na-b: %f b-c: %f \n", a, b, c, fabs(a - b), fabs(b - c));
    return (fabs(a - b) < soglia && fabs(b - c) < soglia);
}

int isoscele(triangolo t)
{
    float a = distanza(t.a, t.b);
    float b = distanza(t.b, t.c);
    float c = distanza(t.c, t.a);

    // return (a == b && b != c) || (a == c && c != b) || (b == c && c != a);
    printf("\na: %f b: %f c: %f \na-b: %f b-c: %f \n", a, b, c, fabs(a - b), fabs(b - c));
    return (fabs(a - b) < soglia && fabs(b - c) > soglia)
        || (fabs(a - c) < soglia && fabs(c - b) > soglia)
        || (fabs(b - c) < soglia && fabs(c - a) > soglia);
}

int scaleno(triangolo t)
{
    float a = distanza(t.a, t.b);
    float b = distanza(t.b, t.c);
    float c = distanza(t.c, t.a);

    // return a != b && a != c && b != c;
    return fabs(a-b) > soglia && fabs(a-c) > soglia && fabs(b-c) > soglia;
}

int main()
{
    FILE *fpr, *fpw;
    triangolo t;
    punto p;

    fpr = fopen("5-15-triangoli-in.txt", "r");
    if (fpr == NULL) {
        printf("File %s non trovato\n", "164-triangoli-in.txt");
        return 1;
    }
    fpw = fopen("5-15-triangoli-out.txt", "w");
    if (fpr == NULL) {
        printf("Errore nell'apertura del file in scrittura\n");
        return 1;
    }

    while (!feof(fpr)) {
        fscanf(fpr, "(%f, %f) (%f, %f) (%f, %f)\n", &t.a.x, &t.a.y, &t.b.x, &t.b.y, &t.c.x, &t.c.y);
        fprintf(fpw, "(%.2f, %.2f) (%.2f, %.2f) (%.2f, %.2f) - ", t.a.x, t.a.y, t.b.x, t.b.y, t.c.x, t.c.y);
        printf("(%.2f, %.2f) (%.2f, %.2f) (%.2f, %.2f) - ", t.a.x, t.a.y, t.b.x, t.b.y, t.c.x, t.c.y);
        if (equilatero(t)) {
            fprintf(fpw, "equilatero");
            printf("equilatero");
        } else if (isoscele(t)) {
            fprintf(fpw, "isoscele");
            printf("isoscele");
        } else if (scaleno(t)) {
            fprintf(fpw, "scaleno");
            printf("scaleno");
        }
        fprintf(fpw, "\n");
        printf("\n\n");
    }

    fclose(fpr);
    fclose(fpw);
}