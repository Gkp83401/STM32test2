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
    // ��1ʱ λ2 ����Ļ, λ1 �����, λ0 ����˸
    screen_w(0, 0x0F);
    screen_w(0, 0x01);
    initMyChar();
    /*
    screen_w(1, '1');
    screen_w(1, '2');
    screen_w(1, '3');
    screen_w(0, 0x80 + 0x40);
    screen_w(1, 'a');
    screen_w(1, 'b');
    screen_w(1, 'c');
    
    
    screen_w(1, 0x00);
    screen_w(1, 0x01);
    */
    
}
