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
extern unsigned char myChar[8][8];

// 对写入模式做一个说明

// 当 rs = 1 就是向对应位置写入数据，有两种位置（自定义字符位置
// 和显示屏幕位置），只需要理会后者，前者的操作用下面的
// initMyChar()封装起来了。

// 当 rs = 0 对屏幕显示进行设置
// 编号     D7      D6      D5      D4      D3      D2      D1      D0
// 1        0       0       0       0       0       0       0       1       清屏
// 2        0       0       0       0       0       0       1       x       光标返回
// 3        0       0       0       0       0       1       I/D     S       显示设置
// 4        0       0       0       0       1       D       C       S       显示及开关
// 5        0       0       0       1       S/C     R/L     x       x       整体或光标移位
// 6        0       0       1       DL      N       F       x       x       一些奇怪的设置
// 7        0       1       (      字符库地址 0x00 - 0x1F            )       光标去到字符库
// 8        1       (       显示地址 第1行0x00开始 第2行0x40开始      )       光标去到显示位
//
// 3    I/D 写入字符后光标加1或减1 1(INC, 加1) 0 (DES, 减1)       S 开启写入后移动,移动方向由I/D决定 (INC 左移) (DES 右移)
//      在程序中设置为0x06
// 4    D 屏幕是否显示字 1(显示)     C 光标有无 1(有)     B 光标闪烁 1(闪)  (奇怪点设置有闪，光标必有)
//      程序中大部分时候是 0x0F
// 5
void screen_w(unsigned char rs, unsigned char d_0_to_7);

unsigned char screen_r(unsigned char rs);

unsigned char screen_r_busy(void);

unsigned char screen_r_address(void);

void my_printf(char *string);

void initMyChar(void); 

void clearAString(unsigned int length, unsigned int position);

void screenWriteAndReturn(char *str);

#endif
