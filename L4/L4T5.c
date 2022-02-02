#include <stdio.h>


long fibo(long luku);

long fibo(long luku) {
    if (luku == 0) {
        return 0;
    } else if (luku == 1) {
        return 1;
    } else {
        return fibo(luku-1) + fibo(luku-2);
    }
}

int main(void) {
    long fibluku;

    printf("Anna luku, jolle lasketaan Fibonaccin luku: ");
    scanf("%ld", &fibluku);
    printf("Luvun %ld Fibonaccin luku on %ld.\n", fibluku, fibo(fibluku));
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}