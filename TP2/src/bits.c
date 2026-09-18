#include <stdio.h>

int main(void) {
    int d = 0x10001000;

    int bit4 = (d >> 28) & 1;
    int bit20 = (d >> 12) & 1;

    if (bit4 == 1 && bit20 == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}