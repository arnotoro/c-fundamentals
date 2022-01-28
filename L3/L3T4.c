#include <stdio.h>
#define MAX 30

int merkkijonoPituus(char *merkkiJono);
char *kopioMerkkijono(char *uusi, char *vanha);

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

char *kopioMerkkijono(char *uusi, char *vanha) {
    char *uusiPtr;
    int i = 0;

    while(vanha[i] != '\0') {
        uusi[i] = vanha[i];
        i++;
    }
    uusi[i] = '\0';
    uusiPtr = uusi;
    return uusiPtr;
}



int main(void) {
    char merkkijono1[MAX];
    char merkkijono2[MAX];
    int pituus1;
    int pituus2;
    int pituus3;
    char *merkkijono2_ptr;

    printf("Anna kopioitava merkkijono: ");
    fgets(merkkijono1, 28, stdin);

    pituus1 = merkkijonoPituus(merkkijono1);
    merkkijono1[pituus1 - 1] = '\0'; //otetaan huomioon rivinvaihto
    merkkijono2_ptr = kopioMerkkijono(merkkijono2, merkkijono1);
    pituus2 = merkkijonoPituus(merkkijono2_ptr);

    printf("Merkkijono 1 on '%s'.\n", merkkijono1);
    printf("Merkkijono 2 on '%s'.\n", merkkijono2_ptr);

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}