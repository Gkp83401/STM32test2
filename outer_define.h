#ifndef OUTER_DEFINE
#define OUTER_DEFINE

#define HAVE_CURSOR ((unsigned char)0)
#define NO_CURSOR   ((unsigned char)1)

/*
	This function must use before 
	using my_printf(char a[]) or my_putchar(char a).
	
	one argument,
	only in value(HAVE_CURSOR, NO_CURSOR)
	make the screem have or not have cursor
*/
void init(unsigned char a);

/*
	display a string
*/
void my_printf(char a[]);
/*
	display one character
*/
void my_putchar(char a);

#endif
