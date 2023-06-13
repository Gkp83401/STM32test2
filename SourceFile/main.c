#include "base.h"

int main()
 {
    while (1) {
        envLoginOutImformation *aEnvLoginOutImformationPoint;
        
        init();
        
        // envCartoon();
        
        
        if (envLogin(aEnvLoginOutImformationPoint) == TO_RESET) {
            continue;
        }
        
        if (envCLI(aEnvLoginOutImformationPoint) == TO_RESET) {
            continue;
        }
        envEditor();
    }
}
