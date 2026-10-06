#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "repertoire.h"

void lire_dossier(const char *nom_repertoire) {
    DIR *dossier = opendir(nom_repertoire);
    if (dossier == NULL) {
        perror("Erreur lors de l'ouverture du dossier");
        return;
    }

    struct dirent *entree;
    printf("Contenu du répertoire '%s' :\n", nom_repertoire);
    while ((entree = readdir(dossier)) != NULL) {
        printf("- %s\n", entree->d_name);
    }

    closedir(dossier);
}

void lire_dossier_recursif(const char *nom_repertoire) {
    DIR *dossier = opendir(nom_repertoire);
    if (dossier == NULL) {
        perror("Erreur lors de l'ouverture du dossier");
        return;
    }

    struct dirent *entree;
    char chemin[1024];

    while ((entree = readdir(dossier)) != NULL) {
        // Ignorer . et .. pour éviter la récursion infinie
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) {
            continue;
        }

        snprintf(chemin, sizeof(chemin), "%s/%s", nom_repertoire, entree->d_name);
        printf("%s\n", chemin);

        struct stat st;
        if (stat(chemin, &st) == 0 && S_ISDIR(st.st_mode)) {
            lire_dossier_recursif(chemin);
        }
    }

    closedir(dossier);
}