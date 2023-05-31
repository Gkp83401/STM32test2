#ifndef INNER_DEFINE
#define INNER_DEFINE

#define GPIOB_CRL *((volatile unsigned long*)0x40010C00)
#define GPIOB_CRH *((volatile unsigned long*)0x40010C04)
#define GPIOB_IDR *((volatile unsigned long*)0x40010C08)
#define GPIOB_ODR *((volatile unsigned long*)0x40010C0C)
#define GPIOB_BRR *((volatile unsigned long*)0x40010C14)
#define GPIOB_BSRR *((volatile unsigned long*)0x40010C10)

#define RCC_APB2ENR *((volatile unsigned long*)0x40021018)
	
#define IS_COMMAND ((unsigned char)0)
#define IS_DATA    ((unsigned char)1)
	
#define LINE_ONE_FIRST ((unsigned char)0x00)
#define LINE_TWO_FIRST ((unsigned char)0x40)
	
void delay(void);

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
void writeSomething(unsigned char pattern, unsigned char thing);

/*
	argument pattern only in value(IS_COMMAND, IS_DATA)
	let function read command or data
*/
unsigned char readSomething(unsigned char pattern);

/* if busy that result is 1 */
unsigned char isBusy(void);

/* 
	make cursor has a new position 
	position can in value(LINE_ONE_FIRST, LINE_TWO_FIRST)
	Also, you can use other correct value.
*/
void reposition(unsigned char position);

/* clear the sream */
void clear(void);

#endif
