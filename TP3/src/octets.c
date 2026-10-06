#include <stdio.h>

void afficher_octets(const void *ptr, size_t taille, const char *nom) {
    const unsigned char *p = (const unsigned char *)ptr;
    printf("Octets de %s :\n", nom);
    for (size_t i = 0; i < taille; i++) {
        printf(" %02x", p[i]);
    }
    printf("\n\n");
}

int main(void) {
    short s = 0x0302;
    int i = 0x04030201;
    long int li = 0x0807060504030201L;
    float f = 2.0f;
    double d = 2.0;
    long double ld = 2.0L;

    afficher_octets(&s, sizeof(s), "short");
    afficher_octets(&i, sizeof(i), "int");
    afficher_octets(&li, sizeof(li), "long int");
    afficher_octets(&f, sizeof(f), "float");
    afficher_octets(&d, sizeof(d), "double");
    afficher_octets(&ld, sizeof(ld), "long double");

    return 0;
}