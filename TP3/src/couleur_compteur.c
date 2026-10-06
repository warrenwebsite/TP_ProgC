#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

typedef struct {
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
} Couleur;

typedef struct {
    Couleur c;
    int occurrences;
} CouleurCompte;

int memes_couleurs(Couleur c1, Couleur c2) {
    return (c1.R == c2.R && c1.G == c2.G && c1.B == c2.B && c1.A == c2.A);
}

int main(void) {
    Couleur couleurs[TAILLE];
    CouleurCompte distinctes[TAILLE];
    int nb_distinctes = 0;

    srand((unsigned int)time(NULL));

    // Génération de couleurs avec un modulo réduit pour forcer des doublons
    for (int i = 0; i < TAILLE; i++) {
        couleurs[i].R = rand() % 5;
        couleurs[i].G = rand() % 5;
        couleurs[i].B = rand() % 5;
        couleurs[i].A = 0xFF;
    }

    // Comptage des couleurs distinctes
    for (int i = 0; i < TAILLE; i++) {
        int trouve = 0;
        for (int j = 0; j < nb_distinctes; j++) {
            if (memes_couleurs(couleurs[i], distinctes[j].c)) {
                distinctes[j].occurrences++;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            distinctes[nb_distinctes].c = couleurs[i];
            distinctes[nb_distinctes].occurrences = 1;
            nb_distinctes++;
        }
    }

    // Affichage
    for (int i = 0; i < nb_distinctes; i++) {
        printf("%02x 0x%02x 0x%02x 0x%02x : %d\n",
               distinctes[i].c.R,
               distinctes[i].c.G,
               distinctes[i].c.B,
               distinctes[i].c.A,
               distinctes[i].occurrences);
    }

    return 0;
}