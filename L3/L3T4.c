#include <stdio.h>
#include <stdlib.h>
#define MAX 60

int merkkijonoPituus(char *merkkiJono);
char *kopioMerkkijono(char *merkkiJono1, char *merkkiJono2);

int main(void) {
    char merkkiJono1[MAX], merkkiJono2[MAX];
    char *ptr;

    printf("Anna ensimmäinen merkkijono (max 30 merkkiä): ");
    fgets(merkkiJono1, MAX, stdin);
    printf("Anna toinen merkkijono (max 30 merkkiä): ");
    fgets(merkkiJono2, MAX, stdin);

    merkkiJono1[merkkijonoPituus(merkkiJono1)-1] = '\0';
    merkkiJono2[merkkijonoPituus(merkkiJono2)-1] = '\0';

    ptr = kopioMerkkijono(merkkiJono1, merkkiJono2);

    if (ptr != 0) {
        printf("Yhdistetty merkkijono on:\n'%s'\n", ptr);
    }

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

int merkkijonoPituus(char *merkkiJono) {
    int pituus = 0;
    char *ptr;

    ptr = merkkiJono;

    while(*ptr != '\0') {
        pituus++;
        ptr++;
    }

    return pituus;
}

char *kopioMerkkijono(char *merkkiJono1, char *merkkiJono2) {
    int i = 0;
    int pituus1 = merkkijonoPituus(merkkiJono1);
    int pituus2 = merkkijonoPituus(merkkiJono2);

    if ((pituus1+pituus2) > MAX) {
        printf("Merkkijonojen yhteenlaskettu pituus on liian pitkä ohjelman muistialueelle.\n");
        return 0;
    }
    
    while(merkkiJono2[i] != '\0') {
        merkkiJono1[pituus1 + i] = merkkiJono2[i];
        i++;
    }

    merkkiJono1[pituus1 + i] = '\0';

    return merkkiJono1;
}
