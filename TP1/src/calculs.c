#include <stdio.h>

int main() {
    int num1 = 16;
    int num2 = 3;
    char op = '+';

    switch (op) {
        case '+':
            printf("Résultat : %d\n", num1 + num2);
            break;

        case '-':
            printf("Résultat : %d\n", num1 - num2);
            break;

        case '*':
            printf("Résultat : %d\n", num1 * num2);
            break;

        case '/':
            if (num2 != 0) {
                printf("Résultat : %d\n", num1 / num2);
            } else {
                printf("Erreur : division par zéro\n");
            }
            break;

        case '%':
            if (num2 != 0) {
                printf("Résultat : %d\n", num1 % num2);
            } else {
                printf("Erreur : modulo par zéro\n");
            }
            break;

        case '&':
            printf("Résultat : %d\n", num1 & num2);
            break;

        case '|':
            printf("Résultat : %d\n", num1 | num2);
            break;

        case '~':
            printf("Résultat : %d\n", ~num1);
            break;

        default:
            printf("Opérateur invalide\n");
            break;
    }

    return 0;
}