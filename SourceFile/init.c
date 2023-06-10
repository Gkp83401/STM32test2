#include "base.h"
#include "screen.h"

void init()
{
    // ��һ���ǹ̶�����
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
    
}