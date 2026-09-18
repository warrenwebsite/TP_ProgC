#include <stdio.h>

int main(void) {
    char str1[100] = "Hello";
    char str2[] = " World!";
    char copie[100];

    // 1. Calcul de la longueur
    int longueur = 0;
    while (str1[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur de \"%s\" : %d\n", str1, longueur);

    // 2. Copie de str1 dans copie
    int i = 0;
    while (str1[i] != '\0') {
        copie[i] = str1[i];
        i++;
    }
    copie[i] = '\0';
    printf("Copie : %s\n", copie);

    // 3. Concaténation de str2 à la suite de str1
    int j = 0;
    while (str2[j] != '\0') {
        str1[longueur + j] = str2[j];
        j++;
    }
    str1[longueur + j] = '\0';
    printf("Concaténation : %s\n", str1);

    return 0;
}