#ifndef SCREEN_H
#define SCREEN_H

// 从GPIOB向屏幕输入字符
#define GPIOB_CRL   *((volatile unsigned long*)0x40010C00)
#define GPIOB_CRH   *((volatile unsigned long*)0x40010C04)
#define GPIOB_IDR   *((volatile unsigned long*)0x40010C08)
#define GPIOB_ODR   *((volatile unsigned long*)0x40010C0C)
#define GPIOB_BRR   *((volatile unsigned long*)0x40010C14)
#define GPIOB_BSRR  *((volatile unsigned long*)0x40010C10)

// 这个字符数组用来存放自定义的字符
// 其中每8个char类型用来构建一个字符
// 要去screen.h改长度 
unsigned char myChar[8][8]={
    {0x07,0x08,0x00,0x08,0x1c,0x08,0x07,0x00},
    {0x1F,0x08,0x00,0x08,0x1c,0x08,0x07,0x00},
    {0x1F,0x1F,0x00,0x08,0x1c,0x08,0x07,0x00},
    {0x1F,0x08,0x1F,0x08,0x1c,0x08,0x07,0x00},
    {0x1F,0x08,0x00,0x1F,0x1c,0x08,0x07,0x00},
    {0x1F,0x08,0x00,0x08,0x1F,0x08,0x07,0x00},
    {0x1F,0x08,0x00,0x08,0x1c,0x1F,0x07,0x00}
    // {0x1F,0x08,0x00,0x08,0x1c,0x08,0x1F,0x00}
};

void screen_w(unsigned char rs, unsigned char d_0_to_7);

unsigned char screen_r(unsigned char rs);

unsigned char screen_r_busy(void);

unsigned char screen_r_address(void);

void my_printf(char *string);

void initMyChar(void); 

#endif
