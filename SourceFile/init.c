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
    
    if (fileSystemInit() == FILE_SYSTEM_INIT_FAIL) {
        screen_w(0, 0x01);
        my_printf("crash\nfile system not succeed");
    }
    
}
