#include "screen.h"

// 这个字符数组用来存放自定义的字符
// 其中每8个char类型用来构建一个字符
// 要去screen.h改长度 
unsigned char myChar[8][8];

void screen_w(unsigned char rs, unsigned char d_0_to_7)
{
    while (screen_r_busy() & 0x80);
    // make e = 0, rw = 0
    GPIOB_ODR = (GPIOB_ODR & 0x0000) | (rs << 11) | (1 << 10) |
        d_0_to_7 | ((unsigned int)(d_0_to_7 & 0x18) << 9);
    GPIOB_BRR = 0x0400;
}

unsigned char screen_r(unsigned char rs)
{
    int i;
    unsigned char result;
    GPIOB_CRL = 0x44433444;
    GPIOB_CRH = 0x33443333;
    
    // 设置rs
    // rw = 1, e = 1
    GPIOB_BRR = 0x0800;
    GPIOB_BSRR = 0x0600 | (rs << 11);
    
    for (i = 0; i < 100; i++);
    
    result = (GPIOB_IDR & 0xE7) | ((unsigned int)(GPIOB_IDR & 0x3000) >> 9);
    
    GPIOB_CRL = 0x33333333;
    GPIOB_CRH = 0x33333333;
    return result;
}

unsigned char screen_r_busy()
{
    return screen_r(0) & 0x80;
}

unsigned char screen_r_address()
{
    int i;
    for (i = 0; i < 4000; i++);
    return screen_r(0) & 0x7F;
}
void my_printf(char *string)
{
    int i = 0;
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
    int i, j;
    int position;
    position = screen_r_address();
    for (j = 0; j < 8; j++) {
        screen_w(0, 0x40 + j * 8);
        for (i = 0; i < 8; i++) {
            screen_w(1, myChar[j][i]);
        }
    }
    screen_w(0, 0x80 | position);
}

void clearAString(unsigned int length, unsigned int position)
{
    unsigned int i;
    screen_w(0, 0x80 | position);
    for (i = 0; i < length; i++) {
        screen_w(1, ' ');
    }
    screen_w(0, 0x80 | position);
    return;
}

void screenWriteAndReturn(char *str)
{
    int position;
    position = screen_r_address();
    my_printf(str);
    screen_w(0, 0x80 + position);
    return;
}
