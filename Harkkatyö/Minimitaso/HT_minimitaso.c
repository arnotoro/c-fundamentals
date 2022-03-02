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
#include <limits.h>
#define MAX 255

typedef struct sahkoData {
    char aikaLeima[MAX];
    long kulutus;
    struct sahkoData *pSeuraava;
} SAHKODATA;

typedef struct tulosData {
    long kumulKulutus;
    char aikaLeima[MAX];
    struct tulosData *pSeuraava;
} TULOSDATA;

int valikko(void);
void kysyTNimi(char *kysymys, char *tiedostoNimi);
SAHKODATA *lueTiedosto(SAHKODATA *pAlku, char *tiedostoNimi);
TULOSDATA *analysoiTiedot(SAHKODATA *pAlku, TULOSDATA *pAlkuT);

int main(void) {
    int iValinta = 1;
    char tiedostoNimi[MAX];
    SAHKODATA *pAlkuS = NULL, *pLoppuS = NULL;
    TULOSDATA *pAlkuT = NULL, *pLoppuT = NULL;


    do {
        iValinta = valikko();
        if (iValinta == 1) {
            kysyTNimi("Anna luettavan tiedoston nimi: ",tiedostoNimi);
            pAlkuS = lueTiedosto(pAlkuS, tiedostoNimi);
        }
        else if (iValinta == 2) {
            analysoiTiedot(pAlkuS, pAlkuT);
        }
        else if (iValinta == 3) {
        }
        else if (iValinta == 0) {
        }
        else {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("\n");
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

void kysyTNimi(char *kysymys, char *tiedostoNimi) {
    printf("%s", kysymys);
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

TULOSDATA *analysoiTiedot(SAHKODATA *pAlkuS, TULOSDATA *pAlkuT) {
    SAHKODATA *pSahko = pAlkuS;
    TULOSDATA *ptr, *pUusi;
    long count = 0, kokoKulutus = 0, maxKulutus = 0, minKulutus = INT_MAX;
    char maxTime[MAX], minTime[MAX];
    double Avg;


    while (pSahko != NULL) {
        if ((pUusi = (TULOSDATA*)malloc(sizeof(TULOSDATA))) == NULL) {
            perror("Muistin varaus epäonnistui, lopetetaan");
            exit(0);
        }

        if ((pSahko->kulutus) > (maxKulutus)) { // Maksimin etsiminen
            maxKulutus = pSahko->kulutus;
            strcpy(maxTime, pSahko->aikaLeima);
        }
        else if ((minKulutus) > (pSahko->kulutus)) { // Minimi
            minKulutus = pSahko->kulutus;
            strcpy(minTime, pSahko->aikaLeima);
        }


        kokoKulutus += pSahko->kulutus;
        pUusi->kumulKulutus = kokoKulutus; // Kumulatiivinen kulutus
        strcpy(pUusi->aikaLeima, pSahko->aikaLeima);
        count++; // Mittaustulosten määrä

        if (pAlkuT == NULL) {
            pAlkuT = pUusi;
        }
        else {
            ptr = pAlkuT;
            while (ptr->pSeuraava != NULL) {
                ptr = ptr->pSeuraava;
            }
            ptr->pSeuraava = pUusi;
        }

        pSahko = pSahko->pSeuraava;
    }

    Avg = ((double)(pUusi->kumulKulutus)/(double)count); // Keskiarvon laskeminen

    printf("Tilastotiedot %d mittaustuloksesta:\n", count);
    printf("Kulutus oli yhteensä %ld kWh, ja keskimäärin %.1f kWh.\n", pUusi->kumulKulutus, Avg);
    printf("Suurin kulutus, %d kWh, tapahtui %s.\n", maxKulutus, maxTime);
    printf("Pienin kulutus, %d kWh, tapahtui %s.\n", minKulutus, minTime);

    return pAlkuT;
}
/* eof */