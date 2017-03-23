// Project name : START_and_STOP_on_CLAP_for_ATmega16_IBOT_mini_V3
// Designed By  : ROBOMART.com
// Designed for	: Robosapiens Technologies Pvt. Ltd.
//                http://www.robosapiensindia.com
/* Program for "START_and_STOP_on_CLAP/toggeling the state of Atmega 16 V3 on Clap Using Sound Sensor"
______________________________________________________________________________________________________
Connection settings of the Kit

SOUND SENSOR--------->PD6
RIGHT MOTOR(+)------->PB0
RIGHT MOTOR(-)------->PB1
LEFT MOTOR(-)-------->PB2
LEFT MOTOR(+)-------->PB3

BOOTLoAder Condition Check----->PA0(f 0 bootloader section else program execution
							    section of Flash memory)

Crystal Ossilator-------------->XTAL1 and XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/


#define F_CPU12000000UL 		// Define clock speed of the MCU
#include<avr/io.h> 				// include avr header file
#include<util/delay.h> 			// include Dealy header file

int main(void)					// main function
{	
DDRB=0b00001111;  				// declare Port B as a output port connected to the motors
DDRD=0x00;        				// declare Port D as a input port connected to the sensor

int ss=0, counter=1;            // define & initialize ss and counter integer as  0 to acquire the sound sensor status in ss and counter increment

while(1)          				// create infinite loop
	{
	ss=(PIND&0b01000000);       // acquire only sound sensor status connected at PD6
		
	if((ss==0b01000000) && (counter==1))	     // check for sound sensor ON status at PD6
	{       
	 PORTB=0b00001001;  						 // forward
		 
		 while((PIND&0b01000000)==0b01000000);	 // monitoring PD6 pin for the change of state	
    		
			counter=0;

		 	_delay_ms(10000);

	} 



	ss=(PIND&0b01000000);    	// acquire only sound sensor status connected at PD6

	if((ss==0b01000000) && (counter==0))
	{
	 PORTB=0b00000000;			// stop

	 counter=1;

	 _delay_ms(10000);

	}
	
	}


}

