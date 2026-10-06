#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "repertoire.h"

#define MAX_CHEMIN 1024
#define CAPACITE_FILE 2048

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
    char chemin[MAX_CHEMIN];

    while ((entree = readdir(dossier)) != NULL) {
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

void lire_dossier_iteratif(const char *nom_repertoire) {
    char file_dirs[CAPACITE_FILE][MAX_CHEMIN];
    int debut = 0;
    int fin = 0;

    strncpy(file_dirs[fin++], nom_repertoire, MAX_CHEMIN - 1);

    while (debut < fin) {
        char rep_courant[MAX_CHEMIN];
        strncpy(rep_courant, file_dirs[debut++], MAX_CHEMIN - 1);

        DIR *dossier = opendir(rep_courant);
        if (dossier == NULL) {
            continue;
        }

        struct dirent *entree;
        while ((entree = readdir(dossier)) != NULL) {
            if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) {
                continue;
            }

            char chemin[MAX_CHEMIN];
            snprintf(chemin, sizeof(chemin), "%s/%s", rep_courant, entree->d_name);
            printf("%s\n", chemin);

            struct stat st;
            if (stat(chemin, &st) == 0 && S_ISDIR(st.st_mode)) {
                if (fin < CAPACITE_FILE) {
                    strncpy(file_dirs[fin++], chemin, MAX_CHEMIN - 1);
                }
            }
        }

        closedir(dossier);
    }
}