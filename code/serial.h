/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#ifndef SERIAL_H
#define SERIAL_H

#include<stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	/** setup the program to use serial communication */
	extern void serial_setup(void);
	/**  poll for data */
	extern void serial_loop(void);
	/** */
	extern uint16_t get_code(void);

#ifdef __cplusplus
}
#endif

#endif

