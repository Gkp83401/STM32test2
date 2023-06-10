#include "keyboard.h"
#include "delay.h"

// ����2�����������������ϻ�ȡ��������ת�ɶ�Ӧ���ַ�
// @������԰������ַ��ϳ�һ��
// @����Ļس�֮���ֵ���Դ�0���\n֮���
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

// �����жϰ����Ƿ��ظ�����
unsigned char pressAgain;

char toGetKey(char preChar)
{
    unsigned int used;
    char getChar;
    
    // ����ʶ��ʱ��
    if (pressAgain)
        ddd(15);
    else
        ddd(20);
    
    used = (GPIOC_IDR & 0xFF);
    if (used & 0x80) {
        if (used & 0x40) {
            getChar = transform2[used&0x3F];
        } else {
            getChar = transform1[used&0x3F];
        }
        
        // �жϲ����ַ����Ŀ�ͷ���Һ���һ���ַ���ͬ
        if (preChar !=0 && preChar == getChar) {
            // �ǵ�һ���ַ���ͬ
            // ����ѡ���ӳٲ�����û�л�ȡ�������˳�
            if (pressAgain == NO_PRESS_AGAIN) {
                ddd(20);
                return 0;
            }
            // ֮ǰ�Ѿ����ַ���ͬ��Ȼ���ٴ���ͬ
            pressAgain = HAVE_PRESS_AGAIN;
        } else {
            pressAgain = NO_PRESS_AGAIN;
        }
        
        return getChar;
    }
    // û�л�ȡ������
    return 0;
}