// 5.16	Scrivi un programma in cui è definita una struttura studente. Dello studente ci interessano
// il nome, i vori presi e la media dei voti. Il programma deve instanziare uno o più studenti e
// aggiungere una serie di voti casuali (anche mezzi voti ma non tutti i decimali possibili). Voglio
// creare uno studente e poi usare delle funzioni per aggiungere voti e calcolare la media. Infine
// stampare lo studente con tutti i suoi dati con una funzione apposita.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 50

typedef struct {
    char nome[M];
    float voti[M];
    int nvoti;
    float media;
} studente;

void calcolaMedia(studente* s)
{
    int i;
    s->media = 0;
    for (i = 0; i < s->nvoti; i++) {
        s->media += s->voti[i];
    }
    s->media /= s->nvoti;
}

studente aggiungiVotoSemplice(studente s, float voto)
{
    if (s.nvoti < M) {
        s.voti[s.nvoti] = voto;
        s.nvoti++;
    }
    return s;
}

int aggiungiVotoComplicato(studente* s, float voto)
{
    if (s->nvoti < M) {
        s->voti[s->nvoti] = voto;
        s->nvoti++;
        calcolaMedia(s);
        return 1;
    } else {
        return 0;
    }
}

void stampaStudente(studente s)
{
    int i;
    printf("Nome: %s\n", s.nome);
    printf("Voti: ");
    for (i = 0; i < s.nvoti; i++) {
        printf("%.2f ", s.voti[i]);
    }
    printf("\nMedia: %.2f\n", s.media);
}

int main()
{
    studente s;
    float voto;

    srand(time(NULL));
    strcpy(s.nome, "Paolo");
    s.nvoti = 0;
    s.media = 0;

    for (int i = 0; i < 5; i++) {
        // voto = (float)rand() / ((float)RAND_MAX / 9) + 1;
        voto = (rand() % 19 + 2) / 2.0;
        // s = aggiungiVotoSemplice(s, voto);
        aggiungiVotoComplicato(&s, voto);
    }
    stampaStudente(s);
}