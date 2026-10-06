#include <stdio.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

void exercice_4_1(void) {
    int num1, num2;
    char op;

    printf("Entrez num1 : ");
    if (scanf("%d", &num1) != 1) return;

    printf("Entrez num2 : ");
    if (scanf("%d", &num2) != 1) return;

    printf("Entrez l'opérateur (+, -, *, /, %%, &, |, ~) : ");
    if (scanf(" %c", &op) != 1) return;

    int res = 0;
    switch (op) {
        case '+': res = somme(num1, num2); break;
        case '-': res = difference(num1, num2); break;
        case '*': res = produit(num1, num2); break;
        case '/': res = quotient(num1, num2); break;
        case '%': res = modulo(num1, num2); break;
        case '&': res = et_logique(num1, num2); break;
        case '|': res = ou_logique(num1, num2); break;
        case '~': res = negation(num1, num2); break;
        default:
            printf("Opérateur inconnu.\n");
            return;
    }
    printf("Résultat : %d\n", res);
}

void exercice_4_2(void) {
    int choix;
    char nom_fichier[100];
    char message[256];

    printf("Que souhaitez-vous faire ?\n");
    printf("1. Lire un fichier\n");
    printf("2. Écrire dans un fichier\n");
    printf("Votre choix : ");
    if (scanf("%d", &choix) != 1) return;
    while (getchar() != '\n');

    if (choix == 1) {
        printf("Entrez le nom du fichier à lire : ");
        if (fgets(nom_fichier, sizeof(nom_fichier), stdin) != NULL) {
            nom_fichier[strcspn(nom_fichier, "\n")] = '\0';
            lire_fichier(nom_fichier);
        }
    } else if (choix == 2) {
        printf("Entrez le nom du fichier dans lequel vous souhaitez écrire : ");
        if (fgets(nom_fichier, sizeof(nom_fichier), stdin) != NULL) {
            nom_fichier[strcspn(nom_fichier, "\n")] = '\0';
            printf("Entrez le message à écrire : ");
            if (fgets(message, sizeof(message), stdin) != NULL) {
                message[strcspn(message, "\n")] = '\0';
                ecrire_dans_fichier(nom_fichier, message);
            }
        }
    } else {
        printf("Choix invalide.\n");
    }
}

void exercice_4_7(void) {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);

    struct couleur couleurs[10] = {
        {0xFF, 0x00, 0x00, 0xFF},
        {0x00, 0xFF, 0x00, 0xFF},
        {0x00, 0x00, 0xFF, 0xFF},
        {0xFF, 0xFF, 0x00, 0xFF},
        {0x00, 0xFF, 0xFF, 0xFF},
        {0xFF, 0x00, 0xFF, 0xFF},
        {0x80, 0x00, 0x00, 0xFF},
        {0x00, 0x80, 0x00, 0xFF},
        {0x00, 0x00, 0x80, 0xFF},
        {0x80, 0x80, 0x80, 0xFF}
    };

    for (int i = 0; i < 10; i++) {
        insertion(&couleurs[i], &ma_liste);
    }

    printf("Liste des couleurs :\n");
    parcours(&ma_liste);
    liberer_liste(&ma_liste);
}

int main(void) {
    int choix;
    printf("Choisissez l'exercice à exécuter :\n");
    printf("1. Exercice 4.1 (Calcul avec opérateurs)\n");
    printf("2. Exercice 4.2 (Gestion de fichiers)\n");
    printf("3. Exercice 4.7 (Gestion d'une liste de couleurs)\n");
    printf("Votre choix : ");
    if (scanf("%d", &choix) != 1) return 1;

    switch (choix) {
        case 1:
            exercice_4_1();
            break;
        case 2:
            exercice_4_2();
            break;
        case 3:
            exercice_4_7();
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }

    return 0;
}