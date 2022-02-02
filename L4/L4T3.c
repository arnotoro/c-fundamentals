#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc <= 1) {
        printf("Et antanut syötteitä.\n");
    } else {
        if (*argv[2] == '+') {
            printf("%s %c %s", argv[1], *argv[2], argv[3]);
            printf(" = %.2f\n", (atof(argv[1])+atof(argv[3])));
        } else if (*argv[2] == '-') {
            printf("%s %c %s", argv[1], *argv[2], argv[3]);
            printf(" = %.2f\n", (atof(argv[1])-atof(argv[3])));
        } else if (*argv[2] == 'x') {
            printf("%s %c %s", argv[1], *argv[2], argv[3]);
            printf(" = %.2f\n", (atof(argv[1])*atof(argv[3])));
        } else if (*argv[2] == '/') {
            printf("%s %c %s", argv[1], *argv[2], argv[3]);
            printf(" = %.2f\n", (atof(argv[1])/atof(argv[3])));
        } else {
            printf("Virheellinen syöte.\n");
        }
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}