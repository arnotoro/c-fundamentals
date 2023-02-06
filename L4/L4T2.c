#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int main(int args, char *argv[]) {
    FILE *file;
    char rivi[MAX];

    if (args > 3) {
        printf("Annoit liikaa parametreja.\n");
        exit(0);
    } else if (args <= 2) {
        printf("Et antanut tarpeeksi parametreja.\n");
        exit(0);
    } else {
        int rows = atoi(argv[2]);
        int i = 0;

        if ((file = fopen(argv[1], "r")) == NULL) {
            perror("Tiedoston avaaminen epäonnistui, lopetetaan");
            exit(0);
        }


        while (i < rows) {
            if (fgets(rivi, MAX, file) == NULL) {
                printf("\nTiedostossa ei ole enempää rivejä luettavaksi.");
                break;
            }
            printf("%s", rivi, i);
            i++;
        }

        printf("\nTiedostosta '%s' luettu %d riviä.\n", argv[1], i);
        fclose(file);
    }

    


    return 0;
}