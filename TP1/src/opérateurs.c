#include <stdio.h>
#include <stdbool.h>

int main() {
    int a = 16;
    int b = 3;

    printf("Addition : %d\n", a + b);
    printf("Soustraction : %d\n", a - b);
    printf("Multiplication : %d\n", a * b);
    printf("Division : %d\n", a / b);
    printf("Modulo : %d\n", a % b);

    printf("a est égal à b : %s\n", (a == b) ? "true" : "false");
    printf("a est supérieur à b : %s\n", (a > b) ? "true" : "false");

    return 0;
}
