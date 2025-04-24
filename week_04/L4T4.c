#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3
#define MAX 100

char *kysyNimi(char *tiedostoNimi);
void tulostaMatriisi(int matriisi[ROW][COL], char *tiedostoNimi, FILE *tietoVirta);

int main(void) {
    int i, j;
    int matriisi[ROW][COL];
    char tiedostoNimi[MAX];
    char *ptr = &tiedostoNimi;
    FILE *file;

    ptr = kysyNimi(ptr);
    printf("Anna arvot lähtömatriisille: \n");

    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("Rivi %d, alkio %d: ", i + 1, j + 1);
            scanf("%d", &matriisi[i][j]);
        }
    }

    if ((file = fopen(ptr, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    tulostaMatriisi(matriisi, tiedostoNimi, file);
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}


char *kysyNimi(char *ptr) {
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", ptr);
    getchar();

    return ptr;
}

void tulostaMatriisi(int matriisi[ROW][COL], char *tiedostoNimi, FILE *tietoVirta) {
    int transpoosi[ROW][COL];

    printf("\nLähtömatriisi: \n");
    fprintf(tietoVirta, "Lähtömatriisi: \n");
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%4d ", matriisi[i][j]);
            fprintf(tietoVirta, "%4d ", matriisi[i][j]);
        }
        printf("\n");
        fprintf(tietoVirta, "\n");
    }

    printf("\nLähtömatriisin transpoosi: \n");
    fprintf(tietoVirta, "\nLähtömatriisin transpoosi: \n");

    // matriisin transpoosi
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            transpoosi[j][i] = matriisi[i][j];
        }
    }

    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%4d ", transpoosi[i][j]);
            fprintf(tietoVirta, "%4d ", transpoosi[i][j]);
        }
        printf("\n");
        fprintf(tietoVirta, "\n");
    }

    printf("\nTiedosto '%s' kirjoitettu.\n", tiedostoNimi);
    fclose(tietoVirta);
}