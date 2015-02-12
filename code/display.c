/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#include"display.h"
#include<Arduino.h>
#include<stdbool.h>
#include"shift.h"

static uint8_t bcd(const uint_fast8_t n)
{
	#if BCD_HARDWARE
	return (uint8_t)n;
	#else
	static const uint8_t pattern[]=
	{/*
		 GFEDCBA.
		---------- */
		B10000001,
		B11110011,
		B01001001,
		B01100001,
		B00110011,
		B00100101,
		B00000101,
		B11110001,
		B00000001,
		B00100001,
	};
	if(n>=sizeof pattern)return B00001101;
	return pattern[n];
	#endif	
}

extern void display_setup(void)
{
	DDRB|=B11111111;
	/* maybe do a MCLR on the registerss */
	thriftout(B00000111,B01000111,B01101111);
}

extern void display_loop(const uint_fast16_t newnumber)
{
	/*
		374 / 100 = 3
		374 % 100 = 74
		374 /  10 = 37
		374 %  10 = 4
	*/
	/* do a triple shiftout */
	thriftout(bcd(newnumber/100),bcd(newnumber/10%10),bcd(newnumber%10));
}

