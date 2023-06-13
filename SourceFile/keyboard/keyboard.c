#include "keyboard.h"
#include "delay.h"

// 下面2个数组用来将键盘上获取到的数据转成对应的字符
// 小写字符
const char transform1[41] = 
{
    '1', '2', 'q', 'w', 'a', 's', 'z', 'x',
    '3', '4', 'e', 'r', 'd', 'f', 'c', 'v',
    '5', '6', 't', 'y', 'g', 'h', 'b', 'n',
    '7', '8', 'u', 'i', 'j', 'k', 'm', keyESC,
    '9', '0', 'o', 'p', 'l', keyLF, keyUP, keyDOWN,
    keyUNUSE1
};
// 大写字符
const char transform2[41] = 
{
    '+', '-', 'Q', 'W', 'A', 'S', 'Z', 'X',
    '#', '$', 'E', 'R', 'D', 'F', 'C', 'V',
    '%', '^', 'T', 'Y', 'G', 'H', 'B', 'N',
    '/', '*', 'U', 'I', 'J', 'K', 'M', ' ',
    '(', ')', 'O', 'P', 'L', keyBS, keyLEFT, keyRIGHT,
    keyUNUSE2
};

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
