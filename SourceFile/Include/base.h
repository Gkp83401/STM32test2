#ifndef BASE_H
#define BASE_H

#include "screen.h"
#include "keyboard.h"
#include "envLogin.h"
#include "envCLI.h"


// ��������GPIOB��GPIOC�������˿�
#define RCC_APB2ENR *((volatile unsigned long*)0x40021018)
    
    
void init(void);



#endif
