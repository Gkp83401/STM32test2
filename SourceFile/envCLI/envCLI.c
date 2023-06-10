#include "envCLI.h"
#include "screen.h"


unsigned char envCLI()
{
    // ��ʾÿ�λس�ǰ������ʲô�ַ���
    unsigned char isWhere;
    char strOn[30];
    
    getKey aGetKey;
    screen_w(0, 0x01);
    my_printf("$ ");
    
    // ÿ��ѭ������ʼ�µİ���
    while(1)
    {
        toGetKey(&aGetKey);
        
        
        if (aGetKey.gs) {
            
            // �������
            if (aGetKey.caps) {
                strOn[isWhere] = transform2[aGetKey.c];
            }
            else {
                strOn[isWhere] = transform1[aGetKey.c];
            }
            isWhere++;
            strOn[isWhere] = 0;
            
            // �����ַ�
            // ����
            if (aGetKey.c == 0x1F && !(aGetKey.caps)) {
                return TO_RESET;
            }
            if (aGetKey.c == 0x25) {
                if (aGetKey.caps) { // �˸�
                    if (isWhere != 0) {
                        isWhere--;
                        screen_w(0, 0x10);
                        screen_w(1, ' ');
                        screen_w(0, 0x10);
                    }
                } else {            // �س�
                    if (strCmp("right"))
                        isRight();
                    else
                        isError();
                    screen_w(0, 0x80);
                    my_printf("                               ");
                    screen_w(0, 0x02);
                    my_printf("$ ");
                    
                    isWhere = 0;
                }
                
            }
            
        }
    }
}
