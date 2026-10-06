#include <stdio.h>
#include "fichier.h"

void lire_fichier(const char *nom_de_fichier) {
    FILE *f = fopen(nom_de_fichier, "r");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier en lecture");
        return;
    }

    printf("Contenu du fichier %s :\n", nom_de_fichier);
    char ligne[256];
    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        printf("%s", ligne);
    }
    printf("\n");
    fclose(f);
}

void ecrire_dans_fichier(const char *nom_de_fichier, const char *message) {
    FILE *f = fopen(nom_de_fichier, "a");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier en écriture");
        return;
    }

    fprintf(f, "%s\n", message);
    fclose(f);
    printf("Le message a été écrit dans le fichier %s.\n", nom_de_fichier);
}