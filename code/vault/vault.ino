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

	/** setup audio pins */
	extern void audio_setup(void);
	/** make one of the sounds */
	extern void sound(const enum sound_t);

#endif

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

	/** sets up all the hardware needed for the displays to work */
	extern void display_setup(void);
	/** puts something new on the display */
	extern void display_loop(const uint_fast16_t);

#endif

/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#ifndef PROGRAM_H
#define PROGRAM_H

	extern void setup(void);
	extern void loop(void);

#endif

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

	/** setup all the pins for the rotary encoder */
	extern void rot_setup(void);
	/** update rotary encoder's value */
	extern void rot_loop(void);
	/** get the number that the rotary encoder  found */
	extern uint_fast16_t get_number(void);
	/** resets the number to zero */
	extern void reset_number(void);

#endif

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

	/** setup the program to use serial communication */
	extern void serial_setup(void);
	/**  poll for data */
	extern void serial_loop(void);
	/** */
	extern uint16_t get_code(void);

#endif

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

	/** sets up the servo pins */
	extern void servo_setup(void);
	/** function to  open the box */
	extern void openbox(void);
	/** function to close the box */
	extern void closebox(void);

#endif

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
	/** functin to send out data to three shift registers at once */
	extern void thriftout(const uint8_t data1, const uint8_t data2, const uint8_t data3);

#endif

/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

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

/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#include<Arduino.h>
#include<stdbool.h>

static uint8_t bcd(const uint_fast8_t n)
{
	#if BCD_HARDWARE
	return (uint8_t)n;
	#else
	static const uint8_t pattern[]=
	{/*
		 GFEDCBA.
		---------- */
		B10000001,
		B11110011,
		B01001001,
		B01100001,
		B00110011,
		B00100101,
		B00000101,
		B11110001,
		B00000001,
		B00100001,
	};
	if(n>=sizeof pattern)return B00001101;
	return pattern[n];
	#endif	
}

extern void display_setup(void)
{
	DDRB|=B11111111;
	/* maybe do a MCLR on the registerss */
	thriftout(B00000111,B01000111,B01101111);
}

extern void display_loop(const uint_fast16_t newnumber)
{
	/*
		374 / 100 = 3
		374 % 100 = 74
		374 /  10 = 37
		374 %  10 = 4
	*/
	/* do a triple shiftout */
	thriftout(bcd(newnumber/100),bcd(newnumber/10%10),bcd(newnumber%10));
}

/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#include<Arduino.h>

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

/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

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
/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#include<Arduino.h>
#include <Servo.h>             //include servo library
//push button using pull up = pin 2
//servo: brown=gnd, red=vcc, orange=pin7

Servo myservo;                 //define servo object
static int pos = 0;            //variable used to store the position


extern void servo_setup(void) 
{ 
}

extern void closebox(void)
{
  myservo.attach(6);            //intialize the servo on pin 7
  for(pos=0; pos<90; pos++){
    myservo.write(pos);
    delay(10);
  }
	sound(sound_opened);
	myservo.detach();
}
extern void openbox(void)
{
  myservo.attach(6);            //intialize the servo on pin 7
  for(pos=90; pos>=1; pos--){
    myservo.write(pos);
    delay(10);
  }
	sound(sound_locked);
	myservo.detach();
}

