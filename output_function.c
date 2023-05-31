#include "outer_define.h"
#include "inner_define.h"

/*
	one argument,
	only in value(HAVE_CURSOR, NO_CURSOR)
	make the screem have or not have cursor
*/
void init(unsigned char a)
{
	/* The 0x00 is setting have or not have cursor */
	unsigned char initCommands[] = {0x38, 0x00, 0x06, 0x01};
	unsigned char initCommandsLength = 
		sizeof(initCommands) / sizeof(unsigned char);
	unsigned char i;
	RCC_APB2ENR |= 1 << 3;
	GPIOB_CRL = 0x33333333;
	GPIOB_CRH = 0x33333333;
	for (i = 0; i < initCommandsLength; i++) {
		if (initCommands[i] == 0) {
			if (a == HAVE_CURSOR) {
				initCommands[i] = 0x0F;
			} else {
				initCommands[i] = 0x0C;
			}
		}
		/* 
			The expression (GPIOB & 0xF800) makes 
			RS = 0, RW = 0, E= 0, data pin = 0x00 
		*/
		/* 
			The operator | makes data pin equal to 
			initial command value 
		*/
		/* GPIOB_ODR = (GPIOB_ODR & 0xF800) | initCommands[i]; */
		/* E = 1 */
		/* GPIOB_BSRR = 0x0400; */
		/* delay(); */
		/* E = 0 */
		/* GPIOB_BRR = 0x0400; */
		writeSomething(IS_COMMAND, initCommands[i]);
	}
	delay();
}

void my_putchar(char a)
{
	unsigned int i;
	/* E = 0, RW = 0, RS = 1 */
	/* GPIOB_ODR = (GPIOB_ODR & 0xF800) | 0x0100 | 
	(unsigned char)a; */
	/* E = 1 */
	/* GPIOB_BSRR = 0x0400; */
	/* delay(); */
	/* E = 0 */
	/* GPIOB_BRR = 0x0400; */
	writeSomething(IS_DATA, (unsigned char)a);
	// for (i = 40; i > 0; i--)
	//  	delay();
	return;
}

void my_printf(char a[])
{
	unsigned char i = 0;
	while (a[i] != 0) {
		if (a[i] == '\n') {
			reposition(LINE_TWO_FIRST);
			i++;
			continue;
		}
		my_putchar(a[i]);
		i++;
	}
	return;
}
