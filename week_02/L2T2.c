#include <stdio.h>
#define MIN 3
#define MAX 10

int main(void) {
    int iLuku = 0;

    printf("Anna kokonaisluku väliltä %d - %d: ", MIN, MAX);
    scanf("%d", &iLuku);

    printf("\n");
    
    if (iLuku < MIN || iLuku > MAX) {
        printf("Antamasi luku ei ole määritellyllä välillä.\n");
        return 0;
    } else {
        for (int i = 0; i < iLuku; i++) {
            for (int j = 0; j < iLuku; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}