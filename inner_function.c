#include "inner_define.h"
	
void delay(void)
{
	int i;
	for (i = 10000; i > 0; i--);
}
	
/*
	The data pin is PB0~PB7 that connect D0~D7.
	(just PB0 to D0, PB1 to D1 and so on)
	PB8  connect RS
	PB9  connect RW
	PB10 connect E
*/

/*
	argument pattern only in value(IS_COMMAND, IS_DATA)
	let function write command or data
	argument thing is the value that need to input
*/
void writeSomething(unsigned char pattern, unsigned char thing)
{
	if (pattern == IS_DATA) {
		/* E = 0, RW = 0, RS = 1 */
		// GPIOB_ODR = (GPIOB_ODR & 0xF800) | 0x0100 | thing;
        GPIOB_ODR = (GPIOB_ODR & 0xF000) | 0x0800 | thing;
	} else {
		// GPIOB_ODR = (GPIOB_ODR & 0xF800) | thing;
        GPIOB_ODR = (GPIOB_ODR & 0xF000) | thing;
	}
	/* E = 1 */
	GPIOB_BSRR = 0x0400;
	delay();
	/* E = 0 */
	GPIOB_BRR = 0x0400;
}

/*
	argument pattern only in value(IS_COMMAND, IS_DATA)
	let function read command or data
*/
unsigned char readSomething(unsigned char pattern)
{
	unsigned char a;
	while(isBusy());
	if (pattern == IS_DATA) {
		/* E = 0, RW = 1, RS = 1 */
		// GPIOB_BSRR = 0x04000300;
        GPIOB_BSRR = 0x04000A00;
	} else {
		/* E = 0, RW = 1, RS = 0 */
		// GPIOB_BSRR = 0x05000200;
        GPIOB_BSRR = 0x0C000200;
	}
	/* E = 1 */
	GPIOB_BSRR = 0x0400;
	GPIOB_CRL = 0x44444444;
	delay();
	a = GPIOB_IDR;
	GPIOB_CRL = 0x33333333;
	/* E = 0 */
	GPIOB_BRR = 0x0400;
	return a;
}

/* if busy that result is 1 */
unsigned char isBusy(void)
{
	if ((readSomething(IS_COMMAND) & 0x80) == 0)
		return (unsigned char)0;
	else
		return (unsigned char)1;
}

/* 
	make cursor has a new position 
	position can in value(LINE_ONE_FIRST, LINE_TWO_FIRST)
	Also, you can use other correct value.
*/
void reposition(unsigned char position)
{
	writeSomething(IS_COMMAND, 0x80 + position);
}

/* clear the sream */
void clear()
{
	writeSomething(IS_COMMAND, 0x01);
}
