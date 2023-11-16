// uso della funzione strtok per dividere automaticamente una stringa in
// sottostringhe sulla base di uno o più caratteri delimitatori

#include <stdio.h>
#include <string.h>

int main() {
    char originale[50] = "Ciao bellissimi, come state!";
    char separatori[] = ", !";  // gioca un po coi separatori
    // ci conviene farci una copia dell'originale
    char stringa[50];

    strcpy(stringa, originale);

    printf("Stringa all'inizio: %s\n\n", stringa);

    // Extract the first token
    char* pezzo = strtok(stringa, separatori);
    while (pezzo != NULL) {
        printf("%s\n", pezzo);  // printing each token
        pezzo = strtok(NULL, separatori);
        // si passa NULL perchè la funzione mantiene un puntatore al punto in
        // cui era arrivato prima e con NULL non lo spositiamo e continuiamo da
        // lì
    }

    printf("\nStringa alla fine: %s\n\n", stringa);

    return 0;
}