#include "base.h"




int main()
 {
    while (1) {
        init();
        
        envLogin();
        
        if (envCLI() == TO_RESET) {
            continue;
        }
    }
}
