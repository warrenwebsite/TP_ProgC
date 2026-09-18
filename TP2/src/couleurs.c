#include <stdio.h>

struct Couleur {
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
};

int main(void) {
    struct Couleur palette[10] = {
        {0xef, 0x78, 0x12, 0xff},
        {0x2c, 0xc8, 0x64, 0xff},
        {0x1a, 0x2b, 0x3c, 0x80},
        {0xff, 0x00, 0x00, 0xff},
        {0x00, 0xff, 0x00, 0xff},
        {0x00, 0x00, 0xff, 0xff},
        {0xff, 0xff, 0x00, 0xaa},
        {0x00, 0xff, 0xff, 0x55},
        {0xff, 0x00, 0xff, 0xee},
        {0x12, 0x34, 0x56, 0x78}
    };

    for (int i = 0; i < 10; i++) {
        printf("Couleur %d :\n", i + 1);
        printf("Rouge : %u\n", palette[i].R);
        printf("Vert : %u\n", palette[i].G);
        printf("Bleu : %u\n", palette[i].B);
        printf("Alpha : %u\n\n", palette[i].A);
    }

    return 0;
}