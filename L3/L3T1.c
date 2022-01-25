#include <stdio.h>

int potenssiin(int luku, int potenssi);

int main(void) {
    int luku;
    int potenssi;
    int vastaus;

    printf("Ohjelma laskee luvun potenssin.\n");
    printf("Anna kokonaisluku, jonka haluat korottaa potenssiin: ");
    scanf("%d", &luku);
    printf("Anna potenssi, jonka haluat laskea: ");
    scanf("%d", &potenssi);

    vastaus = potenssiin(luku, potenssi);

    printf("%d ^ %d = %d.\n", luku, potenssi, vastaus);
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

int potenssiin(int luku, int potenssi) {
    int i = 0;
    int tulos = 1;

    for (i = 0; i < potenssi; i++) {
        tulos = tulos * luku;
    }
    return tulos;
}