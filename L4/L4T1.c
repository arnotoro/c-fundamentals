#include <stdio.h>
#include <string.h>
#define MAX 52


struct Kirja {
    char nimi[MAX];
    int painovuosi;
    int hyllypaikka;
};


int main(void){
    struct Kirja kirja1;
    int i = 0;

    printf("Anna kirjan nimi: ");
    fgets(kirja1.nimi, MAX, stdin);
    kirja1.nimi[strlen(kirja1.nimi) - 1] = '\0';

    printf("Anna kirjan painovuosi: ");
    scanf("%d", &kirja1.painovuosi);
    printf("Anna kirjan hyllypaikka: ");
    scanf("%d", &kirja1.hyllypaikka);

    printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n", 
    kirja1.nimi, kirja1.painovuosi, kirja1.hyllypaikka);
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}