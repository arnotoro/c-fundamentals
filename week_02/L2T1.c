#include <stdio.h>

int main(void) {
    int iLkm = 0; // Tehtävien lukumäärä
    int iArvosana = 0; // Arvosana

    printf("Anna palautettujen tehtävien lukumäärä: ");
    scanf("%d", &iLkm);

    if (iLkm > 0 && iLkm <= 14) {
        iArvosana = 0;
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on %d.\n", iLkm, iArvosana);
    } else if (iLkm > 15 && iLkm <= 17) {
        iArvosana = 1;
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on %d.\n", iLkm, iArvosana);
    } else if (iLkm > 18 && iLkm <= 20) {
        iArvosana = 2;
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on %d.\n", iLkm, iArvosana);
    } else if (iLkm > 21 && iLkm <= 23) {
        iArvosana = 3;
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on %d.\n", iLkm, iArvosana);
    } else if (iLkm > 24 && iLkm <= 26) {
        iArvosana = 4;
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on %d.\n", iLkm, iArvosana);
    } else if (iLkm > 27 && iLkm <= 30) {
        iArvosana = 5;
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on %d.\n", iLkm, iArvosana);
    } else {
        printf("Kurssilla on vain 30 tehtävää.\n");
    }

    return 0;
}