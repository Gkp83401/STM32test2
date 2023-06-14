#include "envCLI.h"
#include "screen.h"
#include "keyboard.h"
#include "string.h"
#include "readAndWrite.h"
#include "superstring.h"
#include "speSignal.h"


unsigned char envCLI(envLoginOutImformation *aEnvLoginOutImformationPoint)
{
    // ��Ż�ȡ����һ������
    superstring command;
    // ���ڴ�ż�����
    int calResult;
    int a;
    int b;
    // ��Ű�����ת��Ϊ���ַ���
    char string[20];
    
    // ����
    screen_w(0, 0x01);
    // ��ʾ��ʾ��
    my_printf("$ ");
    
    while (1) {
        // ��command���г�ʼ��
        command.str[0] = 0;
        command.index = 0;
        command.scrIndex = 0;
        
        // �ж��Ƿ���ڸ�λ����
        if (settleOneLine(&command) == TO_RESET)
            return TO_RESET;
        
        // �Ƿ�Ϊ����right
        if (strCmpNoIndex(command.str, "right")) {
            screen_w(0, 0x01);
            my_printf("$ \nright");
            screen_w(0, 0x80 + 0x02);
        } else if (strCmpNoIndex(command.str, "fan on")) {
            screen_w(0, 0x01);
            my_printf("$ \nfan on");
            GPIOB_BSRR = 1 << 14;
            screen_w(0, 0x80 + 0x02);
        } else if (strCmpNoIndex(command.str, "fan off")) {
            screen_w(0, 0x01);
            my_printf("$ \nfan off");
            GPIOB_BRR = 1 << 14;
            screen_w(0, 0x80 + 0x02);
        } else if (strCmpNoIndex(command.str, "buzzer on")) {
            screen_w(0, 0x01);
            my_printf("$ \nbuzzer on");
            GPIOB_BSRR = 1 << 8;
            screen_w(0, 0x80 + 0x02);
        } else if (strCmpNoIndex(command.str, "buzzer off")) {
            screen_w(0, 0x01);
            my_printf("$ \nbuzzer off");
            GPIOB_BRR = 1 << 8;
            screen_w(0, 0x80 + 0x02);
        } else if (strCmpNoIndex(command.str, "plus")) {
            screen_w(0, 0x01);      // �Ƿ�Ϊ����plus
            my_printf("$ \n character: +");
            screen_w(0, 0x80 + 0x02);
        } else if (strCmpNoIndex(command.str, "emoji")) {
            screen_w(0, 0x01);      // �Ƿ�Ϊ����emoji
            my_printf("$ \n character: ");
            screen_w(1, 0xEF);
            screen_w(0, 0x80 + 0x02);
        } else if (strFindPlusAndCal(command.str, &calResult, &a, &b)) {
            screen_w(0, 0x01);      // �Ƿ�Ϊ�ӷ�����
            my_printf("$ \n");
            numToStr(a, string);
            my_printf(string);
            my_printf(" + ");
            numToStr(b, string);
            my_printf(string);
            my_printf(" = ");
            numToStr(calResult, string);
            my_printf(string);
            screen_w(0, 0x80 + 0x02);
        } else if (strFindJianAndCal(command.str, &calResult, &a, &b)) {
            screen_w(0, 0x01);      // �Ƿ�Ϊ��������
            my_printf("$ \n");
            numToStr(a, string);
            my_printf(string);
            my_printf(" - ");
            numToStr(b, string);
            my_printf(string);
            my_printf(" = ");
            numToStr(calResult, string);
            my_printf(string);
            screen_w(0, 0x80 + 0x02);
        } else if (strFindChengAndCal(command.str, &calResult, &a, &b)) {
            screen_w(0, 0x01);      // �Ƿ�Ϊ�˷�����
            my_printf("$ \n");
            numToStr(a, string);
            my_printf(string);
            my_printf(" * ");
            numToStr(b, string);
            my_printf(string);
            my_printf(" = ");
            numToStr(calResult, string);
            my_printf(string);
            screen_w(0, 0x80 + 0x02);
        } else if (strFindChuAndCal(command.str, &calResult, &a, &b)) {
            screen_w(0, 0x01);      // �Ƿ�Ϊ��������
            my_printf("$ \n");
            numToStr(a, string);
            my_printf(string);
            my_printf(" / ");
            numToStr(b, string);
            my_printf(string);
            my_printf(" = ");
            numToStr(calResult, string);
            my_printf(string);
            screen_w(0, 0x80 + 0x02);
        } else if (strFindPingAndCal(command.str, &calResult, &a, &b)) {
            screen_w(0, 0x01);      // �Ƿ�Ϊ�η�����
            my_printf("$ \n");
            numToStr(a, string);
            my_printf(string);
            my_printf(" ^ ");
            numToStr(b, string);
            my_printf(string);
            my_printf(" = ");
            numToStr(calResult, string);
            my_printf(string);
            screen_w(0, 0x80 + 0x02);
        } else{
            screen_w(0, 0x01);
            my_printf("$ \nerror");
            screen_w(0, 0x80 + 0x02);
        }
    }
}
