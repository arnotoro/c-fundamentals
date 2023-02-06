#include <stdio.h>
#include <string.h>
#define MAX 50


struct Kappale {
    char nimi[MAX];
    char esittaja[MAX];
    char pituus[MAX];
    int julkaisuVuosi;
};


int main(void){
    struct Kappale kappale1;
    int i = 0;

    printf("Anna kappaleen nimi: ");
    fgets(kappale1.nimi, MAX, stdin);
    kappale1.nimi[strlen(kappale1.nimi) - 1] = '\0';

    printf("Anna kappaleen esittäjä: ");
    fgets(kappale1.esittaja, MAX, stdin);
    kappale1.esittaja[strlen(kappale1.esittaja) - 1] = '\0';

    printf("Anna kappaleen pituus: ");
    fgets(kappale1.pituus, MAX, stdin);
    kappale1.pituus[strlen(kappale1.pituus) - 1] = '\0';

    printf("Anna kappaleen julkaisuvuosi: ");
    scanf("%d", &kappale1.julkaisuVuosi);

    printf("Kappaleen nimi on '%s' ja esittäjä '%s'.\n", kappale1.nimi, kappale1.esittaja);
    printf("Kappale on %s minuuttia pitkä ja julkaistu vuonna %d.\n", kappale1.pituus, kappale1.julkaisuVuosi);
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}