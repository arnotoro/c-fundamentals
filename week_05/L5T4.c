#include <stdio.h>
#include <stdlib.h>

int tarkistaSyote(int input);
int* varaaMuisti(int koko, int *osoitin);
void tulostaTaulukko(int *osoitin, int lukumaara);
int tulostaValikko(int valinta);
void vapautaMuisti(int *osoitin);


int main(void) {
    int valinta = 1, koko = 1;
    int *osoitin = NULL;
    int save = 1;
    int testi;

    while(valinta != 0) {
        valinta = tulostaValikko(valinta);
        
        if (valinta == 1) {
            tulostaTaulukko(osoitin, save);
        } else if (valinta == 2) {
            printf("Anna taulukon uusi koko: ");
            scanf("%d", &koko);
            testi = tarkistaSyote(koko);
            if (testi != 0) {
                osoitin = varaaMuisti(koko, osoitin);
                save = koko;
            }
        } else if (valinta == 0) {
            vapautaMuisti(osoitin);
        } else {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

int tulostaValikko(int valinta) {
    printf("1) Tulosta taulukon alkiot\n");
    printf("2) Muuta taulukon kokoa\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &valinta);
    return valinta;
}


int tarkistaSyote(int input) {
    if (input > 0) {
        return input;
    } else if (input == 0) {
        return 1;
    } else {
        printf("Taulukon koko ei voi olla negatiivinen.\n");
        return 0;
    }
}

int* varaaMuisti(int koko, int *osoitin) {
    int *pLuku;
    int i;
        if ((pLuku = (int*)realloc(osoitin, koko * sizeof(int))) == NULL) {
            perror("Muistin varaus epäonnistui.");
            exit(1);
        }  else{
            for (i=0;i<koko;i++) {
                pLuku[i]=i;
            }
        }
    return pLuku;
}

void tulostaTaulukko(int *osoitin, int lukumaara) {
    int i;
    if (osoitin == NULL || lukumaara == 0) {
        printf("Taulukko on tyhjä.\n");
    } else{
        printf("Taulukon alkiot ovat: ");
        for(i = 0; i < lukumaara; i++) {
            printf("%d ", osoitin[i]);
        }
        printf("\n");
    }
}

void vapautaMuisti(int *osoitin) {
    free(osoitin);
    printf("Muisti vapautettu.\n");
}