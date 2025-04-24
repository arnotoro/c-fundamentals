#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int readFile(char *fileName);
int writeFile(char *fileName, int sum);

int main(void){
    char fileName[MAX];
    int sum = 0;
    printf("Tämä ohjelma laskee tiedostossa olevien lukujen summan.\n");
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", fileName);

    sum = readFile(fileName);
    
    printf("Tiedosto '%s' luettu, lukujen summa oli %d.\n", fileName, sum);

    printf("\nAnna kirjoitettavan tiedoston nimi: ");
    scanf("%s", fileName);

    writeFile(fileName, sum);

    printf("\nKiitos ohjelman käytöstä.\n");

    return 0;
}

int readFile(char *fileName) {
    FILE* file;
    int sum = 0;
    char rivi[MAX];

    if ((file = fopen(fileName, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    while (fgets(rivi, MAX, file) != NULL) {
        sum += atoi(rivi);
    }

    fclose(file);
    return sum;
}

int writeFile(char *fileName, int sum) {
    FILE *file;

    if ((file = fopen(fileName, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui");
        exit(0);
    }

    fprintf(file, "Lukujen summa oli ");
    fprintf(file, "%d.\n", sum);

    printf("Tiedosto '%s' kirjoitettu.\n", fileName);

    fclose(file);
    return 0;
}