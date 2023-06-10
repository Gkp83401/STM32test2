#include "envCLI.h"
#include "screen.h"


unsigned char envCLI()
{
    // 表示每次回车前输入了什么字符串
    unsigned char isWhere;
    char strOn[30];
    
    getKey aGetKey;
    screen_w(0, 0x01);
    my_printf("$ ");
    
    // 每次循环代表开始新的按下
    while(1)
    {
        toGetKey(&aGetKey);
        
        
        if (aGetKey.gs) {
            
            // 存程输入
            if (aGetKey.caps) {
                strOn[isWhere] = transform2[aGetKey.c];
            }
            else {
                strOn[isWhere] = transform1[aGetKey.c];
            }
            isWhere++;
            strOn[isWhere] = 0;
            
            // 处理字符
            // 清屏
            if (aGetKey.c == 0x1F && !(aGetKey.caps)) {
                return TO_RESET;
            }
            if (aGetKey.c == 0x25) {
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
                
            }
            
        }
    }
}
