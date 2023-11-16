#include <stdio.h>
#include <string.h>

#define N 30

int main() {
    int i;

    // vari modi di dichiarare, inizializzare e stampare una stringa
    
    // 1
    char s1[N]; 
    printf("Scrivi una parola (prova a vedere che cosa succede se ne metti piu di una): ");
    scanf("%29s", s1);
    printf("s1: %s\n",s1);

    printf("Scrivi una frase: ");
    // gets(s1);                    // dicono di non usarlo mai, è obsoleto e ha problemi
    // scanf(" %29[^\n]", s1);      // metodo interessante
    // fgets(s1, N, stdin);
    fgets(s1, N, stdin);            // al posto di scrivere N ha senso scrivere sizeof(s1)
    printf("\ns1: %s\n\n",s1);

    // 2
    char s2[] = "Ciao";      // crea un array di char di dimensione 5 che contiene {'C', 'i', 'a', 'o', '\0'}
    // equivale a
    char s3[] = {'C', 'i', 'a', 'o', '\0'};

    printf("s2: %s\n",s2);
    printf("s3: %s\n\n",s3);
    
    // 3
    char s4[20] = "Ciao belli"; // crea una stringa di 20 caratteri con i primi 10 char "ciao belli", compreso lo spazio, poi inserisce tutti '\0'
    printf("s4: %s\n\n",s4);


    // modi per stampare una stringa

    // modo semplice come visto sopra
    printf("Stampa dell'intera stringa:\n");
    printf("s4: %s\n",s4);
    printf("\n\n");

    // lettera per lettera con strlen
    printf("Stampa della stringa lettera per lettera con strlen:\n");
    for(i=0; i < strlen(s4); i++){      // strlen contenuta nella libreria string.h restituisce la lunghezza reale della stringa passata come parametro, si ferma prima di '\0'
        printf("%c", s4[i]);
    }
    printf("\n\n");

    // lettera per lettera alternativa
    printf("Stampa della stringa lettera per lettera alternativa:\n");
    for(i=0; s4[i] != '\0'; i++){      // controllo di non essere arrivato a '\0' se si mi fermo
        printf("%c", s4[i]);
    }
    printf("\n\n");



    // assegnamenti

    char s5[30] = "mi chiamo Francesco";
    char s6[30] = "io invece Paolo";

    // queste due operazioni non sono lecite, s5 e s6 sono array cioè indirizzi di memoria del primo char di un array. Puoi provare a decommentare e vedere che dà errore
    // s5 = "ciao";
    // s5 = s6;

    // per copiare una stringa si usa la funzione strcpy (string copy)
    strcpy(s5, "Ciao");     // s5 = "ciao"
    printf("s5: %s\n", s5);
    strcpy(s5, s6);         // s5 = s6
    printf("s5: %s\n\n", s5);


    // per confrontare due stringhe si usa la funzione strcmp che può restituire tre valori -1, 0, 1 che indicano se 
    // la prima delle due stringhe viene prima, è uguale o viene dopo la seconda in ordine alfabetico (utile per ordinare alfabeticamente)
    char s7[30] = "Milano";
    char s8[30] = "Roma";
    printf("Confronto \"Milano\" con \"Roma\": %d\n", strcmp(s7, s8));  // s7 < s8 -> strcmp(s7,s8) < 0
    printf("Confronto \"Roma\" con \"Milano\": %d\n", strcmp(s8, s7));  // s8 > s7 -> strcmp(s7,s8) > 0
    printf("Confronto \"Milano\" con \"Milano\": %d\n\n", strcmp("Milano", "Milano"));

    // concatenare due stringhe

    char s9[30] = "Ciao";
    char s10[30] = "belli!";
    printf("Concateno \"%s\" con \"%s\": ", s9, s10);
    strcat(s9, " ");
    printf("%s\n\n", strcat(s9, s10));


    // La libreria string.h contiene molte altre funzioni, puoi consultarle qui https://it.wikipedia.org/wiki/String.h
}