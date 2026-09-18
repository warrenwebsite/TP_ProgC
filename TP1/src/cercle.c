#include <stdio.h>

int main(void) {
    double pi = 3.1416;
    double r = 8.0;

    double aire = pi * r * r;
    double perimetre = 2 * pi * r;

    printf("L'aire du cercle = %f\n", aire);
    printf("Le périmètre du cercle = %f\n", perimetre);

    return 0;
}