#include <stdio.h>
#include <string.h>

#define N 100
#define M 100

int main() {
    char parole[N][M];
    int n, i;

    printf("Quante frasi vuoi inserire? ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf(" %99[^\n]", parole[i]);
    }

    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", parole[i]);
    }
}