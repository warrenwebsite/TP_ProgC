#include <stdio.h>

int main() {
    char c = 'A';
    signed char sc = -10;
    unsigned char uc = 200;

    short s = -1000;
    signed short ss = -2000;
    unsigned short us = 50000;

    int i = -100000;
    signed int si = -200000;
    unsigned int ui = 300000;

    long int l = -1000000;
    signed long int sl = -2000000;
    unsigned long int ul = 3000000;

    long long int ll = -1000000000LL;
    signed long long int sll = -2000000000LL;
    unsigned long long int ull = 3000000000ULL;

    float f = 3.14f;
    double d = 3.141592;
    long double ld = 3.141592653589793L;

    printf("char : %c\n", c);
    printf("signed char : %hhd\n", sc);
    printf("unsigned char : %hhu\n", uc);

    printf("short : %hd\n", s);
    printf("signed short : %hd\n", ss);
    printf("unsigned short : %hu\n", us);

    printf("int : %d\n", i);
    printf("signed int : %d\n", si);
    printf("unsigned int : %u\n", ui);

    printf("long int : %ld\n", l);
    printf("signed long int : %ld\n", sl);
    printf("unsigned long int : %lu\n", ul);

    printf("long long int : %lld\n", ll);
    printf("signed long long int : %lld\n", sll);
    printf("unsigned long long int : %llu\n", ull);

    printf("float : %f\n", f);
    printf("double : %lf\n", d);
    printf("long double : %Lf\n", ld);

    return 0;
}