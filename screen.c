#include "base.h"
#include "screen.h"

void screen_w(unsigned char rs, unsigned char d_0_to_7)
{
    while (screen_r(0) & 0x80);
    // make e = 0, rw = 0
    GPIOB_ODR = (GPIOB_ODR & 0x0000) | (rs << 11) | (1 << 10) |
        d_0_to_7 | ((unsigned int)(d_0_to_7 & 0x18) << 9);
    GPIOB_BRR = 0x0400;
}

unsigned char screen_r(unsigned char rs)
{
    unsigned int i;
    unsigned char result;
    GPIOB_CRL = 0x44433444;
    GPIOB_CRH = 0x33443333;
    
    // ÉèÖÃrs
    // rw = 1, e = 1
    GPIOB_BRR = 0x0800;
    GPIOB_BSRR = 0x0600 | (rs << 11);
    
    for (i = 0; i < 100; i++);
    
    result = (GPIOB_IDR & 0xE7) | ((unsigned int)(GPIOB_IDR & 0x3000) >> 9);
    
    GPIOB_CRL = 0x33333333;
    GPIOB_CRH = 0x33333333;
    return result;
}

void isRight()
{
    my_printf("\nright");
}
void my_printf(char *string)
{
    unsigned char i = 0;
    while (string[i]) {
        if (string[i] == '\n') {
            screen_w(0, 0xC0);
            i++;
            continue;
        }
        screen_w(1, string[i]);
        i++;
    }
    
}
void initMyChar()
{
    unsigned char i, j;
    unsigned char position;
    position = screen_r(0) & 0x7F;
    for (j = 0; j < sizeof(myChar) / (8 * sizeof(unsigned char)); j++) {
        screen_w(0, 0x40 + j * 8);
        for (i = 0; i < 8; i++) {
            screen_w(1, myChar[j][i]);
        }
    }
    screen_w(0, 0x80 | position);
}
