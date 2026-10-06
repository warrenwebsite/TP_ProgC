#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(struct liste_couleurs *liste) {
    if (liste != NULL) {
        liste->tete = NULL;
    }
}

void insertion(const struct couleur *c, struct liste_couleurs *liste) {
    if (liste == NULL || c == NULL) return;

    struct cellule *nouvelle = malloc(sizeof(struct cellule));
    if (nouvelle == NULL) {
        perror("Erreur allocation mémoire");
        return;
    }

    nouvelle->c = *c;
    nouvelle->suiv = liste->tete;
    liste->tete = nouvelle;
}

void parcours(const struct liste_couleurs *liste) {
    if (liste == NULL) return;

    struct cellule *courant = liste->tete;
    int index = 1;

    while (courant != NULL) {
        printf("Couleur %2d : R=0x%02X, G=0x%02X, B=0x%02X, A=0x%02X\n",
               index++,
               courant->c.R,
               courant->c.G,
               courant->c.B,
               courant->c.A);
        courant = courant->suiv;
    }
}

void liberer_liste(struct liste_couleurs *liste) {
    if (liste == NULL) return;

    struct cellule *courant = liste->tete;
    while (courant != NULL) {
        struct cellule *temp = courant;
        courant = courant->suiv;
        free(temp);
    }
    liste->tete = NULL;
}