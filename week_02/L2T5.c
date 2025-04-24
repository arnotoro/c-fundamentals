#include <stdio.h>

int main (void) {
    int iLuku = 0;
    int iValinta = 0;
    int iMuutos = 0;

    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);


    do {
        printf("\nValikko:\n");
        printf("1) Lisää lukuun\n");
        printf("2) Vähennä luvusta\n");
        printf("0) Lopeta\n");
        printf("Valintasi: ");

        scanf("%d", &iValinta);

        if (iValinta == 1) {
            printf("\nAnna lukuun lisättävä kokonaisluku: ");
            scanf("%d", &iMuutos);
            iLuku += iMuutos;
        } else if (iValinta == 2) {
            printf("\nAnna luvusta vähennettävä kokonaisluku: ");
            scanf("%d", &iMuutos);
            iLuku -= iMuutos;
        } else if (iValinta == 0) {
            printf("\nLopetetaan.\n");
            break;
        } else {
            printf("\nTuntematon valinta, yritä uudestaan.\n");
            continue;
        }
        printf("Luku on nyt %d.\n", iLuku);
        
    } while (iValinta != 0);

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}