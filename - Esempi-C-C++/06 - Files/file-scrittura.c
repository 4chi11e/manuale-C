#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int a = -5, b = 3;

    fp = fopen("file-output.txt", "w");
    if (fp == NULL) {
        printf(" Impossibile aprire il file ");
        return 1;
    }

    fprintf(fp, "Ciao");

    fclose(fp);

    // se lo riapro in scrittura sovrascrivo il file (cancello "Ciao")
    fp = fopen("file-output.txt", "w");
    if (fp == NULL) {
        printf(" Impossibile aprire il file ");
        system("pause");
        return 1;
    }

    fprintf(fp, "%d + %d = %d\n", a, b, a + b);
    fprintf(fp, "%d - %d = %d\n", a, b, a - b);

    fclose(fp);

    // lo riapro in append
    fp = fopen("file-output.txt", "a");
    if (fp == NULL) {
        printf(" Impossibile aprire il file ");
        return 1;
    }

    fprintf(fp, "%d * %d = %d\n", a, b, a * b);

    fclose(fp);
}