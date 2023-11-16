#include <stdio.h>

int main() {

    // esempio per sscanf
    printf("Esempio d'uso di sscanf:\n");
    char frase[] = "Rudolph is 12 years old";
    char str[20];
    int i;
    sscanf(frase, "%s %*s %d", str, &i);        // %*s ci permette di leggere la parola "is" e scartarla
    printf("%s -> %d\n", str, i);

    // esempio per sprintf
    printf("\nEsempio d'uso di sprintf:\n");
    char risultato[50];
    int n, a = 5, b = 3;
    n = sprintf(risultato, "%d + %d = %d", a, b, a + b);
    printf("\"%s\" e' una stringa lunga %d caratteri\n\n", risultato, n);
}