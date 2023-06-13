#ifndef BASE_H
#define BASE_H

#include "screen.h"
#include "keyboard.h"

#include "envCartoon.h"
#include "envLogin.h"
#include "envCLI.h"
#include "envEditor.h"
#include "envLoginOutImformation.h"

#include "fileSystem.h"

#include "speSignal.h"


// ��������GPIOB��GPIOC�������˿�
#define RCC_APB2ENR *((volatile unsigned long*)0x40021018)
    
    
void init(void);



#endif
