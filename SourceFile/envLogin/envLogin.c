#include "envLogin.h"

#include "screen.h"
#include "keyboard.h"
#include "string.h"
#include "readAndWrite.h"
#include "superstring.h"
#include "speSignal.h"


unsigned char envLogin(envLoginOutImformation *aEnvLoginOutImformationPoint)
{
    // ���������û���
    superstring user = {"", 0, 0};
    // ������������
    superstring passwd = {"", 0, 0};
    
    while(1) {
        // ����
        screen_w(0, 0x01);
        // ����Ļ����"user:"
        // Ȼ��س���������"passwd:"
        my_printf("user:\npasswd:");
        
        // ��ʱ���������2��"passwd"�ĺ���
        
        // ʹ���ȥ����1��"user:"����
        screen_w(0, 0x80 + 0x05);
        
        // ����settleOneLine������������浽user��
        // �����������ֵ����TO_RESET��������������
        // ����������������return������ǰ������
        // Ȼ��ȥ��main�����ó�����������
        if (settleOneLine(&user) == TO_RESET)
            return TO_RESET;
        
        // ʹ���ȥ����2��"passwd:"�ĺ���
        screen_w(0, 0x80 + 0x40 + 0x07);
        
        // ����settleOneLine������������浽passwd��
        if (settleOneLinePasswd(&passwd) == TO_RESET)
            return TO_RESET;
        
        // �ж�user��passwd�������ȷ���
        // �����ȷ��return������ȷ�ź�
        // �������ȷwhile(1����ʹ���ͷ��ʼִ��
        if (strCmpNoIndex(user.str, "abc") && strCmpNoIndex(passwd.str, "123")) {
            return NORMAL_RETURN;
        }
    }
}


