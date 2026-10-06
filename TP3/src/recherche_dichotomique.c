#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main(void) {
    int tab[TAILLE];
    int valeur;

    srand((unsigned int)time(NULL));

    // Génération et tri du tableau
    for (int i = 0; i < TAILLE; i++) {
        tab[i] = rand() % 200 - 100;
    }

    for (int i = 0; i < TAILLE - 1; i++) {
        for (int j = 0; j < TAILLE - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }

    printf("Tableau trié :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n\n");

    printf("Entrez l'entier que vous souhaitez chercher : ");
    if (scanf("%d", &valeur) != 1) {
        printf("Erreur de saisie.\n");
        return 1;
    }

    // Recherche dichotomique
    int gauche = 0;
    int droite = TAILLE - 1;
    int trouve = 0;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        if (tab[milieu] == valeur) {
            trouve = 1;
            break;
        } else if (tab[milieu] < valeur) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

    if (trouve) {
        printf("Résultat : entier présent\n");
    } else {
        printf("Résultat : entier absent\n");
    }

    return 0;
}