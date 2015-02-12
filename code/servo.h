/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#ifndef SERVO_H
#define SERVO_H

#ifdef __cplusplus
extern "C"
{
#endif
	
	/** sets up the servo pins */
	extern void servo_setup(void);
	/** function to  open the box */
	extern void openbox(void);
	/** function to close the box */
	extern void closebox(void);

#ifdef __cplusplus
}
#endif

#endif

