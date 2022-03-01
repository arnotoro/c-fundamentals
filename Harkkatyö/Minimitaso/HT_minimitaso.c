/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Tekijä: Arno Törö
 * Opiskelijanumero: 0570180
 * Päivämäärä: 1.3.2022
 * Palauttamalla tämän työn arvioitavaksi vakuutan, että
 * 1) Olen itse kirjoittanut kaiken tässä tiedostossa olevan koodin
 * 2) En ole antanut tätä koodia kenenkään muun käyttöön
 *
 * Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
 * lähteet ja henkilöt, ja se näkyy koodissa seuraavissa kohdissa:
 *
 */
/*************************************************************************/
/* Tehtävä Harkkatyö minimitaso, tiedoston nimi HT_minimitaso.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 255

typedef struct sahkoData {
    char aikaLeima[MAX];
    int kulutus;
    struct sahkoData *pSeuraava;
} SAHKODATA;

int valikko(void);
void kysyTNimi(char *tiedostoNimi);
SAHKODATA *lueTiedosto(SAHKODATA *pAlku, char *tiedostoNimi);
void analysoiTiedot(SAHKODATA *pAlku);

int main(void) {
    int iValinta = 1;
    char tiedostoNimi[MAX];
    SAHKODATA *pAlku = NULL, *pLoppu = NULL;

    do {
        iValinta = valikko();
        if (iValinta == 1) {
            // printf("Anna luettavan tiedoston nimi: ");
            // kysyTNimi(tiedostoNimi);
            pAlku = lueTiedosto(pAlku, "sahko15.csv");
        }
        else if (iValinta == 2) {
            analysoiTiedot(pAlku);
        }
        else if (iValinta == 3) {
        }
        else if (iValinta == 0) {
        }
        else {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    } while (iValinta != 0);

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

int valikko(void) {
    int valinta;

    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi ja tulosta tiedot\n");
    printf("3) Kirjoita tulokset\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &valinta);
    getchar();

    return valinta;
}

void kysyTNimi(char *tiedostoNimi) {
    scanf("%s", tiedostoNimi);
}

SAHKODATA *lueTiedosto(SAHKODATA *pAlku, char *tiedostoNimi) {
    FILE *tiedosto;
    SAHKODATA *pUusi, *ptr;
    char *aika, *viikko, *kulutus;
    char otsikkoRivi[MAX], rivi[MAX];

    if ((tiedosto = fopen(tiedostoNimi, "r")) != NULL) {
        printf("Tiedosto '%s' luettu.\n", tiedostoNimi);
        fgets(otsikkoRivi, MAX, tiedosto); // Luetaan otsikkorivi pois.

        while (fgets(rivi, MAX, tiedosto) != NULL) {
            if ((pUusi = (SAHKODATA *)malloc(sizeof(SAHKODATA))) == NULL) {
                perror("Muistinvaraus epäonnistui, lopetetaan");
                exit(0);
            }
            aika = strtok(rivi, ";");
            viikko = strtok(NULL, ";"); // Ei tarvita, ohitetaan.
            kulutus = strtok(NULL, ";");

            strcpy(pUusi->aikaLeima, aika);
            pUusi->kulutus = atoi(kulutus);

            if (pAlku == NULL) {
                pAlku = pUusi;
            }
            else {
                ptr = pAlku;
                while (ptr->pSeuraava != NULL) {
                    ptr = ptr->pSeuraava;
                }
                ptr->pSeuraava = pUusi;
            }
        }
        return (pAlku);
    }
    else {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fclose(tiedosto);
}

void analysoiTiedot(SAHKODATA *pAlku) {
    SAHKODATA *ptr = pAlku;

    while (ptr != NULL) {
        printf("Aikadata: %s.\n", ptr->aikaLeima);
        printf("Kulutus: %d.\n", ptr->kulutus);
        ptr = ptr->pSeuraava;
    }
    return;
}
/* eof */