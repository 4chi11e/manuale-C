#include <stdio.h>

void bubblesort(int a[], int n) {
    int i, j, tmp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void stampaArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int numeri[] = {1,6,3,7,5,4,7};
    int n = sizeof(numeri)/sizeof(int);
    stampaArray(numeri, n);
    bubblesort(numeri, n);
    stampaArray(numeri, n);
}