/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#include"shift.h"
#include<Arduino.h>

/**
 * ShiftOut function for three registers at once
 */
extern void thriftout(const uint8_t data1, const uint8_t data2, const uint8_t data3)
{
	auto uint_fast8_t i= (uint_fast8_t)8;
	/* clock low and unlock latch */
	PORTB&=B11111100;
	for(;i!=0;--i)
	{
		/* line up the data with the pins */
		const uint8_t mask=(uint8_t)(0|
			((((data1& (0x01U<<(i-1)) )!=0))<<5)|
			((((data2& (0x01U<<(i-1)) )!=0))<<4)|
			((((data3& (0x01U<<(i-1)) )!=0))<<3));
		/* set the high bits */
		PORTB|=mask;
		/* set the low bits */
		PORTB&=mask|B11000111;
		/* clock edge */
		PORTB|=B00000100;
		/* clock edge */
		PORTB&=B11111011;
	}
	/* lock latch */
	PORTB|=B00000001;
}

