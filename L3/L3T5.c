#include <stdio.h>
#include <stdlib.h>
#define MAX 48


int kirjoitaTiedosto(char *tiedostonNimi, int alustus);
int lueTiedosto(char *tiedostonNimi);

int kirjoitaTiedosto(char *tiedostonNimi, int alustus) {
    int i;
    int r;
    FILE *tiedosto;

    srand(alustus);

    if ((tiedosto = fopen(tiedostonNimi, "wb")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    for(i = 0; i < 20; i++) {
        r = (rand() % (999+1-0)+0);
        fwrite(&r, sizeof(r), 1, tiedosto);
    }
    fclose(tiedosto);
    return 0;
}

int lueTiedosto(char *tiedostonNimi) {
    FILE *tiedosto;
    int luku;
    int i;

    if ((tiedosto = fopen(tiedostonNimi, "rb")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan:");
        exit(0);
    }    

    printf("Tiedostossa on seuraavat luvut:\n");
    for(i = 0; i<20; i++) {
        fread(&luku, sizeof(luku), 1, tiedosto);
        printf("%d ", luku);
    }
    fclose(tiedosto);
    return 0;
}




int main(void) {
    char tnimi[MAX];
    int alkuarvo;

    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf("%s", tnimi);

    printf("Anna satunnaisluvuille lähtöarvo: ");
    scanf("%d", &alkuarvo);

    if (kirjoitaTiedosto(tnimi, alkuarvo) == 0) {
        printf("Tiedoston kirjoitus onnistui.\n");
    }
    if (lueTiedosto(tnimi) == 0) {
        printf("\nTiedoston lukeminen onnistui.\n");
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}