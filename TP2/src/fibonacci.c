#include <stdio.h>

int main(void) {
    int n = 7;

    if (n < 0) {
        return 0;
    }

    int u0 = 0;
    int u1 = 1;

    printf("Suite de Fibonacci jusqu'à U%d : ", n);

    if (n == 0) {
        printf("%d\n", u0);
        return 0;
    }

    printf("%d, %d", u0, u1);

    for (int i = 2; i <= n; i++) {
        int un = u0 + u1;
        printf(", %d", un);
        u0 = u1;
        u1 = un;
    }

    printf("\n");
    return 0;
}