#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "keyValue.h"

// ��GPIOC��ȡ���̵�����
#define GPIOC_CRL   *((volatile unsigned long*)0x40011000)
#define GPIOC_CRH   *((volatile unsigned long*)0x40011004)
#define GPIOC_IDR   *((volatile unsigned long*)0x40011008)
#define GPIOC_ODR   *((volatile unsigned long*)0x4001100C)
#define GPIOC_BRR   *((volatile unsigned long*)0x40011014)
#define GPIOC_BSRR  *((volatile unsigned long*)0x40011010)


#define NO_GETCHAR 0

#define NO_PRESS_AGAIN      0
#define HAVE_PRESS_AGAIN    1

// ����2�����������������ϻ�ȡ��������ת�ɶ�Ӧ���ַ�
// Сд�ַ�
const char transform1[41] = 
{
    '1', '2', 'q', 'w', 'a', 's', 'z', 'x',
    '3', '4', 'e', 'r', 'd', 'f', 'c', 'v',
    '5', '6', 't', 'y', 'g', 'h', 'b', 'n',
    '7', '8', 'u', 'i', 'j', 'k', 'm', keyESC,
    '9', '0', 'o', 'p', 'l', keyLF, keyUP, keyDOWN,
    keyUNUSE1
};
// ��д�ַ�
const char transform2[41] = 
{
    '!', '@', 'Q', 'W', 'A', 'S', 'Z', 'X',
    '#', '$', 'E', 'R', 'D', 'F', 'C', 'V',
    '%', '^', 'T', 'Y', 'G', 'H', 'B', 'N',
    '&', '*', 'U', 'I', 'J', 'K', 'M', ' ',
    '(', ')', 'O', 'P', 'L', keyBS, keyLEFT, keyRIGHT,
    keyUNUSE2
};

// ��ȡһ���ַ�
// ����NO_GETCHAR����û�л�ȡ���ַ�
char toGetKey(char preChar);

#endif
