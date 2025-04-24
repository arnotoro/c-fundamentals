#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51
#define FILENAME 31
#define TASK 6

typedef struct tehdytTehtavat {
    char tehtava[TASK];
    int tekijatLKM;
    struct tehtavat *pNext;
} TT;

void kysyTiedostonNimi(char *tiedostonNimi);
TT *lueTiedosto(TT *pA, char *tiedostonNimi);
TT *varaaMuisti(TT *pA);
void tulostaLista(TT *pA);
TT *vapautaMuisti(TT *pA);

int main(void) {
    char tiedostonNimi[FILENAME];
    TT *pAlku = NULL;

    kysyTiedostonNimi(tiedostonNimi);
    pAlku = lueTiedosto(pAlku, tiedostonNimi);

    tulostaLista(pAlku);
    pAlku = vapautaMuisti(pAlku);

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

void kysyTiedostonNimi(char *tiedostonNimi) {
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", tiedostonNimi);
}

TT *lueTiedosto(TT *pA, char *tiedostonNimi) {
    FILE *tiedosto;
    char *tehtava;
    char rivi[MAX];
    int tekijatLKM;
    TT *pUusi, *ptr;

    if ((tiedosto = fopen(tiedostonNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    while(fgets(rivi, MAX, tiedosto) != NULL) {
        tehtava = strtok(rivi, ";");
        tekijatLKM = atoi(strtok(NULL, " "));

        pUusi = varaaMuisti(pUusi);

        strcpy(pUusi->tehtava, tehtava);
        pUusi->tekijatLKM = tekijatLKM;
        pUusi->pNext = NULL;

        if (pA == NULL) {
            pA = pUusi;
        } else {
            ptr = pA;
            while (ptr->pNext != NULL) {
                ptr = ptr->pNext;
            }
            ptr->pNext = pUusi;
        }
    }
    printf("Tiedosto '%s' luettu linkitettyyn listaan.\n", tiedostonNimi);
    fclose(tiedosto);
    return pA;
}

TT *varaaMuisti(TT *pA) {
    TT *pUusi = NULL;

    if ((pUusi = (TT *)malloc(sizeof(TT))) == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }

    pUusi->pNext = pA;
    return pUusi;
}

void tulostaLista(TT *pA) {
    TT *ptr = pA;

    printf("Tehtäviä tehtiin seuraavasti:\n");

    while (ptr != NULL) {
        printf("Tehtävän %s teki %d opiskelijaa.\n", ptr->tehtava, ptr->tekijatLKM);
        ptr = ptr->pNext;
    }

    printf("\n");
    return;
}

TT *vapautaMuisti(TT *pA) {
    TT *ptr = pA;

    while (ptr != NULL) {
        pA = ptr->pNext;
        free(ptr);
        ptr = pA;
    }
    printf("Muisti vapautettu.\n");
    return pA;
}
