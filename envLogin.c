#include "base.h"
#include "screen.h"

void envLogin()
{
    getKey aGetKey;
    char user[30];
    char passwd[30];
    unsigned char i;
    isWhere = 0;
    // 置1时 位2 开屏幕, 位1 开光标, 位0 开闪烁
    screen_w(0, 0x0F);
    screen_w(0, 0x01);
    pressAgain = 0;
    initMyChar();
    
    while(1) {
        // test();
        screen_w(0, 0x01);
        my_printf("user:\npasswd:");
        
        screen_w(0, 0x80 + 0x05);
        i = 0;
        do {
            toGetKey(&aGetKey);
            if (aGetKey.gs) {
                if (aGetKey.c == 0x25) {
                    user[i] = 0;
                    break;
                } else {
                    user[i] = transform1[aGetKey.c];
                    screen_w(1, transform1[aGetKey.c]);
                    i++;
                }
            }
        }while(1);
        screen_w(0, 0x80 + 0x40 + 0x07);
        i = 0;
        do {
            toGetKey(&aGetKey);
            if (aGetKey.gs) {
                if (aGetKey.c == 0x25) {
                    user[i] = 0;
                    break;
                } else {
                    passwd[i] = transform1[aGetKey.c];
                    screen_w(1, '*');
                    i++;
                }
            }
        }while(1);
        if (strCmp2(user, "abc") && strCmp2(passwd, "123")) {
            break;
        }
    }
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
