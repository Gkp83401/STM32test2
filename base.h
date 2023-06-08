#ifndef BASE_H
#define BASE_H

#define GPIOB_CRL   *((volatile unsigned long*)0x40010C00)
#define GPIOB_CRH   *((volatile unsigned long*)0x40010C04)
#define GPIOB_IDR   *((volatile unsigned long*)0x40010C08)
#define GPIOB_ODR   *((volatile unsigned long*)0x40010C0C)
#define GPIOB_BRR   *((volatile unsigned long*)0x40010C14)
#define GPIOB_BSRR  *((volatile unsigned long*)0x40010C10)
#define GPIOC_CRL   *((volatile unsigned long*)0x40011000)
#define GPIOC_CRH   *((volatile unsigned long*)0x40011004)
#define GPIOC_IDR   *((volatile unsigned long*)0x40011008)
#define GPIOC_ODR   *((volatile unsigned long*)0x4001100C)
#define GPIOC_BRR   *((volatile unsigned long*)0x40011014)
#define GPIOC_BSRR  *((volatile unsigned long*)0x40011010)
#define RCC_APB2ENR *((volatile unsigned long*)0x40021018)
    
extern unsigned char myChar[8][8];
extern const char transform1[41];
extern const char transform2[41];
extern unsigned char isWhere;
extern char strOn[30];
extern unsigned char strOnCaps[30];
extern unsigned char pressAgain;
    
void init(void);
    
void ddd(unsigned int u);

unsigned char strCmp(char *mode);


typedef struct
{
    unsigned char gs;
    unsigned char caps;
    unsigned char c;
} getKey;

void toGetKey(getKey *aGetKeyPoint);

#endif
