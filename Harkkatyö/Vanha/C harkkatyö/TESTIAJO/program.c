/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Arno Törö
 * Opiskelijanumero: 0570180
 * Päivämäärä: 28.3.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Luentomoniste, aiemmat harjoitukset, Google
 */
 /*******************************************************************/

#include "ali1.h"
#include "ali2.h"

int valikko(void) {
    //Valikko ohjelma tulostaa valikon ja palauttaa käyttältä kysytyn syötteen.
    int valinta;

    printf("\nValitse haluamasi toiminto alla olevasta valikosta:\n");
    printf("1) Lue tilan käyttö -tiedosto\n");
    printf("2) Tallenna listan tiedot\n");
    printf("3) Analysoi tiedot\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &valinta);

    return valinta;
}

int main(void) {
    tilaData* pAlku = NULL;
    int iValinta = -1;
    char tiedostonNimi[50];
    char tilanNimi[50];
    char* kysyTiedosto = "Anna luettavan tiedoston nimi: ";
    char* kysyTila = "Anna opetustilan nimi: ";


    printf("Tämä ohjelma analysoi tilan käyttö -tiedostoja.\n");

    while (iValinta != 0) {
        iValinta = valikko();
        if (iValinta == 1) {
            if (pAlku != NULL) {
                // Tyhjennetään lista, jos siinä on jo dataa.
                muistinTyhjennys(pAlku);
                pAlku = NULL;
            }
            kysyNimi(kysyTiedosto, tiedostonNimi);
            pAlku = lueTiedosto(pAlku, tiedostonNimi);
        }
        else if (iValinta == 2) {
            if (pAlku == NULL) {
                // Linkitetty lista luodaan käyttötiedostoa luettaessa, jos niin ei ole tehty
                // , käyttäjää opastetaan lukemaan käsiteltävä tiedosto ensimmäiseksi
                printf("Ei tallennettavaa, lue ensin käyttötiedosto.\n");
            }
            else {
                kysyNimi(kysyTila, tilanNimi);
                tallennaLista(pAlku, tilanNimi);
            }
        }
        else if (iValinta == 3) {
            if (pAlku == NULL) {
                // Kts. valinta 2
                printf("Ei analysoitavaa, lue ensin käyttötiedosto.\n");
            }
            else {
                kysyNimi(kysyTila, tilanNimi);
                analysoiData(pAlku, tilanNimi);
            }
        }
        else if (iValinta == 0) {
            muistinTyhjennys(pAlku);
            break;
        }
        else {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    }

    printf("Kiitos ohjelman käytöstä.\n\n");
    return 0;
}
/*******************************************************************/
/* eof */
