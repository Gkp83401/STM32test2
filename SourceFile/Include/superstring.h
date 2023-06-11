#ifndef SUPERSTRING_H
#define SUPERSTRING_H

#include "speSignal.h"

typedef struct
{
    char str[50];
    unsigned int index;
    unsigned int scrIndex;
} superstring;

unsigned char toWriteCh(superstring *aSuperstring, char aChar);

unsigned char toWriteChOneLine(superstring *aSuperstring, char aChar);

unsigned char toWriteChOneLinePasswd(superstring *aSuperstring, char aChar);


#endif
