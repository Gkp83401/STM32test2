#include "base.h"
#include "screen.h"

void test()
{
    unsigned char i;
    for (i = 0; i < numOfCh; i++) {
        screen_w(1, i);
    }
}
