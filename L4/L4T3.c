#include <stdio.h>

#define MAX 30

typedef struct Lasku {
    int luku1;
    int luku2;
    int summa;
} LASKUTOIMITUS; 


int valikko();
void kysyTiedostonNimi(char *fileName);
int lisaaLukuun(int iLuku, int indeksi, LASKUTOIMITUS laskuHistoria[]);
int kirjoitaTiedosto(char *fileName, int indeksi, LASKUTOIMITUS laskuHistoria[]);
int tulostaTiedosto(char *fileName);

int main (void) {
    int iLuku = 0;
    int iValinta = 0;
    int indeksi = 0;
    char fileName[MAX];

    LASKUTOIMITUS laskuHistoria[MAX];

    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);

    kysyTiedostonNimi(fileName);

    do {
        iValinta = valikko();

        if (iValinta == 1) {
            indeksi = lisaaLukuun(iLuku, indeksi, laskuHistoria);
        } else if (iValinta == 2) {
            kirjoitaTiedosto(fileName, indeksi, laskuHistoria);
        } else if (iValinta == 3) { 
            tulostaTiedosto(fileName);
        } else if (iValinta == 0) {
            //printf("%d + %d = %d\n", laskuHistoria[0].luku1, laskuHistoria[0].luku2, laskuHistoria[0].summa);
            printf("\nLopetetaan.\n");
            break;
        } else {
            printf("\nTuntematon valinta, yritä uudestaan.\n");
            continue;
        }        
    } while (iValinta != 0);

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}

int valikko() {
    int iValinta = 0;
    
    printf("\nValitse haluamasi toiminto:\n");
    printf("1) Lisää lukuun\n");
    printf("2) Kirjoita historia tiedostoon\n");
    printf("3) Lue historia tiedostosta\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &iValinta);
    getchar();

    return iValinta;
}

void kysyTiedostonNimi(char *fileName) {
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", fileName);
}

int lisaaLukuun(int iLuku, int indeksi, LASKUTOIMITUS laskuHistoria[]) {
    int iLisays = 0;
    int iSumma = 0;

    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &iLisays);

    if (indeksi > 0) {
        laskuHistoria[indeksi].luku1 = laskuHistoria[indeksi-1].summa;
        laskuHistoria[indeksi].luku2 = iLisays;
        laskuHistoria[indeksi].summa = laskuHistoria[indeksi-1].summa + iLisays;
        printf("%d+%d=%d\n", laskuHistoria[indeksi-1].summa, laskuHistoria[indeksi].luku2, laskuHistoria[indeksi].summa);
    } else {
        laskuHistoria[indeksi].luku1 = iLuku;
        laskuHistoria[indeksi].luku2 = iLisays;
        laskuHistoria[indeksi].summa = iLuku + iLisays;
        printf("%d+%d=%d\n", laskuHistoria[indeksi].luku1, laskuHistoria[indeksi].luku2, laskuHistoria[indeksi].summa);
    }

    indeksi++;
    return indeksi;
}

int kirjoitaTiedosto(char *fileName, int indeksi, LASKUTOIMITUS laskuHistoria[]) {
    FILE *file;
    int i = 0;

    if ((file = fopen(fileName, "a")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    for (i = 0; i < indeksi; i++) {
        fprintf(file, "%d+%d=%d\n", laskuHistoria[i].luku1, laskuHistoria[i].luku2, laskuHistoria[i].summa);
    }

    printf("\nTiedosto '%s' kirjoitettu.\n", fileName);

    fclose(file);
    return 0;
}

int tulostaTiedosto(char *fileName) {
    FILE *file;
    char rivi[MAX];

    if ((file = fopen(fileName, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui");
        exit(0);
    }

    printf("\nTiedostossa oleva laskuhistoria:\n");

    while(fgets(rivi, MAX, file) != NULL) {
        printf("%s", rivi);
    }

    printf("Tiedosto '%s' luettu ja tulostettu.\n", fileName);
    fclose(file);
    return 0;
}