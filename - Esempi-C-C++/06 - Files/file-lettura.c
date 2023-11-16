#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char parola[30];
    char riga[100];
    int dimriga = 100;

    fp = fopen("file-input.txt", "r");
    if (fp == NULL) {
        printf(" Impossibile aprire il file ");
        system("pause");
        return 1;
    }

    // leggo tutto il file parola per parola (perdo gli a capo)
    printf("Lettura del file parola per parola:\n");
    printf("-----------------------------------------------------------------\n");
    while(!feof(fp)){
        fscanf ( fp ,"%s", parola);
        printf("%s ", parola);
    }
    printf("\n-----------------------------------------------------------------\n\n");

    // riporto il puntatore del file all'inizio del file
    rewind(fp);
    // fseek(fp, 0, SEEK_SET); // alternativa che permette più possibilità ma più complesso

    // leggo tutto il file riga per riga
    printf("Lettura del file riga per riga:\n");
    printf("-----------------------------------------------------------------\n");
    while(!feof(fp)){
        fgets(riga, dimriga, fp);
        printf("%s", riga);
    }
    printf("\n-----------------------------------------------------------------\n\n");



    fclose(fp);
}