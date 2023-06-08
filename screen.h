#ifndef SCREEN_H
#define SCREEN_H

void screen_w(unsigned char rs, unsigned char d_0_to_7);

unsigned char screen_r(unsigned char rs);

void my_printf(char *string);

void initMyChar(void);

void isRight(void);

#endif
