/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#ifndef DISPLAY_H
#define DISPLAY_H
#include<stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	/** sets up all the hardware needed for the displays to work */
	extern void display_setup(void);
	/** puts something new on the display */
	extern void display_loop(const uint_fast16_t);

#ifdef __cplusplus
}
#endif

#endif

