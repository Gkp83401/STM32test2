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
    // ����
    screen_w(0, 0x01);
    // ������ƶ�����1�е�6��λ����
    // 0x80�������ƶ�
    // 0x00����ȥ����1��
    // 0x06�����6��λ��
    screen_w(0, 0x80 + 0x00 + 0x06);
    // д���1���ַ�
    screen_w(1, 0x00);
    // д���2���ַ�
    screen_w(1, 0x01);
    // д���3���ַ�
    screen_w(1, 0x02);
    // д���4���ַ�
    screen_w(1, 0x03);
    
    // ������ƶ�����2�е�6��λ����
    // 0x80�������ƶ�
    // 0x40�����2��
    // 0x06�����6��λ��
    screen_w(0, 0x80 + 0x40 + 0x06);
    // д���5���ַ�
    screen_w(1, 0x04);
    // д���6���ַ�
    screen_w(1, 0x05);
    // д���7���ַ�
    screen_w(1, 0x06);
    // д���8���ַ�
    screen_w(1, 0x07);
    
    // �ù�겻��ʾ
    screen_w(0, 0x0C);
    
    // ʵ������4��
    // �ӳ�500����λ��ʱ��
    ddd(50);
    for (i = 0; i < 4; i++) {
        // ÿ��ʾһ���ӳ�100����λ��ʱ�䣬���ƶ�
        ddd(100);
        // ��������ʾ����һ��
        screen_w(0, 0x18);
    }
    
    // �ӳ�100����λ��ʱ��
    ddd(100);
    for (i = 0; i < 14; i++) {
        // ÿ��ʾһ���ӳ�30����λ��ʱ�䣬���ƶ�
        ddd(30);
        // ��������ʾ����һ��
        screen_w(0, 0x1C);
    }
    // 20����λ����ʱ
    ddd(20);
    screen_w(0, 0x0F);
}
