#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compter_occurrences(const char *ligne, const char *motif) {
    int compte = 0;
    size_t len_motif = strlen(motif);
    if (len_motif == 0) return 0;

    const char *p = ligne;
    while ((p = strstr(p, motif)) != NULL) {
        compte++;
        p += len_motif;
    }
    return compte;
}

int main(int argc, char *argv[]) {
    char nom_fichier[256];
    char phrase[256];

    if (argc >= 2) {
        strncpy(nom_fichier, argv[1], sizeof(nom_fichier) - 1);
        nom_fichier[sizeof(nom_fichier) - 1] = '\0';
    } else {
        printf("Entrez le nom du fichier : ");
        if (fgets(nom_fichier, sizeof(nom_fichier), stdin) == NULL) return 1;
        nom_fichier[strcspn(nom_fichier, "\n")] = '\0';
    }

    printf("Entrez la phrase que vous souhaitez rechercher : ");
    if (fgets(phrase, sizeof(phrase), stdin) == NULL) return 1;
    phrase[strcspn(phrase, "\n")] = '\0';

    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    printf("\nRésultats de la recherche :\n");
    char ligne[1024];
    int num_ligne = 0;
    int trouve = 0;

    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        num_ligne++;
        int occ = compter_occurrences(ligne, phrase);
        if (occ > 0) {
            printf("Ligne %d, %d fois\n", num_ligne, occ);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune occurrence trouvée.\n");
    }

    fclose(f);
    return 0;
}