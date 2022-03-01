/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Arno Törö
 * Opiskelijanumero: 0570180
 * Päivämäärä: 19.4.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Luentomoniste, aiemmat harjoitukset, Google
 */
 /*******************************************************************/

#include "ali1.h"
#include "ali2.h"

tilaData* lueTiedosto(tilaData* pAlku, char* tiedostoNimi) {
    FILE* tiedosto;
    int tKayttajat;
    int v;
    char tilanNimi[30];
    int kk;
    int p;
    int t;
    int m;
    int epo;
    char puskuri[256];
    int riviLkm = 0;
    tilaData* pLoppu = NULL, * ptr = NULL;

    printf("Luetaan tiedosto '%s'\n", tiedostoNimi);

    if ((tiedosto = fopen(tiedostoNimi, "r")) != NULL) {
        fgets(puskuri, 256, tiedosto); // Luetaan otsikkorivi pois

        while (fscanf(tiedosto, "%29[^;];%d;%d;%d;%d;%d;%d;%d\n", tilanNimi, &epo, &p, &kk, &v, &t, &m, &tKayttajat) != EOF) {
            // Käydään käyttötiedosto läpi ja tallennetaan puolipisteillä erotetut arvot omiin muuttujiinsa.

            if ((ptr = (tilaData*)malloc(sizeof(tilaData))) == NULL) {
                // Mikäli muistin varaus epäonnistuu, varoitetaan siitä käyttäjää.
                perror("Muistin varaus epäonnistui\n");
                exit(1);
            }

            // Tallennetaan luettu data linkitettyyn listaan.
            strncpy(ptr->tilanNimi, tilanNimi, 29);
            ptr->tilanKayttajat = tKayttajat;
            ptr->vuosi = v;
            ptr->kuukausi = kk;
            ptr->paiva = p;
            ptr->tunti = t;
            ptr->minuutti = m;
            ptr->ePoch = epo;
            ptr->seuraava = NULL;

            // Lisätään listan loppuun uusi alkio.
            if (pAlku == NULL) {
                pAlku = ptr;
                pLoppu = ptr;
            }
            else {
                pLoppu->seuraava = ptr;
                pLoppu = ptr;
            }
            riviLkm++;
        }
        printf("Tiedosto '%s' luettu, %d riviä.\n", tiedostoNimi, riviLkm);
    }
    else {
        // Mikäli luettavaa tiedostoa ei ole olemassa tai jokin muu menee pieleen, huomautetaan taas käyttäjää.
        perror("Tiedoston lukeminen epäonnistui");
        exit(0);
    }

    fclose(tiedosto);
    return pAlku;
}


void tallennaLista(tilaData* pAlku, char* opetusTila) {
    tilaData* ptr = pAlku;
    FILE* tiedosto;

    if ((tiedosto = fopen("tulostiedot.txt", "w")) != NULL) {
        // Tulostetaan tiedoston alkuun tallennettavan opetustilan nimi ja sarakkeet.
        fprintf(tiedosto, "Opetustila: %s\n", opetusTila);
        fprintf(tiedosto, "Pvm Klo Lkm\n");

        while (ptr != NULL) {
            // Käydään linkitetty lista läpi ja tulostetaan data tiedostoon
            if (strcmp((ptr->tilanNimi), (opetusTila)) == 0) {
                fprintf(tiedosto, "%d.%d.%d %02d:%02d %d\n", (ptr->paiva), (ptr->kuukausi), (ptr->vuosi), (ptr->tunti), (ptr->minuutti), (ptr->tilanKayttajat));
            }
            ptr = ptr->seuraava;
        }
        printf("Käyttödata tallennettu.\n");
    }
    else {
        // Jos taas jokin meni pieleen, huomautetaan käyttäjää.
        perror("Tiedostoon kirjoittaminen epäonnistui");
        exit(0);
    }
    fclose(tiedosto); 
}
/*******************************************************************/
/* eof */
