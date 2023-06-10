#include "base.h"
#include "screen.h"

void init()
{
    // 这一段是固定设置
    RCC_APB2ENR |= 1 << 3;
    RCC_APB2ENR |= 1 << 4;
    GPIOC_CRL = 0x84444444;
    GPIOC_ODR = 0x0000;
    GPIOB_CRL = 0x33333333;
    GPIOB_CRH = 0x33333333;
    // 固定设置
    screen_w(0, 0x38);
    // 固定设置
    // 置1时 位1 指针加1, 位0 屏幕移动
    screen_w(0, 0x06);
    
}
