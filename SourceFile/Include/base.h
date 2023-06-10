#ifndef BASE_H
#define BASE_H

#include "screen.h"
#include "envCLI.h"
#include "keyboard.h"

// 用来开启GPIOB和GPIOC这两个端口
#define RCC_APB2ENR *((volatile unsigned long*)0x40021018)
    
    

extern unsigned char isWhere;
extern char strOn[30];
extern unsigned char strOnCaps[30];
extern unsigned char pressAgain;
    
void init(void);
    
unsigned char strCmp(char *mode);

unsigned char strCmp2(char *ch1, char *ch2);


void envLogin(void);

#endif
