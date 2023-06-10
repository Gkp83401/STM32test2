#include "base.h"

unsigned char strCmp(char *mode)
{
    unsigned char i;
    char ch;
    for (i = 0; i < isWhere; i++) {
        if (strOnCaps[i])
            ch = transform2[strOn[i]];
        else
            ch = transform1[strOn[i]];
        if (mode[i] != ch)
            return 0;
    }
    if (mode[i] == 0)
        return 1;
    return 0;
}

unsigned char strCmp2(char *ch1, char *ch2)
{
    unsigned char i = 0;
    unsigned char result = 0; // is unsucced
    while(ch1[i] == ch2[i]) {
        if (ch1[i] == 0) {
            result = 1;
            break;
        }
        i++;
    }
    return result;
}
