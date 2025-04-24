#include <stdio.h>
#include <string.h>

void tulostaMerkkijono(char *merkkijono, int pituus);
void tulostaMerkkijonoTakaperin(char *merkkijono, int pituus, int askel);

int main(int argc, char *argv[]) {
    int valinta = 1;

    if (argc >= 3) {
        printf("Annoit liikaa parametreja.\n");
        return 0;
    } else if (argc <= 1) {
        printf("Et antanut tarpeeksi parametreja.\n");
        return 0;
    } else {
        char *merkkijono = argv[1];
        int pituus = strlen(merkkijono) - 1;
        int askel = 0;
        do {
            printf("Valitse haluamasi toiminto:\n");
            printf("1) Tulosta merkkijono\n");
            printf("2) Tulosta merkkijono takaperin\n");
            printf("0) Lopeta\n");
            printf("Anna valintasi: ");
            scanf("%d", &valinta);
            getchar();

            switch (valinta) {
                case 1:
                    tulostaMerkkijono(merkkijono, askel);
                    break;
                case 2:
                    tulostaMerkkijonoTakaperin(merkkijono, pituus, askel);
                    break;
                case 0:
                    printf("Lopetetaan.\n");
                    break;
                default:
                    printf("Virheellinen valinta.\n");
                    break;
            }
        } while (valinta != 0);
    }

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}


void tulostaMerkkijono(char *merkkijono, int askel) {
    if (merkkijono[askel] == '\0') {
        printf("\n");
        return;
    } else {
        printf("%c\n", merkkijono[askel]);
        tulostaMerkkijono(merkkijono, askel + 1);
    }
}

void tulostaMerkkijonoTakaperin(char *merkkijono, int pituus, int askel) {
    if (merkkijono[askel] == '\0') {
        printf("\n");
        return;
    } else {
        printf("%c\n", merkkijono[pituus - askel]);
        tulostaMerkkijonoTakaperin(merkkijono, pituus, askel + 1);
    }
}