/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#include"program.h"
#include<Arduino.h>
#include"rot.h"
#include"display.h"
#include"servo.h"
#include"audio.h"
#include"serial.h"

const static uint8_t goodpin=4;
const static uint8_t badpin=7;

void setup(void)
{
	display_setup();
	rot_setup();
	servo_setup();
	closebox();
	pinMode(goodpin,INPUT);
	pinMode(badpin,OUTPUT);
	digitalWrite(badpin,HIGH);
	serial_setup();
	audio_setup();
}

void loop(void)
{
	static int opened=0;
	static uint_fast16_t lastnumber=0;
	uint_fast16_t nownumber=0;
	if(digitalRead(goodpin)==HIGH)
	{
		if(get_number()==get_code())
		{
			uint_fast16_t timeleft=800;
			display_loop(++opened);
			pinMode(goodpin,OUTPUT);
			pinMode(badpin,OUTPUT);
			
			sound(sound_correct);
			digitalWrite(goodpin,HIGH);
			openbox();
			digitalWrite(badpin,LOW);
			while(timeleft-->0)
			{
				display_loop(timeleft);
				delay(10);
			}
			digitalWrite(badpin,HIGH);
			closebox();
			digitalWrite(goodpin,LOW);

			pinMode(goodpin,INPUT);
			reset_number();
		}
		else
		{
			sound(sound_incorrect);
			Serial.println(get_number());
		}
	}
	nownumber=get_number();
	if(nownumber!=lastnumber)sound(sound_tick);
	lastnumber=nownumber;

	display_loop(nownumber);
	serial_loop();
	delay(100);
}

