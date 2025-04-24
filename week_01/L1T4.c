#include <stdio.h>
#include <string.h>

int main(void) {
    char merkki;
    char merkkijono[21];

    printf("Anna merkki: ");
    scanf("%c", &merkki);
    getchar();
    printf("Annoit merkin '%c'.\n", merkki);

    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    scanf("%s", merkkijono);

    printf("Annoit merkkijonon '%s'.\n", merkkijono);

    return 0;
}