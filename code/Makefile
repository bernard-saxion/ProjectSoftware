TARGET:=vault.elf
INCLUDES:= -I/usr/share/arduino/libraries/EEPROM/ -I/usr/share/arduino/libraries/Servo/
OBJS:=program.o shift.o rot.o display.o servo.o audio.o serial.o
LIBS:=share/lib/libservo.a share/lib/libeeprom.a
LINKERFLAGS:=-lservo -leeprom
include share/Makefile

