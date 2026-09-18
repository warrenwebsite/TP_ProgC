#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 11

int main(void) {
    int tab_int[TAILLE];
    float tab_float[TAILLE];

    srand((unsigned int)time(NULL));

    // Remplissage avec des valeurs aléatoires
    for (int i = 0; i < TAILLE; i++) {
        *(tab_int + i) = rand() % 100 + 1;
        *(tab_float + i) = (float)(rand() % 1000) / 100.0f;
    }

    // Affichage avant multiplication
    printf("Tableau d'entiers (avant la multiplication par 3) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d%s", *(tab_int + i), (i == TAILLE - 1) ? "" : ", ");
    }
    printf("\n\n");

    printf("Tableau de nombres à virgule flottante (avant la multiplication par 3) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%.2f%s", *(tab_float + i), (i == TAILLE - 1) ? "" : ", ");
    }
    printf("\n\n");

    // Multiplication par 3 pour les indices pairs à l'aide de pointeurs
    for (int i = 0; i < TAILLE; i++) {
        if (i % 2 == 0) {
            *(tab_int + i) *= 3;
            *(tab_float + i) *= 3.0f;
        }
    }

    // Affichage après multiplication
    printf("Tableau d'entiers (après la multiplication par 3) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d%s", *(tab_int + i), (i == TAILLE - 1) ? "" : ", ");
    }
    printf("\n\n");

    printf("Tableau de nombres à virgule flottante (après la multiplication par 3) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%.2f%s", *(tab_float + i), (i == TAILLE - 1) ? "" : ", ");
    }
    printf("\n");

    return 0;
}