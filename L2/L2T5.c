#include <stdio.h>

int main (void) {

    const int koko = 200;
    char taulukko[koko];
    int  pituus = 0;    
    int valinta;
    char merkki;
    char *ptr;
    int i;

    do {
        printf("\nValikko\n");
        printf("1) Lisää uusi merkki\n");
        printf("2) Tyhjennä merkkijono\n");
        printf("3) Tulosta merkkijono\n");
        printf("0) Lopeta\n");
        printf("Valintasi: ");
        scanf("%d", &valinta);
        getchar();
        printf("\n");

        switch (valinta) { 
            case 1:
                printf("Anna jokin merkki: ");
                scanf("%c", &merkki);;
                if (pituus < koko) {
                    taulukko[pituus] = merkki;
                    pituus++;
                }
                else {
                    printf("Merkkijonoon ei mahdu enempää merkkejä.\n");
                }
                break;
            case 2:
                if (pituus != 0) {
                    for(i = 0; i < pituus; i++) {
                        taulukko[i] = " ";
                    }
                    pituus = 0;
                    printf("Merkkijono on tyhjennetty.\n");
                }
                else {
                    printf("Merkkijono on tyhjä.\n");
                }

                break;
            case 3:
                if (pituus != 0) {

                    ptr = taulukko;
                    printf("Merkkijono: ");
                    for (i = 0; i < pituus; i++) {
                        printf("%c", *ptr);
                        ptr++;
                    }
                    printf("\n");
                } 
                else {
                    printf("Merkkijono on tyhjä.\n");
                }
                break;
            case 0:
                printf("Ohjelman lopetus.\n");
                break;
            default:
                printf("Tuntematon valinta.\n");
                break;
        }
    } while(valinta != 0);


    return 0;
}