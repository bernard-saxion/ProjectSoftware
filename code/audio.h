/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#ifndef SOUND_H
#define SOUND_H

/** all the different sounds that can be made */
enum sound_t
{
	sound_correct=1,
	sound_opened=2,
	sound_locked=3,
	sound_incorrect=4,
	sound_tick=5,
};

#ifdef __cplusplus
extern "C"
{
#endif

	/** setup audio pins */
	extern void audio_setup(void);
	/** make one of the sounds */
	extern void sound(const enum sound_t);

#ifdef __cplusplus
}
#endif

#endif

