// Scrivi un programma per gestire un corso. Al corso sono
// iscritte delle persone, massimo 30. Per ogni persona dovete sapere nome e
// cognome e ad ognuno alla fine del corso viene assegnato un voto da 1 a 10. Alla
// fine stampa tutti i dati di ogni studente, compresi i voti.

#include <stdio.h>
#include <string.h>

#define N 30
#define M 50

typedef struct {
    char nome[M];
    char cognome[M];
    float voto;
} studente;

typedef struct {
    studente lista[N];
    int nstudenti;
} registro;



void ordinaRegistro(registro* r) {
    int i, j;
    studente tmp;
    for (i = 0; i < r->nstudenti - 1; i++) {
        for (j = 0; j < r->nstudenti - 1 - i; j++) {
            if (strcmp(r->lista[j].cognome, r->lista[j+1].cognome) > 0 
             || (strcmp(r->lista[j].cognome, r->lista[j+1].cognome) == 0  
                && strcmp(r->lista[j].nome, r->lista[j+1].nome) > 0)) {
                tmp = r->lista[j];
                r->lista[j] = r->lista[j+1];
                r->lista[j+1] = tmp;
            }
        }
    }
}

int aggiungiStudente(registro* r, studente s){  // registro *r
    if (r->nstudenti < N) {
        r->lista[r->nstudenti] = s;
        (*r).nstudenti+=1; // alternativa scomoda con l'asterisco  (*r). equivale a r->
        ordinaRegistro(r);
        printf("Studente aggiunto\n");
        return 1;
    } else {
        return 0;
    }
}

void stampaRegistro(registro r) {
    int i;
    printf("Inizio stampa\n");
    for (i = 0; i < r.nstudenti; i++) {
        printf("%2d: %s %s - %.2f\n", i+1, r.lista[i].cognome, r.lista[i].nome, r.lista[i].voto);
    }
}

void raddoppia(int* x) {
    *x = *x * 2;
}

void invertiValore(int a, int b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void invertiIndirizzo(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    registro reg;
    reg.nstudenti = 0;
    studente s;

    strcpy(s.nome, "Luigi");
    strcpy(s.cognome, "Sambo");
    s.voto = 5.5;
    aggiungiStudente(&reg, s);

    strcpy(s.nome, "Riccardo");
    strcpy(s.cognome, "Germano");
    s.voto = 6;
    aggiungiStudente(&reg, s);

    stampaRegistro(reg);
    printf("%d\n", reg.nstudenti);


    int x = 2;
    raddoppia(&x);
    printf("%d\n\n", x);

    int a = 5, b = 7;
    printf("a: %d, b: %d\n", a, b);
    invertiValore(a, b);
    printf("a: %d, b: %d\n", a, b);
    invertiIndirizzo(&a, &b);
    printf("a: %d, b: %d\n", a, b);
}