#include <stdio.h>
#include <string.h>

#define M 100

int main() {
    FILE* fp;
    int cont = 0;
    char riga[M];

    fp = fopen("testo.txt", "r");
    if (fp == NULL) {
        return 1;
    }

    while (!feof(fp)) {
        fgets(riga, M, fp);
        // if (strcmp(riga, " \n")) {
        if (riga[0] == '\n') {
            cont += 1;
        }
    }
    fclose(fp);

    printf("%d\n", cont);
}