/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#ifndef IO_H
#define IO_H

#include<stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif

	/** functin to send out data to three shift registers at once */
	extern void thriftout(const uint8_t data1, const uint8_t data2, const uint8_t data3);

#ifdef __cplusplus
}
#endif

#endif

