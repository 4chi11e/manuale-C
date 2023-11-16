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

registro reg;

void ordinaRegistro() {
    int i, j;
    studente tmp;
    for (i = 0; i < reg.nstudenti - 1; i++) {
        for (j = 0; j < reg.nstudenti - 1 - i; j++) {
            if (strcmp(reg.lista[j].cognome, reg.lista[j+1].cognome) > 0 
             || (strcmp(reg.lista[j].cognome, reg.lista[j+1].cognome) == 0  
                && strcmp(reg.lista[j].nome, reg.lista[j+1].nome) > 0)) {
                tmp = reg.lista[j];
                reg.lista[j] = reg.lista[j+1];
                reg.lista[j+1] = tmp;
            }
        }
    }
}

int aggiungiStudente(studente s){  // registro *r
    if (reg.nstudenti < N) {
        reg.lista[reg.nstudenti] = s;
        reg.nstudenti+=1; // alternativa scomoda con l'asterisco  (*r). equivale a reg.
        ordinaRegistro();
        printf("Studente aggiunto\n");
        return 1;
    } else {
        return 0;
    }
}

void stampaRegistro() {
    int i;
    printf("Inizio stampa\n");
    for (i = 0; i < reg.nstudenti; i++) {
        printf("%2d: %s %s - %.2f\n", i+1, reg.lista[i].cognome, reg.lista[i].nome, reg.lista[i].voto);
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
    reg.nstudenti = 0;
    studente s;

    strcpy(s.nome, "Luigi");
    strcpy(s.cognome, "Sambo");
    s.voto = 5.5;
    aggiungiStudente(s);

    strcpy(s.nome, "Riccardo");
    strcpy(s.cognome, "Germano");
    s.voto = 6;
    aggiungiStudente(s);

    stampaRegistro();
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