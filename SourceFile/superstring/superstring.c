#include "superstring.h"
#include "screen.h"
#include "keyValue.h"
#include "speSignal.h"

unsigned char toWriteCh(superstring *aSuperstring, char aChar)
{
    if (aChar >= 0x20 && aChar <= 0x7F) {
        if (aSuperstring->scrIndex == aSuperstring->index) {
            aSuperstring->str[aSuperstring->index] = aChar;
            aSuperstring->str[aSuperstring->index+1] = 0;
            screen_w(1, aChar);
            aSuperstring->index++;
            aSuperstring->scrIndex++;
        } else {
        }
        return NORMAL_RETURN;
    }
    if (aChar == (char)keyESC) {
        return TO_RESET;
    }
    if (aChar == (char)keyLF) {     // 外层设置
        return NORMAL_RETURN;
    }
    if (aChar == (char)keyUP) {     // 外层设置
        return NORMAL_RETURN;
    }
    if (aChar == (char)keyDOWN) {   // 外层设置
        return NORMAL_RETURN;
    }
    if (aChar == (char)keyLEFT) {
        if (aSuperstring->scrIndex == 0)
            return NORMAL_RETURN;
        screen_w(0, 0x10);
        aSuperstring->scrIndex--;
        return NORMAL_RETURN;
    }
    if (aChar == (char)keyRIGHT) {
        if (aSuperstring->index == aSuperstring->scrIndex)
            return NORMAL_RETURN;
        screen_w(0, 0x14);
        aSuperstring->scrIndex++;
        return NORMAL_RETURN;
    }
    if (aChar == (char)keyBS) {
        return;
    }
    if (aChar == (char)keyUNUSE1) {
        return;
    }
    if (aChar == (char)keyUNUSE2) {
        return;
    }
}