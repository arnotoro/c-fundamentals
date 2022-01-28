#include <stdio.h>
#include <stdlib.h>
#define MAXPITUUS 48

int valikko(void);
int tiedostonkirjoitus(char *tnimi);
int tiedostonlukeminen(char *tnimi);

int valikko(void) {
    int valinta;
    printf("Valitse alla olevista valinnoista\n");
    printf("1) Lisää uusi nimi\n");
    printf("2) Tulosta nimet\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &valinta);
    getchar();

    return valinta;
}

int tiedostonkirjoitus(char *tnimi) {
    char nimi[MAXPITUUS];
    FILE* tiedosto;

    printf("Anna lisättävä nimi: ");
    scanf("%s", nimi);
    

    if ((tiedosto = fopen(tnimi, "a")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    fprintf(tiedosto, "%s\n", nimi);

    fclose(tiedosto);

    printf("Nimi lisätty tiedostoon.\n");
    return 0;
}

int tiedostonlukeminen(char *tnimi) {
    char tuloste[MAXPITUUS];
    FILE *tiedosto;

    if ((tiedosto = fopen(tnimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    printf("Tiedostossa olevat nimet:\n");
    while (fgets(tuloste, MAXPITUUS, tiedosto) != NULL) {
        printf("%s", tuloste);
    }

    
    fclose(tiedosto);
    printf("Tiedosto luettu ja tulostettu.\n");
    return 0;
}

int main(void) {
    char tnimi[30];
    int valinta;

    printf("Tämä ohjelma lisää nimiä tiedostoon ja lukee ne.\n");
    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf("%s", tnimi);

    while(1)  {
        valinta = valikko();
        if (valinta == 1) {
            tiedostonkirjoitus(tnimi);
            printf("\n");
            continue;
        } else if (valinta == 2) {
            tiedostonlukeminen(tnimi);
            printf("\n");
            continue;
        } else if (valinta == 0) {
            break;
        } else {
            printf("Väärä valinta.\n");
            continue;
        }
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}