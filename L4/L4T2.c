#include <stdio.h>
#define MAX 2


void tulostaMatriisi(int matriisi[MAX][MAX], char *matriisiNimi);

void tulostaMatriisi(int matriisi[MAX][MAX], char *matriisiNimi) {
    int k, l;

    printf("\n%s:\n", matriisiNimi);
    for(k = 0; k<MAX; k++) {
        for(l = 0; l<MAX; l++) {
            printf("%4d ", matriisi[k][l]);
            if(l==1) {
                printf("\n");
            }
        }
    }
}

int main(void) {
    int matriisi1[MAX][MAX];
    int matriisi2[MAX][MAX];
    int summamatriisi[MAX][MAX];
    int i, j;

    printf("Anna arvot yhteenlaskettaville matriiseille:\n");

    printf("Matriisin 1 alkiot:\n");
    for(i = 0; i<MAX; i++) {
        for(j = 0; j<MAX; j++) {
            printf("Rivi %d alkio %d: ", i+1, j+1);
            scanf("%d", &matriisi1[i][j]);
        }
    }

    tulostaMatriisi(matriisi1, "Matriisi 1");
    printf("\nMatriisin 2 alkiot:\n");
    for(i = 0; i<MAX; i++) {
        for(j = 0; j<MAX; j++) {
            printf("Rivi %d alkio %d: ", i+1, j+1);
            scanf("%d", &matriisi2[i][j]);
        }
    }

    tulostaMatriisi(matriisi2, "Matriisi 2");

    for(i = 0; i<MAX; i++) {
        for (j = 0; j<MAX; j++) {
            summamatriisi[i][j] = matriisi1[i][j] + matriisi2[i][j];
        }
    }
    tulostaMatriisi(summamatriisi, "Summamatriisi");
    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}