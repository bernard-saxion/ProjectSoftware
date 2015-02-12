/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#include"serial.h"
#include<Arduino.h>
#include<EEPROM.h>

/** setup the program to use serial communication */
extern void serial_setup(void)
{
	Serial.begin(9600);
}

/**  poll for data */
extern void serial_loop(void)
{
	if(Serial.available())
	{
		int n = Serial.parseInt();
		if(n>0&&n<999)
		{
			EEPROM.write(1,n);
		}
	}
}


extern uint16_t get_code(void)
{
	return EEPROM.read(1);
}
