#include <stdio.h>
#define MAX_SIZE 52
#define MAX_COUNT 50

int tulostaValikko(int valinta);

int tulostaValikko(int valinta) {
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lisää uusi tunnus\n");
    printf("2) Tulosta tunnukset\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &valinta);
    printf("\n");
    return valinta;
}

typedef struct kayttajatunnus {
    char username[MAX_SIZE];
    char password[MAX_SIZE];
    int ID;
} tunnukset;

int main(void) {
    int valinta, i;
    int laskuri = 0;
    tunnukset tunnus[MAX_COUNT];

    printf("Käyttäjätunnusten hallinta.\n");

    while(1) {
        valinta = tulostaValikko(valinta);

        if (valinta == 1) {
            printf("Anna käyttäjätunnus: ");
            scanf("%s", tunnus[laskuri].username);
            printf("Anna salasana: ");
            scanf("%s", tunnus[laskuri].password);

            printf("Tunnus '%s' lisättiin listaan.\n\n", tunnus[laskuri].username);
            tunnus[laskuri].ID = laskuri;
            ++laskuri;
            continue;
        } else if (valinta == 2) {
            printf("Listalla olevat tunnukset:\n");

            for(i = 0; i<laskuri; i++) {
                printf("%d. tunnus '%s', salasana '%s', ID '%d'.\n", 
                i+1, tunnus[i].username, tunnus[i].password, tunnus[i].ID);
            }
            printf("\n");
        } else if (valinta == 0) {
            break;
        } else {
            printf("Tuntematon valinta.\n");
            continue;
        }
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}