#include "keyboard.h"
#include "delay.h"

// 用来判断按键是否被重复按下
// 可以为NO_PRESS_AGAIN和HAVE_PRESS_AGAIN
unsigned char pressAgain = 0;

unsigned int noInput = 0;

char toGetKey(char preChar)
{
    unsigned int used;
    char getChar;
    
    // 按下识别时间
    if (pressAgain == HAVE_PRESS_AGAIN)
        ddd(5);
    else
        ddd(20);
    
    used = (GPIOC_IDR & 0xFF);
    if (used & 0x80) {
        
        ddd(1);
        if (used != (GPIOC_IDR & 0xFF))
            return NO_GETCHAR;
        ddd(1);
        if (used != (GPIOC_IDR & 0xFF))
            return NO_GETCHAR;
        
        noInput = 0;
        if (used & 0x40) {
            getChar = transform2[used&0x3F];
        } else {
            getChar = transform1[used&0x3F];
        }
        
        // 判断不是字符串的开头并且和上一个字符相同
        if (preChar !=0 && preChar == getChar) {
            // 是第一次字符相同
            // 这里选择延迟并当做没有获取输入来退出
            if (pressAgain == NO_PRESS_AGAIN) {
                ddd(20);
                return NO_GETCHAR;
            }
            // 之前已经有字符相同，然后再次相同
            pressAgain = HAVE_PRESS_AGAIN;
        } else {
            
            pressAgain = NO_PRESS_AGAIN;
        }
        
        return getChar;
    }
    // 没有获取到输入
    if (noInput == 300)
        pressAgain = NO_PRESS_AGAIN;
    else
        noInput++;
    return NO_GETCHAR;
}
