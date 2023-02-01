#include <stdio.h>

float rectangleArea(float basis, float height);

int main(void) {
    float basis = 0;
    float height = 0;
    float area = 0;

    printf("Tämä ohjelma laskee suorakulmion pinta-alan.\n");
    printf("Anna suorakulmion kanta: ");
    scanf("%f", &basis);
    printf("Anna suorakulmion korkeus: ");
    scanf("%f", &height);

    area = rectangleArea(basis, height);
    printf("Suorakulmion pinta-ala on %.2f.\n", area);
    printf("Kiitos ohjelman käytöstä.\n");

}
float rectangleArea(float basis, float height) {
    return basis * height;
}