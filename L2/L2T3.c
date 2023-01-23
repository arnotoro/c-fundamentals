#include <stdio.h>
#define MAX 15

int main(void) {
    char cMerkki = {0};
    char cMerkkijono[MAX] = {0};
    int iArvo = 0;

    printf("Anna merkki: ");
    scanf("%c", &cMerkki);

    iArvo = cMerkki;
    printf("Merkki '%c' on ASCII-taulukon mukaan lukuna %d.\n", cMerkki, iArvo);

    printf("Anna merkkijono: ");
    scanf("%s", cMerkkijono);

    iArvo = 0;
    for (int i = 0; i < MAX; i++) {
        iArvo += cMerkkijono[i];
    }

    printf("Merkkijonon '%s' merkkien summa on %d.\n", cMerkkijono, iArvo);

    return 0;
}