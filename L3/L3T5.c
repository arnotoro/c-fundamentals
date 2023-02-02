#include <stdio.h>
#include <stdlib.h>
#define MAX 30


void setSeed();
int getAmount();
int generateCharacters(int amount);
int checkForChar();

int main(void) {
    int amount = 0;

    printf("Tämä ohjelma luo satunnaisia merkkijonoja.\n");

    setSeed();
    amount = getAmount();

    generateCharacters(amount);

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

void setSeed() {
    int seed = 0;

    printf("Anna satunnaisgeneraattorin siemenluku: ");
    scanf("%d", &seed);

    srand(seed);
}

int getAmount() {
    int amount = 0;

    printf("Anna arvottavien merkkien määrä: ");
    scanf("%d", &amount);

    return amount;
}

int generateCharacters(int amount) {
    int i = 0;
    int iArvo = 0;
    char characters[MAX];
    char cMerkki;

    for (i = 0; i < amount; i++) {
        iArvo = rand() % 95 + 32;
        cMerkki = iArvo;
        characters[i] = cMerkki;
    }

    printf("%s", characters);

    return 0;
}

