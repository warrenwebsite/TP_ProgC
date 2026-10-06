#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage : %s <opérateur> <num1> [num2]\n", argv[0]);
        return 1;
    }

    char op = argv[1][0];
    int num1 = atoi(argv[2]);
    int num2 = (argc >= 4) ? atoi(argv[3]) : 0;
    int res = 0;

    switch (op) {
        case '+': res = somme(num1, num2); break;
        case '-': res = difference(num1, num2); break;
        case '*': res = produit(num1, num2); break;
        case '/': res = quotient(num1, num2); break;
        case '%': res = modulo(num1, num2); break;
        case '&': res = et_logique(num1, num2); break;
        case '|': res = ou_logique(num1, num2); break;
        case '~': res = negation(num1, 0); break;
        default:
            printf("Opérateur inconnu : %c\n", op);
            return 1;
    }

    printf("Résultat : %d\n", res);
    return 0;
}