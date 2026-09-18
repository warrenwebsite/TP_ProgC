#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(void) {
    char c = 0x12;
    short s = 0x1234;
    int i = 0x12345678;
    long int li = 0x1122334455667788L;
    long long int lli = 0x0123456789ABCDEFLL;
    float f = 2.0f;
    double d = 2.0;
    long double ld = 2.0L;

    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long int *pli = &li;
    long long int *plli = &lli;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    uint32_t f_hex, d_hex_low;
    memcpy(&f_hex, &f, sizeof(float));
    memcpy(&d_hex_low, &d, sizeof(uint32_t));

    printf("Avant la manipulation :\n");
    printf("Adresse de c   : %p, Valeur de c   : %02hhx\n", (void*)pc, (unsigned char)*pc);
    printf("Adresse de s   : %p, Valeur de s   : %04hx\n", (void*)ps, (unsigned short)*ps);
    printf("Adresse de i   : %p, Valeur de i   : %08x\n", (void*)pi, *pi);
    printf("Adresse de li  : %p, Valeur de li  : %016lx\n", (void*)pli, *pli);
    printf("Adresse de lli : %p, Valeur de lli : %016llx\n", (void*)plli, *plli);
    printf("Adresse de f   : %p, Valeur de f   : %08x\n", (void*)pf, f_hex);
    printf("Adresse de d   : %p, Valeur de d   : %08x\n", (void*)pd, d_hex_low);
    printf("Adresse de ld  : %p\n\n", (void*)pld);

    // Modification via les pointeurs
    *pc = 0x34;
    *ps = 0x4321;
    *pi = 0x78563412;
    *pli = 0x8877665544332211L;
    *plli = 0x0FEDCBA987654321LL;
    *pf = 1.0f;
    *pd = 1.0;
    *pld = 1.0L;

    memcpy(&f_hex, &f, sizeof(float));
    memcpy(&d_hex_low, &d, sizeof(uint32_t));

    printf("Après la manipulation :\n");
    printf("Adresse de c   : %p, Valeur de c   : %02hhx\n", (void*)pc, (unsigned char)*pc);
    printf("Adresse de s   : %p, Valeur de s   : %04hx\n", (void*)ps, (unsigned short)*ps);
    printf("Adresse de i   : %p, Valeur de i   : %08x\n", (void*)pi, *pi);
    printf("Adresse de li  : %p, Valeur de li  : %016lx\n", (void*)pli, *pli);
    printf("Adresse de lli : %p, Valeur de lli : %016llx\n", (void*)plli, *plli);
    printf("Adresse de f   : %p, Valeur de f   : %08x\n", (void*)pf, f_hex);
    printf("Adresse de d   : %p, Valeur de d   : %08x\n", (void*)pd, d_hex_low);
    printf("Adresse de ld  : %p\n", (void*)pld);

    return 0;
}