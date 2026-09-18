#include <stdio.h>
#include <string.h>

struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float note_prog;
    float note_sys;
};

int main(void) {
    struct Etudiant etudiants[5];

    strcpy(etudiants[0].nom, "Dupont");
    strcpy(etudiants[0].prenom, "Marie");
    strcpy(etudiants[0].adresse, "20, Boulevard Niels Bohr, Lyon");
    etudiants[0].note_prog = 16.5f;
    etudiants[0].note_sys = 12.1f;

    strcpy(etudiants[1].nom, "Martin");
    strcpy(etudiants[1].prenom, "Pierre");
    strcpy(etudiants[1].adresse, "22, Boulevard Niels Bohr, Lyon");
    etudiants[1].note_prog = 14.0f;
    etudiants[1].note_sys = 14.1f;

    strcpy(etudiants[2].nom, "Bernard");
    strcpy(etudiants[2].prenom, "Lucas");
    strcpy(etudiants[2].adresse, "10, Rue de la Paix, Paris");
    etudiants[2].note_prog = 11.5f;
    etudiants[2].note_sys = 15.0f;

    strcpy(etudiants[3].nom, "Thomas");
    strcpy(etudiants[3].prenom, "Lea");
    strcpy(etudiants[3].adresse, "5, Avenue Jean Jaures, Villeurbanne");
    etudiants[3].note_prog = 18.0f;
    etudiants[3].note_sys = 17.5f;

    strcpy(etudiants[4].nom, "Petit");
    strcpy(etudiants[4].prenom, "Hugo");
    strcpy(etudiants[4].adresse, "12, Rue Garibaldi, Lyon");
    etudiants[4].note_prog = 13.5f;
    etudiants[4].note_sys = 10.0f;

    for (int i = 0; i < 5; i++) {
        printf("Étudiant.e %d :\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prénom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Note 1 : %.1f\n", etudiants[i].note_prog);
        printf("Note 2 : %.1f\n\n", etudiants[i].note_sys);
    }

    return 0;
}