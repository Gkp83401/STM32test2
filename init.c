#include "base.h"
#include "screen.h"

void init()
{
    isWhere = 0;
    // ��1ʱ λ2 ����Ļ, λ1 �����, λ0 ����˸
    screen_w(0, 0x0F);
    screen_w(0, 0x01);
    pressAgain = 0;
    /*
    screen_w(1, '1');
    screen_w(1, '2');
    screen_w(1, '3');
    screen_w(0, 0x80 + 0x40);
    screen_w(1, 'a');
    screen_w(1, 'b');
    screen_w(1, 'c');
    
    
    initMyChar();
    screen_w(1, 0x00);
    screen_w(1, 0x01);
    */
}
