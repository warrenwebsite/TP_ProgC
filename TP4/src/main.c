#include <stdio.h>
#include "operator.h"

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

int main(void) {
    int choix;
    printf("Choisissez l'exercice à exécuter :\n");
    printf("1. Exercice 4.1 (Calcul avec opérateurs)\n");
    printf("Votre choix : ");
    if (scanf("%d", &choix) != 1) return 1;

    switch (choix) {
        case 1:
            exercice_4_1();
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }

    return 0;
}