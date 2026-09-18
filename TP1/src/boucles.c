#include <stdio.h>

int main(void) {
    int compteur = 5;

    for (int i = 0; i < compteur; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == compteur - 1 || j == 0 || j == i) {
                printf("* ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }

    return 0;
}