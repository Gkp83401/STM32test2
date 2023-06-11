#include "envLogin.h"
#include "screen.h"
#include "keyboard.h"
#include "string.h"
#include "readAndWrite.h"
#include "superstring.h"
#include "speSignal.h"

unsigned char envLogin()
{
    superstring user = {"", 0, 0};
    superstring passwd = {"", 0, 0};
    
    while(1) {
        screen_w(0, 0x01);
        my_printf("user:\npasswd:");
        
        screen_w(0, 0x80 + 0x05);
        
        if (settleOneLine(&user) == TO_RESET)
            return TO_RESET;
        
        screen_w(0, 0x80 + 0x40 + 0x07);
        
        if (settleOneLinePasswd(&passwd) == TO_RESET)
            return TO_RESET;
            
        if (strCmpNoIndex(user.str, "abc") && strCmpNoIndex(passwd.str, "123")) {
            return NORMAL_RETURN;
        }
    }
}


