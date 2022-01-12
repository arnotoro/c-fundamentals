#include <stdio.h>

int main(void){

    int Kluku = 0;
    float Lluku = 0;

    printf("Anna kokonaisluku: ");
    scanf("%d", &Kluku);
    printf("Anna liukuluku: ");
    scanf("%f", &Lluku);

    printf("Annoit luvut %d ja %.2f.\n", Kluku, Lluku);

    return 0;
}