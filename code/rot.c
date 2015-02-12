#include"program.h"
#include<Arduino.h>

/** rotary in */
static volatile uint_fast16_t rin;
static void rota(void)
{
	/* read out the pin */
	switch(PIND&B00001000)
	{
		/* lo */
		case B00000000:
			/*  up but not over 1e3 */
			rin++;
			rin%=1000;
			return;
		/* hi */
		case B00001000:
			/* down but not negative */
			if(--rin>1000)rin=999;
			return;
	}
}


extern void rot_setup(void)
{
	/* data directions, `1` adds input mode*/
	DDRD&=B00001100;
	/* watch the rotary move */
	attachInterrupt(0,&rota,FALLING);
}

extern void rot_loop(void)
{
	/* using interrupts, no loop needed */
}

extern uint_fast16_t get_number(void)
{
	return rin;
}

extern void reset_number(void)
{
	rin=0;
}

