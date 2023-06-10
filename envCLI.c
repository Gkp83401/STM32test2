#include "base.h"
#include "screen.h"

// 表示每次回车前输入了什么字符串
unsigned char isWhere;
char strOn[30];
unsigned char strOnCaps[30];

void envCLI()
{
    getKey aGetKey;
    screen_w(0, 0x01);
    my_printf("$ ");
    
    // 每次循环代表开始新的按下
    while(1)
    {
        toGetKey(&aGetKey);
        
        
        if (aGetKey.gs) {
            // 清屏
            if (aGetKey.c == 0x1F && !(aGetKey.caps)) {
                // init();
            }
            else if (aGetKey.c == 0x25) {
                if (aGetKey.caps) { // 退格
                    if (isWhere != 0) {
                        isWhere--;
                        screen_w(0, 0x10);
                        screen_w(1, ' ');
                        screen_w(0, 0x10);
                    }
                } else {            // 回车
                    if (strCmp("right"))
                        isRight();
                    else
                        isError();
                    screen_w(0, 0x80);
                    my_printf("                               ");
                    screen_w(0, 0x02);
                    my_printf("$ ");
                    
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
