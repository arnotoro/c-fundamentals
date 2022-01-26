#include <stdio.h>
#include <string.h>

void vertailu_int(int luku1, int luku2);
void vertailu_float(float luku1, float luku2);

void vertailu_int(int luku1, int luku2) {
    int iSuurempi;
    int iPienempi;

    if (luku1 > luku2) {
        iSuurempi = luku1;
        iPienempi = luku2;
        printf("Luku %d on suurempi ja %d pienempi.\n", iSuurempi, iPienempi);

    } else if (luku2 > luku1) {
        iSuurempi = luku2;
        iPienempi = luku1;
        printf("Luku %d on suurempi ja %d pienempi.\n", iSuurempi, iPienempi);
    } else {
        printf("Luvut %d ja %d ovat yhtä suuria.\n", luku1, luku2);
    }
}

void vertailu_float(float luku1, float luku2) {
    float fSuurempi;
    float fPienempi;
    
    if (luku1 > luku2) {
        fSuurempi = luku1;
        fPienempi = luku2;
        printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", fSuurempi, fPienempi);

    } else if (luku2 > luku1) {
        fSuurempi = luku2;
        fPienempi = luku1;
        printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", fSuurempi, fPienempi);
    } else {
        printf("Luvut %5.2f ja %5.2f ovat yhtä suuria.\n", luku1, luku2);
    }
}


int main(void) {

    int luku1;
    int luku2;
    float luku3;
    float luku4;
    char nimi1[20];
    char nimi2[20];
    int tulos;

    printf("Anna kaksi kokonaislukua:\n");
    printf("Luku 1: ");
    scanf("%d", &luku1);
    printf("Luku 2: ");
    scanf("%d", &luku2);

    vertailu_int(luku1, luku2);
    
    printf("Anna kaksi desimaalilukua:\n");
    printf("Luku 1: ");
    scanf("%f", &luku3);
    printf("Luku 2: ");
    scanf("%f", &luku4);

    vertailu_float(luku3, luku4);

    printf("Anna kaksi nimeä:\n");
    printf("Nimi 1: ");
    scanf("%s", nimi1);
    printf("Nimi 2: ");
    scanf("%s", nimi2);

    tulos = strcmp(nimi1, nimi2);

    if (tulos == 0) {
        printf("Merkkijonona '%s' ja '%s' ovat yhtä suuria.\n", nimi1, nimi2);
    } else if (tulos > 0) {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", nimi1, nimi2);
    } else {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", nimi2, nimi1);
    }

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}