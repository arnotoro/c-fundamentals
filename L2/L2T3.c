#include <stdio.h>

int main(void) {
    unsigned int luku;
    unsigned int i = 1;

    printf("Anna jokin kokonaisluku väliltä 1-10: ");
    scanf("%d", &luku);

    if (1 <= luku && luku <= 10) {
        while (i <= luku) {
            printf("%d kierros.\n", i);
            i++;
        }
    }
    else {
        printf("Antamasi luku ei ole välillä 1-10.\n");
    }
    return 0;
}