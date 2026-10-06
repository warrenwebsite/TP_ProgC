#ifndef LISTE_H
#define LISTE_H

struct couleur {
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
};

struct cellule {
    struct couleur c;
    struct cellule *suiv;
};

struct liste_couleurs {
    struct cellule *tete;
};

void init_liste(struct liste_couleurs *liste);
void insertion(const struct couleur *c, struct liste_couleurs *liste);
void parcours(const struct liste_couleurs *liste);
void liberer_liste(struct liste_couleurs *liste);

#endif