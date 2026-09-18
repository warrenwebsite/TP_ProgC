#include <stdio.h>

int main(void) {
    char identites[5][2][50] = {
        {"Dupont", "Marie"},
        {"Martin", "Pierre"},
        {"Bernard", "Lucas"},
        {"Thomas", "Lea"},
        {"Petit", "Hugo"}
    };

    char adresses[5][100] = {
        "20, Boulevard Niels Bohr, Lyon",
        "22, Boulevard Niels Bohr, Lyon",
        "10, Rue de la Paix, Paris",
        "5, Avenue Jean Jaures, Villeurbanne",
        "12, Rue Garibaldi, Lyon"
    };

    float notes_prog[5] = {16.5f, 14.0f, 11.5f, 18.0f, 13.5f};
    float notes_sys[5]  = {12.1f, 14.1f, 15.0f, 17.5f, 10.0f};

    for (int i = 0; i < 5; i++) {
        printf("Étudiant.e %d :\n", i + 1);
        printf("Nom : %s\n", *(identites + i)[0]);
        printf("Prénom : %s\n", *(*(identites + i) + 1));
        printf("Adresse : %s\n", *(adresses + i));
        printf("Note Programmation C : %.1f\n", *(notes_prog + i));
        printf("Note Système d'exploitation : %.1f\n\n", *(notes_sys + i));
    }

    return 0;
}