#include <stdio.h>

int main(void) {
    int luku;
    int tulos = 0;

    printf("Anna jokin luku väliltä 10 - 200: ");
    scanf("%d", &luku);

    if (10 <= luku && luku <= 200) {
        
        for(int i = 0; i <= luku; i++) {
            tulos = tulos + i;
        }
        printf("Lukujen 0 - %d summa on %d.\n", luku, tulos);
    }    
    else {
        printf("Antamasi luku ei ole annetulla välillä.\n");
    }
    
    
    return 0;
}