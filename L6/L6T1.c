#include <stdio.h>

typedef struct luvut
{
    int numero;
    struct luvut *pNext;
} LUKUJA;

int main(void)
{
    LUKUJA *pStart = NULL, *pEnd = NULL;
    LUKUJA *pNew, *ptr;
    int luku, i;

    printf("Anna listan luvut.\n");
    while (1)
    {
        if ((pNew = (LUKUJA *)malloc(sizeof(LUKUJA))) == NULL)
        {
            perror("Muistin varaus epäonnistui.\n");
            exit(1);
        }
        printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
        scanf("%d", &luku);
        if (luku == 0)
        {
            break;
        }
        pNew->numero = luku;
        pNew->pNext = NULL;

        if (pStart == NULL)
        {
            pStart = pNew;
            pEnd = pNew;
        }
        else
        {
            pEnd->pNext = pNew;
            pEnd = pNew;
        }
    }

    // Listan läpikäynti
    printf("Listassa on seuraavat luvut: ");
    ptr = pStart;
    while (ptr != NULL)
    {
        printf("%d ", ptr->numero);
        ptr = ptr->pNext;
    }

    // Muistin vapauttaminen
    ptr = pStart;
    while (ptr != NULL)
    {
        pStart = ptr->pNext;
        free(ptr);
        ptr = pStart;
    }
    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}