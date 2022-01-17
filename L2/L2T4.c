#include <stdio.h>

int main(void) {
    int valinta;
    float Lluku;
    float pi = 3.141;

    printf("Anna liukuluku: ");
    scanf("%f", &Lluku);

    printf("\nValikko\n");
    printf("1) Kerro piin arvo luvulla %.3f.\n", Lluku);
    printf("2) Jaa piin arvo luvulla %.3f.\n", Lluku);
    printf("Valitse: ");
    scanf("%d", &valinta);
    printf("\n");

    switch (valinta)
    {
    case 1:
        printf("Pii * %.3f = %.3f.\n", Lluku, pi * Lluku);
        break;
    case 2:
        printf("Pii / %.3f = %.3f.\n", Lluku, pi / Lluku);
        break;
    default:
        printf("Tuntematon valinta.\n");
        break;
    }

    return 0;
}