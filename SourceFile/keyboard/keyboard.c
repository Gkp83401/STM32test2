#include "keyboard.h"
#include "delay.h"

// �����жϰ����Ƿ��ظ�����
// ����ΪNO_PRESS_AGAIN��HAVE_PRESS_AGAIN
unsigned char pressAgain = 0;

unsigned int noInput = 0;

char toGetKey(char preChar)
{
    unsigned int used;
    char getChar;
    
    // ����ʶ��ʱ��
    if (pressAgain == HAVE_PRESS_AGAIN)
        ddd(5);
    else
        ddd(20);
    
    used = (GPIOC_IDR & 0xFF);
    if (used & 0x80) {
        
        ddd(1);
        if (used != (GPIOC_IDR & 0xFF))
            return NO_GETCHAR;
        ddd(1);
        if (used != (GPIOC_IDR & 0xFF))
            return NO_GETCHAR;
        
        noInput = 0;
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
                return NO_GETCHAR;
            }
            // ֮ǰ�Ѿ����ַ���ͬ��Ȼ���ٴ���ͬ
            pressAgain = HAVE_PRESS_AGAIN;
        } else {
            
            pressAgain = NO_PRESS_AGAIN;
        }
        
        return getChar;
    }
    // û�л�ȡ������
    if (noInput == 300)
        pressAgain = NO_PRESS_AGAIN;
    else
        noInput++;
    return NO_GETCHAR;
}
