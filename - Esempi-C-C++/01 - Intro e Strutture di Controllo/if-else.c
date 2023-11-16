#include <stdio.h>

int main() {
    int num, den1, den2;

    num = 5;
    den1 = 2;
    den2 = 0;

    if (den1 != 0) {
        printf("%d / %d = %g \n", num, den1, (float)num/(float)den1);
    } else {
        printf("%d / %d = impossibile! \n", num, den1);
    }

    if (den2 != 0) {
        printf("%d / %d = %g \n", num, den2, (float)num/(float)den2);
    } else {
        printf("%d / %d = impossibile! \n", num, den2);
    }
}