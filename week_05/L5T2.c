#include <stdio.h>
#include <stdlib.h>

int tarkistaSyote(char* input);
int* varaaMuisti(int koko);
void taytaTaulukko(int *osoitin, int lukumaara);
void tulostaTaulukko(int *osoitin, int lukumaara);
void vapautaMuisti(int *osoitin);


int main(int argc, char *argv[]) {
    int koko, *osoitin;
    if (argc <= 1 ) {
        printf("Et antanut taulukon kokoa.");
        return 0;
    } else {
        koko = tarkistaSyote(argv[1]);
        if (koko != 0) {
            osoitin = varaaMuisti(koko);
            taytaTaulukko(osoitin, koko);
            tulostaTaulukko(osoitin, koko);
            vapautaMuisti(osoitin);
        }
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

int tarkistaSyote(char* input) {
    int luku;

    luku = atoi(input);

    if (luku > 0) {
        return luku;
    } else {
        printf("Parametri ei ollut positiivinen kokonaisluku.");
        return 0;
    }
}

int* varaaMuisti(int koko) {
    int *pLuku;
    if ((pLuku = (int*)malloc(koko * sizeof(int))) == NULL) {
        perror("Muistin varaus epäonnistui.");
        exit(1);
    }
    printf("Muistin varaus onnistui.\n");
    return pLuku;
}

void taytaTaulukko(int *osoitin, int lukumaara) {
    int i, count = 1;
    printf("Taulukossa on tilaa %d alkiolle.\n", lukumaara);
    for (i = 0; i < lukumaara; i++, count++) {
        printf("Anna %d. luku: ", count);
        scanf("%d", &osoitin[i]);
    }
    printf("Taulukko täytetty.\n");
}

void tulostaTaulukko(int *osoitin, int lukumaara) {
    int i;

    printf("Taulukossa on luvut: ");
    for(i = 0; i < lukumaara; i++) {
        printf("%d ", osoitin[i]);
    }
    printf("\nTaulukko tulostettu.\n");
}

void vapautaMuisti(int *osoitin) {
    free(osoitin);
    printf("Muisti vapautettu.\n");
}