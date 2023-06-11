#include "string.h"

unsigned char strCmpOneIndex(unsigned char index, char *strInd, char *strZeroOrInd)
{
    int i;
    for (i = 0; i < index; i++) {
        if (strZeroOrInd[i] != strInd[i])
            return IS_NOT_SAME;
    }
    return IS_SAME;
}

unsigned char strCmpNoIndex(char *ch1, char *ch2)
{
    int i = 0;
    while(ch1[i] == ch2[i]) {
        if (ch1[i] == 0) {
            return IS_SAME;
        }
        i++;
    }
    return IS_NOT_SAME;
}

void strMoveOneLeft(superstring *aSuperstring)
{
    int i;
    if (aSuperstring->scrIndex == 0)
        return;
    i = aSuperstring->scrIndex;
    while (aSuperstring->str[i-1]) {
        aSuperstring->str[i-1] = aSuperstring->str[i];
        i++;
    }
    (aSuperstring->scrIndex)--;
    (aSuperstring->index)--;
    return;
}

void strMoveOneRight(superstring *aSuperstring, char aChar)
{
    int i;
    for (i = aSuperstring->index; i >= (int)aSuperstring->scrIndex; i--) {
        aSuperstring->str[i+1] = aSuperstring->str[i];
    }
    aSuperstring->str[aSuperstring->scrIndex] = aChar;
    (aSuperstring->scrIndex)++;
    (aSuperstring->index)++;
    return;
}
