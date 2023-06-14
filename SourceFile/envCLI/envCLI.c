#include "envCLI.h"
#include "screen.h"
#include "keyboard.h"
#include "string.h"
#include "readAndWrite.h"
#include "superstring.h"
#include "speSignal.h"


unsigned char envCLI(envLoginOutImformation *aEnvLoginOutImformationPoint)
{
    // 存放获取到的一行命令
    superstring command;
    // 用于存放计算结果
    int calResult;
    int a;
    int b;
    // 存放把数字转化为的字符串
    char string[20];
    
    // 清屏
    screen_w(0, 0x01);
    // 显示提示符
    my_printf("$ ");
    
    while (1) {
        // 对command进行初始化
        command.str[0] = 0;
        command.index = 0;
        command.scrIndex = 0;
        
        // 判断是否存在复位按键
        if (settleOneLine(&command) == TO_RESET)
            return TO_RESET;
        
        // 是否为命令right
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
            screen_w(0, 0x01);      // 是否为命令plus
            my_printf("$ \n character: +");
            screen_w(0, 0x80 + 0x02);
        } else if (strCmpNoIndex(command.str, "emoji")) {
            screen_w(0, 0x01);      // 是否为命令emoji
            my_printf("$ \n character: ");
            screen_w(1, 0xEF);
            screen_w(0, 0x80 + 0x02);
        } else if (strFindPlusAndCal(command.str, &calResult, &a, &b)) {
            screen_w(0, 0x01);      // 是否为加法运算
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
            screen_w(0, 0x01);      // 是否为减法运算
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
            screen_w(0, 0x01);      // 是否为乘法运算
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
            screen_w(0, 0x01);      // 是否为除法运算
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
            screen_w(0, 0x01);      // 是否为次方运算
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
