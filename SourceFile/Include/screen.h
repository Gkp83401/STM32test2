#ifndef SCREEN_H
#define SCREEN_H

// ��GPIOB����Ļ�����ַ�
#define GPIOB_CRL   *((volatile unsigned long*)0x40010C00)
#define GPIOB_CRH   *((volatile unsigned long*)0x40010C04)
#define GPIOB_IDR   *((volatile unsigned long*)0x40010C08)
#define GPIOB_ODR   *((volatile unsigned long*)0x40010C0C)
#define GPIOB_BRR   *((volatile unsigned long*)0x40010C14)
#define GPIOB_BSRR  *((volatile unsigned long*)0x40010C10)

// ����ַ�������������Զ�����ַ�
// ����ÿ8��char������������һ���ַ�
// Ҫȥscreen.h�ĳ��� 
extern unsigned char myChar[8][8];

// ��д��ģʽ��һ��˵��

// �� rs = 1 �������Ӧλ��д�����ݣ�������λ�ã��Զ����ַ�λ��
// ����ʾ��Ļλ�ã���ֻ��Ҫ�����ߣ�ǰ�ߵĲ����������
// initMyChar()��װ�����ˡ�

// �� rs = 0 ����Ļ��ʾ��������
// ���     D7      D6      D5      D4      D3      D2      D1      D0
// 1        0       0       0       0       0       0       0       1       ����
// 2        0       0       0       0       0       0       1       x       ��귵��
// 3        0       0       0       0       0       1       I/D     S       ��ʾ����
// 4        0       0       0       0       1       D       C       S       ��ʾ������
// 5        0       0       0       1       S/C     R/L     x       x       ���������λ
// 6        0       0       1       DL      N       F       x       x       һЩ��ֵ�����
// 7        0       1       (      �ַ����ַ 0x00 - 0x1F            )       ���ȥ���ַ���
// 8        1       (       ��ʾ��ַ ��1��0x00��ʼ ��2��0x40��ʼ      )       ���ȥ����ʾλ
//
// 3    I/D д���ַ������1���1 1(INC, ��1) 0 (DES, ��1)       S ����д����ƶ�,�ƶ�������I/D���� (INC ����) (DES ����)
//      �ڳ���������Ϊ0x06
// 4    D ��Ļ�Ƿ���ʾ�� 1(��ʾ)     C ������� 1(��)     B �����˸ 1(��)  (��ֵ�����������������)
//      �����д󲿷�ʱ���� 0x0F
// 5
void screen_w(unsigned char rs, unsigned char d_0_to_7);

unsigned char screen_r(unsigned char rs);

unsigned char screen_r_busy(void);

unsigned char screen_r_address(void);

void my_printf(char *string);

void initMyChar(void); 

void clearAString(unsigned int length, unsigned int position);

void screenWriteAndReturn(char *str);

#endif
