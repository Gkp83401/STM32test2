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

void strCopy(char *sourceStr, char *targetStr)
{
    int i;
    
    i = 0;
    while (sourceStr[i] != 0) {
        targetStr[i] = sourceStr[i];
        i++;
    }
    targetStr[i] = 0;
    
    return;
}

int strLength(char *str)
{
    int i;
    i = 0;
    while (str[i] != 0) {
        i++;
    }
    return i;
}

int strFindPlusAndCal(char *str, int *calResult, int *aO, int *bO)
{
    int i;
    int a;
    int b;
    
    i = 0;
    while (1) {
        if (str[i] == '+') {
            str[i] = 0;
            a = strToNum(str);
            b = strToNum(&(str[i+1]));
            *calResult = a + b;
            *aO = a;
            *bO = b;
            return 1;
        }
        if (str[i] == 0) {
            return 0;
        }
        i++;
    }
}

int strFindJianAndCal(char *str, int *calResult, int *aO, int *bO)
{
    int i;
    int a;
    int b;
    
    i = 0;
    while (1) {
        if (str[i] == '-') {
            str[i] = 0;
            a = strToNum(str);
            b = strToNum(&(str[i+1]));
            *aO = a;
            *bO = b;
            *calResult = a - b;
            return 1;
        }
        if (str[i] == 0) {
            return 0;
        }
        i++;
    }
}

int strFindChengAndCal(char *str, int *calResult, int *aO, int *bO)
{
    int i;
    int a;
    int b;
    
    i = 0;
    while (1) {
        if (str[i] == '*') {
            str[i] = 0;
            a = strToNum(str);
            b = strToNum(&(str[i+1]));
            *calResult = a * b;
            *aO = a;
            *bO = b;
            return 1;
        }
        if (str[i] == 0) {
            return 0;
        }
        i++;
    }
}

int strFindChuAndCal(char *str, int *calResult, int *aO, int *bO)
{
    int i;
    int a;
    int b;
    
    i = 0;
    while (1) {
        if (str[i] == '/') {
            str[i] = 0;
            a = strToNum(str);
            b = strToNum(&(str[i+1]));
            *aO = a;
            *bO = b;
            *calResult = a / b;
            return 1;
        }
        if (str[i] == 0) {
            return 0;
        }
        i++;
    }
}

int strFindPingAndCal(char *str, int *calResult, int *aO, int *bO)
{
    int i;
    int j;
    int a;
    int b;
    int d;
    
    i = 0;
    while (1) {
        if (str[i] == '^') {
            str[i] = 0;
            a = strToNum(str);
            b = strToNum(&(str[i+1]));
            d = 1;
            for (j = 0; j < b; j++) {
                d *= a;
            }
            *calResult = d;
            *aO = a;
            *bO = b;
            return 1;
        }
        if (str[i] == 0) {
            return 0;
        }
        i++;
    }
}

int strToNum(char *str)
{
    int length = strLength(str);
    int i;
    int j;
    int j0;
    int num;
    int out = 0;
    i = length - 1;
    j = 0;
    for (; i >=0; i--) {
        num = str[i] - 0x30;
        for (j0 = 0; j0 < j; j0++) {
            num *= 10;
        }
        out += num;
        j++;
    }
    return out;
}

void numToStr(int num, char *str)
{
    int length;
    int i;
    int j;
    int d;
    int dR;
    
    length = 0;
    while (1) {
        dR = 1;
        for (d = 0; d < length; d++) {
            dR *= 10;
        }
        if (num / dR == 0) {
            break;
        }
        length++;
    }
    
    j = 0;
    for (i = length - 1; i >= 0; i--) {
        
        dR = 1;
        for (d = 0; d < i; d++) {
            dR *= 10;
        }
        
        str[j] = num / dR + 0x30;
        num -= (num / dR) * dR;
        
        j++;
    }
    str[j] = 0;
}
