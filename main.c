#include "outer_define.h"

void SystemInit() {}
    
#define GPIOB_CRL *((volatile unsigned long*)0x40010C00)
#define GPIOB_CRH *((volatile unsigned long*)0x40010C04)
#define GPIOB_IDR *((volatile unsigned long*)0x40010C08)
#define GPIOB_ODR *((volatile unsigned long*)0x40010C0C)
#define GPIOB_BRR *((volatile unsigned long*)0x40010C14)
#define GPIOB_BSRR *((volatile unsigned long*)0x40010C10)
#define RCC_APB2ENR *((volatile unsigned long*)0x40021018)

void ddd()
{
    int i;
    for (i = 0; i < 10000; i++);
}
	
void screen(unsigned char rs, unsigned char rw, unsigned char e, unsigned char d_0_to_7)
{
    int i;
    GPIOB_ODR = (GPIOB_ODR & 0x0000) | (rs << 11) | (rw << 9) | (e << 10) |
        d_0_to_7 | ((unsigned int)(d_0_to_7 & 0x18) << 9);
    GPIOB_BSRR = 0x0400;
    for (i = 0; i < 10000; i++);
    GPIOB_BRR = 0x0400;
    for (i = 0; i < 10000; i++);
}
int main()
{
	/* The 0x00 is setting have or not have cursor */
	// unsigned char initCommands[] = {0x38, 0x0F, 0x06, 0x01};
	RCC_APB2ENR |= 1 << 3;
	GPIOB_CRL = 0x33333333;
	GPIOB_CRH = 0x33333333;
	
    screen(0, 0, 0, 0x38);
//    GPIOB_ODR = (GPIOB_ODR & 0xF000) | 0x38 | 0x3000;
//	GPIOB_BSRR = 0x0400;
//	ddd();
//	GPIOB_BRR = 0x0400;
//    ddd();
    
    screen(0, 0, 0, 0x01);
//    GPIOB_ODR = (GPIOB_ODR & 0x0000) | 0x01 | 0x0000;
//	GPIOB_BSRR = 0x0400;
//	ddd();
//	GPIOB_BRR = 0x0400;
//    ddd();
    
    screen(0, 0, 0, 0x0F);
//    GPIOB_ODR = (GPIOB_ODR & 0x0000) | 0x0F | 0x1000;
//	GPIOB_BSRR = 0x0400;
//	ddd();
//	GPIOB_BRR = 0x0400;
//    ddd();
    
    screen(0, 0, 0, 0x06);
//    GPIOB_ODR = (GPIOB_ODR & 0x0000) | 0x06 | 0x0000;
//	GPIOB_BSRR = 0x0400;
//	ddd();
//	GPIOB_BRR = 0x0400;
//    ddd();
    
    screen(1, 0, 0, 't');
    screen(1, 0, 0, 'w');
//    GPIOB_ODR = (GPIOB_ODR & 0x0000) | 0x0800 | 't';
//	GPIOB_BSRR = 0x0400;
//	ddd();
//	GPIOB_BRR = 0x0400;
//    ddd();
	
	ddd();
	// init(HAVE_CURSOR);
	// my_printf("hello\nworld!");
	while(1);
}
