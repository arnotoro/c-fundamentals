/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Tekijä: Arno Törö
 * Opiskelijanumero: 
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
SAHKODATA *lisaaListaan(SAHKODATA *pAlku, char *tietoRivi);
TULOSDATA *analysoiTiedot(SAHKODATA *pAlku, TULOSDATA *pAlkuT);
void kirjoitaTiedosto(TULOSDATA *pAlku, char *tiedostoNimi);
SAHKODATA *tyhjennaSahko(SAHKODATA *pAlku);
TULOSDATA *tyhjennaTulos(TULOSDATA *pAlku);

int main(void) {
    int iValinta = 1;
    char tiedostoNimi[MAX];
    SAHKODATA *pAlku = NULL;
    TULOSDATA *pAlkuT = NULL;

    do {
        iValinta = valikko();
        if (iValinta == 1) {
            kysyTNimi("Anna luettavan tiedoston nimi: ",tiedostoNimi);
            pAlku = lueTiedosto(pAlku, tiedostoNimi);
        }
        else if (iValinta == 2) {
            if (pAlku == NULL) {
                printf("Ei analysoitavaa, lue tiedosto ennen analyysiä.\n");
            } 
            else {
                pAlkuT = analysoiTiedot(pAlku, pAlkuT);
            }
        }
        else if (iValinta == 3) {
            if (pAlkuT == NULL) { 
                printf("Ei kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n");

            }
            else  {
                kysyTNimi("Anna kirjoitettavan tiedoston nimi: ", tiedostoNimi);
                kirjoitaTiedosto(pAlkuT, tiedostoNimi);
            }
        }
        else if (iValinta == 0) {
            break;
        }
        else {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("\n");
    } while (iValinta != 0);
    
    printf("\nKiitos ohjelman käytöstä.\n");
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
    char otsikkoRivi[MAX], rivi[MAX];

    if (pAlku != NULL) {
        pAlku = tyhjennaSahko(pAlku);
    }
    
    if ((tiedosto = fopen(tiedostoNimi, "r")) != NULL) {
        printf("Tiedosto '%s' luettu.\n", tiedostoNimi);
        
        fgets(otsikkoRivi, MAX, tiedosto); // Luetaan otsikkorivi pois.
        while (fgets(rivi, MAX, tiedosto) != NULL) {
            pAlku = lisaaListaan(pAlku, rivi);
        }
        fclose(tiedosto);
    }
    else {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    return pAlku;
}


SAHKODATA *lisaaListaan(SAHKODATA *pAlku, char *tietoRivi) {
    SAHKODATA *pUusi = NULL, *ptr = NULL;
    char *aika, *viikko, *kulutus;

    if ((pUusi = (SAHKODATA *)malloc(sizeof(SAHKODATA))) == NULL) {
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }
    
    aika = strtok(tietoRivi, ";");
    viikko = strtok(NULL, ";"); // Ei tarvita, ohitetaan.
    kulutus = strtok(NULL, ";");

    strcpy(pUusi->aikaLeima, aika);
    pUusi->kulutus = atol(kulutus);
    pUusi->pSeuraava = NULL;

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
    return (pAlku);
}

TULOSDATA *analysoiTiedot(SAHKODATA *pAlkuS, TULOSDATA *pAlkuT) {
    TULOSDATA *ptr = NULL, *pUusi = NULL;
    long kokoKulutus = 0, maxKulutus = 0, minKulutus = INT_MAX;
    int count = 0;
    char maxTime[MAX], minTime[MAX];
    double avg;

    if (pAlkuT != NULL) {
        pAlkuT = tyhjennaTulos(pAlkuT);
    }

    while (pAlkuS != NULL) {
        if ((pUusi = (TULOSDATA*)malloc(sizeof(TULOSDATA))) == NULL) {
            perror("Muistin varaus epäonnistui, lopetetaan");
            exit(0);
        }

        if ((pAlkuS->kulutus) > (maxKulutus)) { // Maksimin etsiminen
            maxKulutus = pAlkuS->kulutus;
            strcpy(maxTime, pAlkuS->aikaLeima);
        }
        else if ((minKulutus) > (pAlkuS->kulutus)) { // Minimi
            minKulutus = pAlkuS->kulutus;
            strcpy(minTime, pAlkuS->aikaLeima);
        }

        kokoKulutus += pAlkuS->kulutus;
        pUusi->kumulKulutus = kokoKulutus; // Kumulatiivinen kulutus

        strcpy(pUusi->aikaLeima, pAlkuS->aikaLeima);
        pUusi->pSeuraava = NULL;
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

        pAlkuS = pAlkuS->pSeuraava;
    }

    avg = ((double)(pUusi->kumulKulutus)/(double)count); // Keskiarvon laskeminen

    printf("Tilastotiedot %d mittaustuloksesta:\n", count);
    printf("Kulutus oli yhteensä %ld kWh, ja keskimäärin %.1f kWh.\n", pUusi->kumulKulutus, avg);
    printf("Suurin kulutus, %ld kWh, tapahtui %s.\n", maxKulutus, maxTime);
    printf("Pienin kulutus, %ld kWh, tapahtui %s.\n", minKulutus, minTime);

    return pAlkuT;
}

void kirjoitaTiedosto(TULOSDATA *pAlku, char *tiedostoNimi) {
    FILE *tiedosto;
    TULOSDATA *ptr = pAlku;

    if ((tiedosto = fopen(tiedostoNimi, "w")) != NULL) {
        printf("Tiedosto '%s' kirjoitettu.\n", tiedostoNimi);
        
        fprintf(tiedosto, "Tarkastelujakson kumulatiivinen sähköntuotanto:\n");
        fprintf(tiedosto, "Pvm;Kumulatiivinen kulutus (kWh)\n");

        while(ptr != NULL) {
            fprintf(tiedosto, "%s;%ld\n", (ptr->aikaLeima), (ptr->kumulKulutus));
            ptr = ptr->pSeuraava;
        }
        fclose(tiedosto);
    }
    else {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    return;
}

SAHKODATA *tyhjennaSahko(SAHKODATA *pAlku) {
    SAHKODATA *ptr = pAlku;
    while (ptr != NULL) {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    //printf("Muisti vapautettu.");
    return NULL;
}

TULOSDATA *tyhjennaTulos(TULOSDATA *pAlku) {
    TULOSDATA *ptr = pAlku;
    while (ptr != NULL) {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    //printf("Muisti vapautettu.");
    return NULL;
}
/* eof */