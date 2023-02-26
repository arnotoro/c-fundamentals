#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
    char data;
    struct linkedlist *pSeuraava;
} LL;


int main(void) {
    LL *pAlku = NULL, *pLoppu = NULL;
    LL *pUusi, *ptr;
    char kirjain;

    printf("Anna listan kirjaimet.\n");
    
    while (1) {
        printf("Anna kirjain, q lopettaa: ");
        scanf("%c", &kirjain);
        getchar();

        if (kirjain == 'q') {
            break;
        }
        // Varataan muisti
        if ((pUusi = (LL*)malloc(sizeof(LL))) == NULL) {
            perror("Muistinvaraus epäonnistui");
            exit(0);
        }

        // Alustetaan uusi alkio
        pUusi->data = kirjain;
        pUusi->pSeuraava = NULL;

        // Lisätään alkio listalle
        if (pAlku == NULL) {
            pAlku = pUusi;
            pLoppu = pUusi;
        } else {
            pLoppu->pSeuraava = pUusi;
            pLoppu = pUusi;
        }   
    }

    // Tulostetaan lista
    printf("Listassa on seuraavat kirjaimet:\n");
    ptr = pAlku;
    while (ptr != NULL) {
        printf("%c ", ptr->data);
        ptr = ptr->pSeuraava;
    }
    printf("\n");
    // Vapautetaan muisti
    ptr = pAlku;
    while (ptr != NULL) {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }

    printf("\nMuisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}
