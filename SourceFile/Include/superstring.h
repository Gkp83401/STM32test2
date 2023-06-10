#ifndef SUPERSTRING_H
#define SUPERSTRING_H

typedef struct
{
    char str[50];
    unsigned int index;
    unsigned int scrIndex;
} superstring;

unsigned char toWriteCh(superstring *aSuperstring, char aChar);

#endif