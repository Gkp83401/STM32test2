#include "superstring.h"
#include "screen.h"
#include "string.h"
#include "keyValue.h"

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
            clearAString(aSuperstring->index - aSuperstring->scrIndex,
                screen_r_address());
            screen_w(1, aChar);
            screenWriteAndReturn(&(aSuperstring->str[aSuperstring->scrIndex]));
            strMoveOneRight(aSuperstring, aChar);
        }
        return NORMAL_RETURN;
    }
    if (aChar == (char)keyESC) {
        return TO_RESET;
    }
    if (aChar == (char)keyNULL) {
        return NORMAL_RETURN;
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
        if (aSuperstring->scrIndex != 0) {
            clearAString(aSuperstring->index - aSuperstring->scrIndex + 1,
                screen_r_address() - 1);
            screenWriteAndReturn(&(aSuperstring->str[aSuperstring->scrIndex]));
            strMoveOneLeft(aSuperstring);
        }
        return NORMAL_RETURN;
    }
    if (aChar == (char)keyUNUSE1) {
        return NORMAL_RETURN;
    }
    if (aChar == (char)keyUNUSE2) {
        return NORMAL_RETURN;
    }
    return UNKNOW_KEY;
}

unsigned char toWriteChOneLine(superstring *aSuperstring, char aChar)
{
    if (aChar == (char)keyLF) {
        return FINISH_INPUT;
    }
    return toWriteCh(aSuperstring, aChar);
}
unsigned char toWriteChOneLinePasswd(superstring *aSuperstring, char aChar)
{
    if (aChar == (char)keyLF) {
        return FINISH_INPUT;
    }
    if (aChar >= 0x20 && aChar <= 0x7F) {
        if (aSuperstring->scrIndex == aSuperstring->index) {
            aSuperstring->str[aSuperstring->index] = aChar;
            aSuperstring->str[aSuperstring->index+1] = 0;
            screen_w(1, '*');
            aSuperstring->index++;
            aSuperstring->scrIndex++;
        } else {
            clearAString(aSuperstring->index - aSuperstring->scrIndex,
                screen_r_address());
            screen_w(1, '*');
            screenWriteAndReturn(&(aSuperstring->str[aSuperstring->scrIndex]));
            strMoveOneRight(aSuperstring, aChar);
        }
        return NORMAL_RETURN;
    }
    return toWriteCh(aSuperstring, aChar);
}

