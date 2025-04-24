#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 30


void setSeed();
int getAmount();
char *generateCharacters(char *characters, int amount);
void checkForChar(char *characters);

int main(void) {
    int amount = 0;
    int length = 0;
    int foundC = 0;
    char characters[MAX] = {0};
    char *ptr;

    printf("Tämä ohjelma luo satunnaisia merkkijonoja.\n");

    setSeed();
    amount = getAmount();

    ptr = generateCharacters(characters, amount);
    checkForChar(ptr);


    printf("Generoitiin merkkijono '%s', jossa on %d merkkiä.\n", ptr, strlen(ptr));
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

char *generateCharacters(char *characters, int amount) {
    int i = 0;
    int iArvo = 0;
    char cMerkki;

    for (i = 0; i < amount; i++) {
        iArvo = rand() % 95 + 32;
        cMerkki = iArvo;
        
        if ((isalpha(cMerkki) || isspace(cMerkki) || isdigit(cMerkki))) {
            characters[i] = cMerkki;
        } else {
            i--; amount--;
        }
    }

    return characters;
}

void checkForChar(char *characters) {
    int i = 0;
    int foundC = 0;

    while (characters[i] != '\0') {
        if (characters[i] == 'c') {
            foundC = 1;
        }
        i++;
    }

    if (foundC) {
        printf("\nMerkkijonosta löydettiin merkki 'c'.\n");
    } else {
        printf("\nMerkkijonossa ei ollut merkkiä 'c'.\n");
    }

    return;
}