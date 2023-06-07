void SystemInit() {}
    
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

void ddd(unsigned int u)
{
    unsigned long int i;
    for (i = 0; i < 10000 * (unsigned long int)u; i++);
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
    int i;
    unsigned char codetable[]={0x07,0x08,0x00,0x08,0x1c,0x08,0x07,0x00};
    unsigned char transform1[41] = 
    {
        '1', '2', 'q', 'w', 'a', 's', 'z', 'x',
        '3', '4', 'e', 'r', 'd', 'f', 'c', 'v',
        '5', '6', 't', 'y', 'g', 'h', 'b', 'n',
        '7', '8', 'u', 'i', 'j', 'k', 'm', 0,
        '9', '0', 'o', 'p', 'l', 0,   0,   0,
        0
    };
    unsigned char transform2[41] = 
    {
        '!', '@', 'Q', 'W', 'A', 'S', 'Z', 'X',
        '#', '$', 'E', 'R', 'D', 'F', 'C', 'V',
        '%', '^', 'T', 'Y', 'G', 'H', 'B', 'N',
        '&', '*', 'U', 'I', 'J', 'K', 'M', 0,
        '(', ')', 'O', 'P', 'L', 0,   0,   0,
        0
    };
    unsigned char used;
    unsigned char used2;
    unsigned char used3;
	RCC_APB2ENR |= 1 << 3;
    RCC_APB2ENR |= 1 << 4;
    GPIOC_CRL = 0x44444444;
    GPIOC_CRH = 0x44444444;
	GPIOB_CRL = 0x33333333;
	GPIOB_CRH = 0x33333333;
    
    aaa:
    screen(0, 0, 0, 0x38);
    screen(0, 0, 0, 0x0F);
    screen(0, 0, 0, 0x06);
    screen(0, 0, 0, 0x01);
    
    screen(1, 0, 0, '5');
    screen(1, 0, 0, 'G');
    screen(1, 0, 0, 'i');
    /*
    // ×Ô¶¨Òå×Ö·û
    screen(0, 0, 0, 0x40);
    for (i = 0; i < 8; i++) {
        screen(1, 0, 0, codetable[i]);
    }
    screen(0, 0, 0, 0x81);
    screen(1, 0, 0, 0x00);
    */
    
	while(1)
    {
        used = (unsigned char)(GPIOC_IDR & 0xFF);
        if (used & 0x80) {
            used2 = used & 0x3F;
            if (used2 == 0x25)
                screen(0, 0, 0, 0xC0);
            else if (used2 == 0x1F)
                goto aaa;
            else if (used & 0x40)
                screen(1, 0, 0, transform2[used2]);
            else
                screen(1, 0, 0, transform1[used2]);
            
        }
        
        ddd(25);
    }
}
