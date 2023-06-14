#include "envLogin.h"

#include "screen.h"
#include "keyboard.h"
#include "string.h"
#include "readAndWrite.h"
#include "superstring.h"
#include "speSignal.h"


unsigned char envLogin(envLoginOutImformation *aEnvLoginOutImformationPoint)
{
    // 存放输入的用户名
    superstring user = {"", 0, 0};
    // 存放输入的密码
    superstring passwd = {"", 0, 0};
    
    while(1) {
        // 清屏
        screen_w(0, 0x01);
        // 向屏幕输入"user:"
        // 然后回车接着输入"passwd:"
        my_printf("user:\npasswd:");
        
        // 这时光标来到第2行"passwd"的后面
        
        // 使光标去到第1行"user:"后面
        screen_w(0, 0x80 + 0x05);
        
        // 调用settleOneLine函数来将输入存到user中
        // 如果函数返回值等于TO_RESET代表按下了重启键
        // 所以条件成立会用return结束当前函数，
        // 然后去到main函数让程序重新运行
        if (settleOneLine(&user) == TO_RESET)
            return TO_RESET;
        
        // 使光标去到第2行"passwd:"的后面
        screen_w(0, 0x80 + 0x40 + 0x07);
        
        // 调用settleOneLine函数来将输入存到passwd中
        if (settleOneLinePasswd(&passwd) == TO_RESET)
            return TO_RESET;
        
        // 判断user和passwd输入的正确与否
        // 如果正确用return返回正确信号
        // 如果不正确while(1）会使其从头开始执行
        if (strCmpNoIndex(user.str, "abc") && strCmpNoIndex(passwd.str, "123")) {
            return NORMAL_RETURN;
        }
    }
}


