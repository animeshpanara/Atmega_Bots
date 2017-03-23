// Project name : Turn_on_CLAP_for_ATmega16_IBOT_mini_V3
// Designed By  : ROBOMART.com
// Designed for	: Robosapiens Technologies Pvt. Ltd.
//                http://www.robosapiensindia.com
/* Program for "Turn_on_CLAP of Atmega 16 V3 on Clap Using Sound Sensor"
_________________________________________________________________________________
Connection settings of the Kit

SOUND SENSOR--------->PD6
RIGHT MOTOR(+)------->PB0
RIGHT MOTOR(-)------->PB1
LEFT MOTOR(-)-------->PB2
LEFT MOTOR(+)-------->PB3

BOOTLoAder Condition Check----->PA0(If 0 bootloader section else program execution
							    section of Flash memory)

Crystal Ossilator-------------->XTAL1 and XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/


#define F_CPU 12000000UL 			// define clock speed of the MCU
#include<avr/io.h> 					// include avr header file
#include<util/delay.h>				// include delay header file

void main(void) 					// main fuinction
	{
	int PORT_STA;

	DDRB=0xFF; 						// declare Port B as a output port connected to the motors
	DDRD=0x00; 						// declare Port D as a inpute port connected to the sensor
	
	while(1) 						// infinite loop
	{
	PORT_STA=PIND&0b01000000; 		// masking PD6 to the variable

		if(PORT_STA==0b01000000)	// sensor on

			PORTB=0b00000001;  		// take turn left

		
		if(PORT_STA==0b00000000)   	// sensor off

			PORTB=0b00001001;  		// move forward
			
	}

	}
