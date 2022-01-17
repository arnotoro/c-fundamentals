#include <stdio.h>

int main(void) {

    int luku1;
    int luku2;
    int valinta;

    printf("Anna kaksi kokonaislukua: ");
    scanf("%d %d", &luku1, &luku2);
    printf("\n");

    printf("Valikko\n");
    printf("1) Summaa luvut yhteen.\n");
    printf("2) Kerro luvut keskenään.\n");
    printf("Valitse: ");
    scanf("%d", &valinta);
    printf("\n");

    if (valinta == 1) {
        printf("Luvut laskettiin yhteen. Tulos = %d.\n", luku1+luku2);
    }
    else if (valinta == 2) {
        printf("Luvut kerrottiin keskenään. Tulos = %d\n", luku1*luku2);
    }
    else {
       printf("Tuntematon valinta.\n"); 
    };

    return 0;
}