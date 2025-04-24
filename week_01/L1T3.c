#include <stdio.h>

int main(void) {

    int luku1 = 0;
    int luku2 = 0;

    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d", &luku1);
    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &luku2);


    int tulo = ++luku1 * luku2; 
    printf("%d * %d = %d\n", luku1, luku2, tulo); luku1--;

    int osmErotus = (luku1 / luku2) - 10;
    printf("(%d / %d) - 10 = %d\n", luku1, luku2, osmErotus);

    int jakoJaannos = luku1 % (--luku2);
    printf("%d %% %d = %d\n", luku1, luku2, jakoJaannos);

    return 0;
}