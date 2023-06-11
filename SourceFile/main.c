#include "base.h"

int main()
 {
    while (1) {
        init();
        /*
        if (envLogin() == TO_RESET) {
            continue;
        }
        
        if (envCLI() == TO_RESET) {
            continue;
        }
        */
        envEditor();
    }
}
