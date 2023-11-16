#include <stdio.h>
#include <string.h>
#include <ctype.h>  // tolower e toupper si trovano qui

int main() {
    char s1[] = "CiAo";
    int i;

    for (i = 0; i < strlen(s1); i++) {
        // s1[i] = tolower(s1[i]);
        printf("%c", tolower(s1[i]));
    }

    printf("\n");

    for (i = 0; i < strlen(s1); i++) {
        // s1[i] = toupper(s1[i]);
        printf("%c", toupper(s1[i]));
    }
}