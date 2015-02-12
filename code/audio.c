/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#include"audio.h"
#include<Arduino.h>
static uint8_t speaker = 5;

//NOTES                      'c'  , 'd',  'e',  'f'
static const int tones[] = { 1915, 1500, 1319, 5000, 400, 1132}; //freq

extern void audio_setup(void)
{
	pinMode(speaker, OUTPUT);
	sound(sound_correct);
	sound(sound_opened);
}

extern void sound(const enum sound_t number)
{
	auto int Cur_tone = 0;
	auto uint_fast8_t i;
	if((number == sound_correct) || (number == sound_opened) || 
	   (number == sound_locked) || (number == sound_incorrect) ||
	   (number == sound_tick))
	{ 
		if (number==sound_correct)
		{
			Cur_tone = tones[0];
		} 
		if (number==sound_opened)
		{
			Cur_tone = tones[1];
		}
		if (number==sound_locked)
		{
			Cur_tone = tones[2];
		}
		if (number==sound_incorrect)
		{
			Cur_tone = tones[3];
		}
		if (number==sound_tick)
		{
			Cur_tone = tones[4];
		}
	}
	else //in case no button is pressed , close the piezo
	{
		digitalWrite(speaker,LOW);
	}

	for(i=Cur_tone;i!=0;i--)
	{
		digitalWrite(speaker, HIGH);
		delayMicroseconds(Cur_tone);
		digitalWrite(speaker, LOW);
		delayMicroseconds(Cur_tone);
	}
}

