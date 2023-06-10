#ifndef KEYBOARD_H
#define KEYBOARD_H

// 从GPIOC读取键盘的输入
#define GPIOC_CRL   *((volatile unsigned long*)0x40011000)
#define GPIOC_CRH   *((volatile unsigned long*)0x40011004)
#define GPIOC_IDR   *((volatile unsigned long*)0x40011008)
#define GPIOC_ODR   *((volatile unsigned long*)0x4001100C)
#define GPIOC_BRR   *((volatile unsigned long*)0x40011014)
#define GPIOC_BSRR  *((volatile unsigned long*)0x40011010)

#define keyESC      0x1B
#define keyLF       '\n'
#define keyUP       0x80
#define keyDOWN     0x81
#define keyLEFT     0x82
#define keyRIGHT    0x83
#define keyBS       0x08
#define keyUNUSE1   0x84
#define keyUNUSE2   0x85

#define NO_PRESS_AGAIN      0
#define HAVE_PRESS_AGAIN    1

extern const char transform1[41];
extern const char transform2[41];

// 获取一个字符
// 返回0代表没有获取到字符
char toGetKey(char preChar);

#endif
