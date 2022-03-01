#pragma once
/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Arno Törö
 * Opiskelijanumero: 0570180
 * Päivämäärä: 19.4.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Luentomoniste, aiemmat harjoitukset, Google
 */
 /*******************************************************************/

#ifndef ali1_h_
#define ali1_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct NODE { // Tietueen määrittely listalle.
    int tilanKayttajat;
    char tilanNimi[30];
    int vuosi;
    int kuukausi;
    int paiva;
    int tunti;
    int minuutti;
    int ePoch;
    struct NODE* seuraava;
};
typedef struct NODE tilaData;

tilaData* lueTiedosto(tilaData* pAlku, char* tiedostoNimi);
void tallennaLista(tilaData* pAlku, char* opetusTila);

#endif
/*******************************************************************/
/* eof */
