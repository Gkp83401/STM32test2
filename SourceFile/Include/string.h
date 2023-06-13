#ifndef STRING_H
#define STRING_H

#include "superstring.h"

// �Ƚϵ������ַ����ĺ������ؽ��
#define IS_SAME         1
#define IS_NOT_SAME     0

// �ַ�����Ϊ����
// һ�����ý�βΪ0����ǽ���
// ��һ������һ��ֵ����ʾ�ַ�����

// �Ƚ������ַ���
// ��ͬ���� IS_SAME
// ����ͬ���� IS_NOT_SAME
// ����Ƚϵ�һ��0��β��һ�����ȱ�ʶ �� �������ȱ�ʶ
unsigned char strCmpOneIndex(unsigned char index, char *strInd, char *strZeroOrInd);
// ����Ƚϵ�����0��β
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

int strFindPlusAndCal(char *str, int *calResult);

int strFindJianAndCal(char *str, int *calResult);

int strFindChengAndCal(char *str, int *calResult);

int strFindChuAndCal(char *str, int *calResult);

int strFindPingAndCal(char *str, int *calResult);

int strToNum(char *str);

void numToStr(int num, char *str);

#endif
