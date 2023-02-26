#include <stdio.h>
#include <stdlib.h>

typedef struct autot{
    int vuosiluku;
    char automerkki[30];
    struct autot *pNext;
} AUTOT;

AUTOT *lisaaListaan(AUTOT *pS, char *tNimi);
AUTOT *vapautaMuisti(AUTOT *pS);
void tulosta(AUTOT *pS);

AUTOT *lisaaListaan(AUTOT *pS, char *tNimi) {
    char sisalto[30];
    FILE *tiedosto;
    AUTOT *pNew, *ptr;

    if ((tiedosto = fopen(tNimi, "r")) == NULL) {
        perror("Tiedoston avaus epäonnistui.\n");
        exit(0);
    }
    if ((pNew = (AUTOT*)malloc(sizeof(AUTOT))) == NULL) {
        perror("Muistinvaraus epäonnistui");
        exit(0);
    }

    printf("Luetaan tiedot tiedostosta %s.", tNimi);

    while(fgets(sisalto, 30, tiedosto) != NULL) {
        pNew->automerkki = sisalto;
        pNew->vuosiluku = atoi(sisalto);
        pNew->pNext = NULL;

        if (pS == NULL) {
            pS = pNew;
        } else {
            ptr = pS;
            while (ptr->pNext != NULL) {
                ptr = ptr->pNext;
            }
            ptr->pNext = pNew;
        }
    }


}


int main(int argc, char *argv[]) {

    if (argc < 1) {
        printf("Et antanut tiedoston nimeä.\n");
        exit(0);
    }


    return 0;
}