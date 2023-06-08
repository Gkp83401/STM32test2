#include "base.h"

void toGetKey(getKey *aGetKeyPoint)
{
    unsigned int used;
    
    // 按下识别时间
    if (pressAgain)
        ddd(15);
    else
        ddd(20);
    
    used = (GPIOC_IDR & 0xFF);
    if (used & 0x80) {
        aGetKeyPoint->caps = used & 0x40 ? 1 :0;
        aGetKeyPoint->c = used & 0x3F;
        if (isWhere !=0 && 
            aGetKeyPoint->caps == strOnCaps[isWhere-1] && 
            aGetKeyPoint->c == strOn[isWhere-1]) {
            if (pressAgain) {
                aGetKeyPoint->gs = 1;
            } else {
                aGetKeyPoint->gs = 0;
                ddd(20);
            }
            pressAgain = 1;
        } else {
            pressAgain = 0;
            aGetKeyPoint->gs = 1;
        }
    } else {
        aGetKeyPoint->gs = 0;
    }
}
