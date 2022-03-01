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

void kysyNimi(char* kysymys, char* tnimi) {
    // Tämä funktio tulostaa sille parametrina annetun kysymyksen ja tallentaa käyttäjän vastauksen muuttujaan.
    printf("%s", kysymys);
    scanf("%s", tnimi);
}


void analysoiData(tilaData* pAlku, char* opetusTila) {
    tilaData* ptr = pAlku;
    int kaytMIN = 0;
    int kaytMAX = 0;
    int kaytAVG = 0;
    int nCount = 0;
    int kaytALL = 0;


    while (ptr != NULL) {
        // Käydään lista lävitse.

        if (strcmp((ptr->tilanNimi), (opetusTila)) == 0) {
            // Otetaan huomioon vain halutun tilan data.

            if (kaytMIN > (ptr->tilanKayttajat)) {
                // Selvitetään tilan pienin käyttäjämäärä vertaamalla arvoja toisiinsa ja tallentamalla se muuttujaan.
                kaytMIN = ptr->tilanKayttajat;
            }
            else if (kaytMAX < (ptr->tilanKayttajat)) {
                // Sama kuin yllä mutta suurin käyttäjämäärä.
                kaytMAX = ptr->tilanKayttajat;
            }

            kaytALL += ptr->tilanKayttajat; // Lasketaan kaikki käyttäjät yhteen.
            nCount++; // Pidetään kirjaa tilan datapisteiden määrästä.
        }

        ptr = ptr->seuraava;
    }

    kaytAVG = (kaytALL) / nCount; // Käyttäjämäärän keskiarvon laskeminen

    // Tulostetaan tulokset näytölle 5 merkkiä leveään tilaan.
    printf("Opetustilan %s käyttöanalyysi,%5.d alkiota:\n", opetusTila, nCount);
    printf("  Avg  Min  Max\n");
    printf("%5d%5d%5d\n", kaytAVG, kaytMIN, kaytMAX);

}

void muistinTyhjennys(tilaData* pAlku) {
    // Aliohjelma, joka vapauttaa varatun muistin.
    if (pAlku != NULL) {
        tilaData* tmp = pAlku;

        while (pAlku != NULL){
            pAlku = tmp->seuraava;
            free(tmp);
            tmp = pAlku;
        }
    }
}
/*******************************************************************/
/* eof */
