#include <stdio.h>
#define PI 3.141

int main(void) {
    float fSade = 0;
    int iValinta = 0;

    printf("Anna ympyrän säde: ");
    scanf("%f", &fSade);

    printf("\nValikko:\n");
    printf("1) Laske ympyrän kehän pituus\n");
    printf("2) Laske ympyrän pinta-ala\n");
    printf("Valitse: ");
    scanf("%d", &iValinta);

    switch(iValinta) {
        case 1:
            printf("Ympyrän säde on %.3f ja sen kehän pituus %.3f.", fSade, 2 * PI * fSade);
            break;
        case 2:
            printf("Ympyrän säde on %.3f ja sen pinta-ala on %.3f.", fSade, PI * fSade * fSade);
            break;
        default:
            printf("Tuntematon valinta.\n");
    }
    return 0;
}