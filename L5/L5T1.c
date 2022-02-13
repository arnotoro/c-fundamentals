#include <stdio.h>
#include <stdlib.h>

void potenssi(int *luku);

void potenssi(int *luku) {
    *luku = *luku**luku;
}


int main(int argc, char *argv[]) {
    int luku, *ptr;
    if (argc <= 1) {
        printf("Et antanut lukua!\n");
    } else {

    luku = atoi(argv[1]);
    ptr = &luku;

    printf("Luku on %d.\n", luku);
    potenssi(ptr);
    printf("Luvun neliö on %d.\n", *ptr);
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}