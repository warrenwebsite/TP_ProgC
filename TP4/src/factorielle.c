#include <stdio.h>

int factorielle(int num) {
    if (num <= 0) {
        printf("fact(0): 1\n");
        return 1;
    } else {
        int valeur = num * factorielle(num - 1);
        printf("fact(%d): %d\n", num, valeur);
        return valeur;
    }
}

int main(void) {
    int valeurs_test[] = {0, 3, 5, 7};
    int taille = sizeof(valeurs_test) / sizeof(valeurs_test[0]);

    for (int i = 0; i < taille; i++) {
        int n = valeurs_test[i];
        printf("--- Calcul pour n = %d ---\n", n);
        int res = factorielle(n);
        printf("Résultat final : %d! = %d\n\n", n, res);
    }

    return 0;
}