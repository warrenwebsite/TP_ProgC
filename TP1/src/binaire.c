#include <stdio.h>

int main() {
    int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = 5;

    for (int i = 0; i < taille; i++) {
        int nombre = nombres[i];

        printf("%d en binaire : ", nombre);

        if (nombre == 0) {
            printf("0");
        } else {
            int bits[32];
            int j = 0;

            while (nombre > 0) {
                bits[j] = nombre % 2;
                nombre = nombre / 2;
                j++;
            }

            for (j = j - 1; j >= 0; j--) {
                printf("%d", bits[j]);
            }
        }

        printf("\n");
    }

    return 0;
}