#include "envCartoon.h"
#include "screen.h"
#include "delay.h"

void envCartoon()
{
    int i;
    myChar[0][0] = 0x01;
    myChar[0][1] = 0x02;
    myChar[0][2] = 0x04;
    myChar[0][3] = 0x08;
    myChar[0][4] = 0x10;
    myChar[0][5] = 0x10;
    myChar[0][6] = 0x10;
    myChar[0][7] = 0x10;
    
    myChar[1][0] = 0x1F;
    myChar[1][1] = 0x00;
    myChar[1][2] = 0x00;
    myChar[1][3] = 0x00;
    myChar[1][4] = 0x01;
    myChar[1][5] = 0x02;
    myChar[1][6] = 0x04;
    myChar[1][7] = 0x05;
    
    myChar[2][0] = 0x1F;
    myChar[2][1] = 0x00;
    myChar[2][2] = 0x00;
    myChar[2][3] = 0x10;
    myChar[2][4] = 0x00;
    myChar[2][5] = 0x00;
    myChar[2][6] = 0x00;
    myChar[2][7] = 0x10;
    
    myChar[3][0] = 0x10;
    myChar[3][1] = 0x08;
    myChar[3][2] = 0x04;
    myChar[3][3] = 0x02;
    myChar[3][4] = 0x01;
    myChar[3][5] = 0x01;
    myChar[3][6] = 0x01;
    myChar[3][7] = 0x01;
    
    myChar[4][0] = 0x10;
    myChar[4][1] = 0x10;
    myChar[4][2] = 0x10;
    myChar[4][3] = 0x10;
    myChar[4][4] = 0x08;
    myChar[4][5] = 0x04;
    myChar[4][6] = 0x02;
    myChar[4][7] = 0x01;
    
    myChar[5][0] = 0x04;
    myChar[5][1] = 0x04;
    myChar[5][2] = 0x04;
    myChar[5][3] = 0x02;
    myChar[5][4] = 0x01;
    myChar[5][5] = 0x00;
    myChar[5][6] = 0x00;
    myChar[5][7] = 0x1F;
    
    myChar[6][0] = 0x08;
    myChar[6][1] = 0x04;
    myChar[6][2] = 0x04;
    myChar[6][3] = 0x08;
    myChar[6][4] = 0x10;
    myChar[6][5] = 0x00;
    myChar[6][6] = 0x00;
    myChar[6][7] = 0x1F;
    
    myChar[7][0] = 0x01;
    myChar[7][1] = 0x01;
    myChar[7][2] = 0x01;
    myChar[7][3] = 0x01;
    myChar[7][4] = 0x02;
    myChar[7][5] = 0x04;
    myChar[7][6] = 0x08;
    myChar[7][7] = 0x10;
    
    initMyChar();
    // 清屏
    screen_w(0, 0x01);
    // 将光标移动到第1行第6个位置上
    // 0x80代表光标移动
    // 0x00代表去到第1行
    // 0x06代表第6个位置
    screen_w(0, 0x80 + 0x00 + 0x06);
    // 写入第1个字符
    screen_w(1, 0x00);
    // 写入第2个字符
    screen_w(1, 0x01);
    // 写入第3个字符
    screen_w(1, 0x02);
    // 写入第4个字符
    screen_w(1, 0x03);
    
    // 将光标移动到第2行第6个位置上
    // 0x80代表光标移动
    // 0x40代表第2行
    // 0x06代表第6个位置
    screen_w(0, 0x80 + 0x40 + 0x06);
    // 写入第5个字符
    screen_w(1, 0x04);
    // 写入第6个字符
    screen_w(1, 0x05);
    // 写入第7个字符
    screen_w(1, 0x06);
    // 写入第8个字符
    screen_w(1, 0x07);
    
    // 让光标不显示
    screen_w(0, 0x0C);
    
    // 实现左移4格
    // 延迟500个单位的时间
    ddd(50);
    for (i = 0; i < 4; i++) {
        // 每显示一个延迟100个单位的时间，再移动
        ddd(100);
        // 让整个显示左移一格
        screen_w(0, 0x18);
    }
    
    // 延迟100个单位的时间
    ddd(100);
    for (i = 0; i < 14; i++) {
        // 每显示一个延迟30个单位的时间，再移动
        ddd(30);
        // 让整个显示右移一格
        screen_w(0, 0x1C);
    }
    // 20个单位的延时
    ddd(20);
    screen_w(0, 0x0F);
}
