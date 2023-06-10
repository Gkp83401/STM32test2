#ifndef SCREEN_H
#define SCREEN_H

// ´ÓGPIOBÏòÆÁÄ»ÊäÈë×Ö·û
#define GPIOB_CRL   *((volatile unsigned long*)0x40010C00)
#define GPIOB_CRH   *((volatile unsigned long*)0x40010C04)
#define GPIOB_IDR   *((volatile unsigned long*)0x40010C08)
#define GPIOB_ODR   *((volatile unsigned long*)0x40010C0C)
#define GPIOB_BRR   *((volatile unsigned long*)0x40010C14)
#define GPIOB_BSRR  *((volatile unsigned long*)0x40010C10)

extern unsigned char myChar[8][8];

void screen_w(unsigned char rs, unsigned char d_0_to_7);

unsigned char screen_r(unsigned char rs);

unsigned char screen_r_address(void);

void my_printf(char *string);

void initMyChar(void);

void isRight(void);

void isError(void);

#endif
