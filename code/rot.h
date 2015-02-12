/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#ifndef ROT_H
#define ROT_H

#include<stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	/** setup all the pins for the rotary encoder */
	extern void rot_setup(void);
	/** update rotary encoder's value */
	extern void rot_loop(void);
	/** get the number that the rotary encoder  found */
	extern uint_fast16_t get_number(void);
	/** resets the number to zero */
	extern void reset_number(void);

#ifdef __cplusplus
}
#endif

#endif

