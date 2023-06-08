#include "base.h"

unsigned char strCmp(char *mode)
{
    unsigned char i;
    char ch;
    for (i = 0; i < isWhere; i++) {
        if (strOnCaps[i])
            ch = transform2[i];
        else
            ch = transform1[i];
        if (mode[i] != ch)
            return 0;
    }
    if (mode[i] == 0)
        return 1;
    return 0;
}
