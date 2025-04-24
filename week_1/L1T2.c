#include <stdio.h>

int main(void){

    int iLuku = 0;
    float fLuku = 0;

    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);
    printf("Anna liukuluku: ");
    scanf("%f", &fLuku);

    printf("Annoit luvut %d ja %.2f.\n", iLuku, fLuku);

    return 0;
}