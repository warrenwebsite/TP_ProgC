#include <stdio.h>

#define NB_PHRASES 10

// Comparaison manuelle de deux chaînes sans bibliothèque externe
int chaines_egales(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0;
        }
        i++;
    }
    return (s1[i] == '\0' && s2[i] == '\0');
}

void rechercher_phrase(const char *tableau[], int taille, const char *cible) {
    for (int i = 0; i < taille; i++) {
        if (chaines_egales(tableau[i], cible)) {
            printf("Recherche de \"%s\" -> Phrase trouvée\n", cible);
            return;
        }
    }
    printf("Recherche de \"%s\" -> Phrase non trouvée\n", cible);
}

int main(void) {
    const char *phrases[NB_PHRASES] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };

    // Tests demandés dans le sujet
    rechercher_phrase(phrases, NB_PHRASES, "La programmation en C est amusante.");
    rechercher_phrase(phrases, NB_PHRASES, "Je préfère le Python.");

    return 0;
}