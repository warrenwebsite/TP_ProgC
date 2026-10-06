#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main(void) {
    int tab[TAILLE];
    int valeur, trouve = 0;

    srand((unsigned int)time(NULL));

    printf("Tableau :\n");
    for (int i = 0; i < TAILLE; i++) {
        tab[i] = rand() % 200 - 100;
        printf("%d ", tab[i]);
    }
    printf("\n\n");

    printf("Entrez l'entier que vous souhaitez chercher : ");
    if (scanf("%d", &valeur) != 1) {
        printf("Erreur de saisie.\n");
        return 1;
    }

    for (int i = 0; i < TAILLE; i++) {
        if (tab[i] == valeur) {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("Résultat : entier présent\n");
    } else {
        printf("Résultat : entier absent\n");
    }

    return 0;
}