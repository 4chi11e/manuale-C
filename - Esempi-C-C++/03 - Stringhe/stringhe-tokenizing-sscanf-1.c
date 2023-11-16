// in questo primo esempio faccio vedere il caso in cui so esattamente almento
// quante stringhe ci sono prima dei : ma non so quanti numeri ci sono alla fine

#include <stdio.h>

int main() {
    char frase[] = "Frase di prova: con dei separatori: 1 2 3 4";
    char parti[100][100];
    int numeri[100];
    int quanti, i;

    // metto un numero di %d che mi copre il caso con più numeri. In quanti
    // verrà messo quanti token/parti riesce effettivamente a leggere
    quanti = sscanf(frase, "%[^:]: %[^:]: %d %d %d %d %d", parti[0], parti[1],
                    &numeri[0], &numeri[1], &numeri[2], &numeri[3], &numeri[4]);
    printf("%s: %s:", parti[0], parti[1]);

    // quanti - 2 perchè ci sono due stringhe
    for (i = 0; i < quanti - 2; i++) {
        printf(" %d", numeri[i]);
    }
    printf("\n", quanti);
}