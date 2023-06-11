#include "readAndWrite.h"
#include "keyboard.h"

// ��һ��ģʽ�¶�ȡ��д��
unsigned char settleOneLine(superstring *aSuperstring)
{
    unsigned char signal;
    char getCh;
    getCh = 0;
    while (1) {
        getCh = toGetKey(getCh);
        signal = toWriteChOneLine(aSuperstring, getCh);
        if (signal == TO_RESET) {
            return TO_RESET;
        }
        if (signal == FINISH_INPUT) {
            return NORMAL_RETURN;
        }
    }
}

unsigned char settleOneLinePasswd(superstring *aSuperstring)
{
    unsigned char signal;
    char getCh;
    getCh = 0;
    while (1) {
        getCh = toGetKey(getCh);
        signal = toWriteChOneLinePasswd(aSuperstring, getCh);
        if (signal == TO_RESET) {
            return TO_RESET;
        }
        if (signal == FINISH_INPUT) {
            return NORMAL_RETURN;
        }
    }
}

