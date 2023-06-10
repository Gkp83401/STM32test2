#include "string.h"

unsigned char strCmpOneIndex(unsigned char index, char *strInd, char *strZeroOrInd)
{
    unsigned int i;
    for (i = 0; i < index; i++) {
        if (strZeroOrInd[i] != strInd[i])
            return IS_NOT_SAME;
    }
    return IS_SAME;
}

unsigned char strCmp2(char *ch1, char *ch2)
{
    unsigned int i = 0;
    while(ch1[i] == ch2[i]) {
        if (ch1[i] == 0) {
            return IS_SAME;
        }
        i++;
    }
    return IS_NOT_SAME;
}
