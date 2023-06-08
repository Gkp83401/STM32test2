#include "base.h"
#include "screen.h"

// �м����ַ�Ҫ�ǵ�ȥbase.hȥ��
unsigned char myChar[8][8]={
    {0x07,0x08,0x00,0x08,0x1c,0x08,0x07,0x00},
    {0x1F,0x08,0x00,0x08,0x1c,0x08,0x07,0x00},
    {0x1F,0x1F,0x00,0x08,0x1c,0x08,0x07,0x00},
    {0x1F,0x08,0x1F,0x08,0x1c,0x08,0x07,0x00},
    {0x1F,0x08,0x00,0x1F,0x1c,0x08,0x07,0x00},
    {0x1F,0x08,0x00,0x08,0x1F,0x08,0x07,0x00},
    {0x1F,0x08,0x00,0x08,0x1c,0x1F,0x07,0x00},
    {0x1F,0x08,0x00,0x08,0x1c,0x08,0x1F,0x00}
};
const char transform1[41] = 
{
    '1', '2', 'q', 'w', 'a', 's', 'z', 'x',
    '3', '4', 'e', 'r', 'd', 'f', 'c', 'v',
    '5', '6', 't', 'y', 'g', 'h', 'b', 'n',
    '7', '8', 'u', 'i', 'j', 'k', 'm', 0,
    '9', '0', 'o', 'p', 'l', 0,   0,   0,
    0
};
const char transform2[41] = 
{
    '!', '@', 'Q', 'W', 'A', 'S', 'Z', 'X',
    '#', '$', 'E', 'R', 'D', 'F', 'C', 'V',
    '%', '^', 'T', 'Y', 'G', 'H', 'B', 'N',
    '&', '*', 'U', 'I', 'J', 'K', 'M', ' ',
    '(', ')', 'O', 'P', 'L', 0,   0,   0,
    0
};

unsigned char isWhere;
char strOn[30];
unsigned char strOnCaps[30];

unsigned char pressAgain;

int main()
{
    getKey aGetKey;
    RCC_APB2ENR |= 1 << 3;
    RCC_APB2ENR |= 1 << 4;
    GPIOC_CRL = 0x84444444;
    GPIOC_ODR = 0x0000;
    GPIOB_CRL = 0x33333333;
    GPIOB_CRH = 0x33333333;
    // �̶�����
    screen_w(0, 0x38);
    // �̶�����
    // ��1ʱ λ1 ָ���1, λ0 ��Ļ�ƶ�
    screen_w(0, 0x06);
    
    
    init();
    
    
    
    
    // ÿ��ѭ������ʼ�µİ���
    while(1)
    {
        toGetKey(&aGetKey);
        
        
        if (aGetKey.gs) {
            // ����
            if (aGetKey.c == 0x1F && !(aGetKey.caps)) {
                init();
            }
            else if (aGetKey.c == 0x25) {
                if (aGetKey.caps) {
                    if (isWhere != 0) {
                        isWhere--;
                        screen_w(0, 0x10);
                        screen_w(1, ' ');
                        screen_w(0, 0x10);
                    }
                } else {
                    screen_w(0, 0xC0);
                    if (strCmp("right"))
                        isRight();
                    isWhere = 0;
                }
                
            } else {
                if (aGetKey.caps) {
                    strOnCaps[isWhere] = 1;
                    strOn[isWhere] = aGetKey.c;
                    screen_w(1, transform2[aGetKey.c]);
                }
                else {
                    strOnCaps[isWhere] = 0;
                    strOn[isWhere] = aGetKey.c;
                    screen_w(1, transform1[aGetKey.c]);
                }
                isWhere++;
            }
            
        }
    }
    
}
