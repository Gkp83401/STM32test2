#include "envCLI.h"
#include "screen.h"
#include "keyboard.h"
#include "string.h"
#include "readAndWrite.h"
#include "superstring.h"
#include "speSignal.h"


unsigned char envCLI()
{
    superstring command;
    screen_w(0, 0x01);
    my_printf("$ ");
    
    while (1) {
        command.str[0] = 0;
        command.index = 0;
        command.scrIndex = 0;
        
        if (settleOneLine(&command) == TO_RESET)
            return TO_RESET;
        
        if (strCmpNoIndex(command.str, "right")) {
            screen_w(0, 0x01);
            my_printf("$ \nright");
            screen_w(0, 0x80 + 0x02);
        } else {
            screen_w(0, 0x01);
            my_printf("$ \nerror");
            screen_w(0, 0x80 + 0x02);
        }
    }
}
