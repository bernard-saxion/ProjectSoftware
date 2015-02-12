/*********************
 * project software
 * 2014/2015
 * Saxion Enschede
 * Acedemy LED
 * EEL1Ib --- team 5
<405759@student.saxion.nl>
 *********************/

#include"servo.h"
#include<Arduino.h>
#include <Servo.h>             //include servo library
#include"audio.h"
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

