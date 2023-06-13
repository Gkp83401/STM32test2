#ifndef STRING_H
#define STRING_H

#include "superstring.h"

// 比较的两个字符串的函数返回结果
#define IS_SAME         1
#define IS_NOT_SAME     0

// 字符串分为两种
// 一种是用结尾为0来标记结束
// 另一种是用一个值来表示字符长度

// 比较两个字符串
// 相同返回 IS_SAME
// 不相同返回 IS_NOT_SAME
// 参与比较的一个0结尾、一个长度标识 或 两个长度标识
unsigned char strCmpOneIndex(unsigned char index, char *strInd, char *strZeroOrInd);
// 参与比较的两个0结尾
unsigned char strCmpNoIndex(char *str1, char *str2);

void strMoveOneLeft(superstring *aSuperstring);

void strMoveOneRight(superstring *aSuperstring, char aChar);

void strCopy(char *sourceStr, char *targetStr);

/*

void strCopyInd(char *indSourceStr, char *target);

void strCat(char *headStr, char addStr);

unsigned int strCatInd(char *headStr, unsigned int index, char *addStr);
*/

int strLength(char *str);

#endif
