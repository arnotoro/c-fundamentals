#include <stdio.h>

#define MAX 30

int valikko();
int lisaaLukuun(char* fileName, int iLuku);
int tulostaTiedosto(char *fileName);

int main (void) {
    int iLuku = 0;
    int iValinta = 0;
    int iMuutos = 0;
    char fileName[MAX];

    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);

    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", fileName);

    do {
        iValinta = valikko();

        if (iValinta == 1) {
            iLuku = lisaaLukuun(fileName, iLuku);
        } else if (iValinta == 2) {
            tulostaTiedosto(fileName);
        } else if (iValinta == 0) {
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
    printf("2) Tulosta tulokset\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &iValinta);
    getchar();

    return iValinta;
}

int lisaaLukuun(char* fileName, int iLuku) {
    FILE *file;
    int iLisays = 0;
    int iSumma = 0;

    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &iLisays);
    iSumma = iLuku + iLisays;

    printf("%d+%d=%d\n", iLuku, iLisays, iSumma);

    if ((file = fopen(fileName, "a")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    fprintf(file, "%d+%d=%d\n", iLuku, iLisays, iSumma);


    fclose(file);
    return iSumma;
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