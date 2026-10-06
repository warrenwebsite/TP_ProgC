#include <stdio.h>
#include <string.h>
#include "fichier.h"

#define NB_ETUDIANTS 5

struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float note1;
    float note2;
};

int main(void) {
    struct Etudiant etudiants[NB_ETUDIANTS];
    char ligne[300];
    const char *nom_fichier = "etudiant.txt";

    // Écrase le fichier existant s'il existe déjà
    FILE *f_init = fopen(nom_fichier, "w");
    if (f_init != NULL) {
        fclose(f_init);
    }

    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Entrez les détails de l'étudiant.e %d :\n", i + 1);

        printf("Nom : ");
        if (fgets(etudiants[i].nom, sizeof(etudiants[i].nom), stdin) == NULL) return 1;
        etudiants[i].nom[strcspn(etudiants[i].nom, "\n")] = '\0';

        printf("Prénom : ");
        if (fgets(etudiants[i].prenom, sizeof(etudiants[i].prenom), stdin) == NULL) return 1;
        etudiants[i].prenom[strcspn(etudiants[i].prenom, "\n")] = '\0';

        printf("Adresse : ");
        if (fgets(etudiants[i].adresse, sizeof(etudiants[i].adresse), stdin) == NULL) return 1;
        etudiants[i].adresse[strcspn(etudiants[i].adresse, "\n")] = '\0';

        printf("Note 1 : ");
        if (scanf("%f", &etudiants[i].note1) != 1) return 1;

        printf("Note 2 : ");
        if (scanf("%f", &etudiants[i].note2) != 1) return 1;
        while (getchar() != '\n'); // Vider le buffer

        printf("\n");

        snprintf(ligne, sizeof(ligne), "%s;%s;%s;%.2f;%.2f",
                 etudiants[i].nom,
                 etudiants[i].prenom,
                 etudiants[i].adresse,
                 etudiants[i].note1,
                 etudiants[i].note2);

        ecrire_dans_fichier(nom_fichier, ligne);
    }

    printf("Les détails des étudiants ont été enregistrés dans le fichier %s.\n", nom_fichier);
    return 0;
}