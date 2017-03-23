// Project name		: Black_Line_Follower_Robot_for_ATmega16_IBOT_mini_V3
// Designed By 		: ROBOMART.com
// Designed for		: Robosapiens Technologies Pvt. Ltd.
//                	  http://www.robosapiensindia.com
/* Program for "Black Line Follower Robot" 
______________________________________________________________________________________________________
Connection settings of the Kit

Pins of IR sensor is connected with the PortA of the MCU

Left Sensor -----> PA4
Right Sensor-----> PA5


Left Motor  -----> PB0,PB1
Right Motor -----> PB2,PB3


BOOTLooder Condition Check--->PA0(If 0 bootler section else program execution section of Flash memory)
Crystal Ossilator(12MHz)----->XTAL1,XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)

*/


#define F_CPU 12000000UL  // define MCU Clock speed
#include <avr/io.h>       // include avr header file
#include <util/delay.h>   // include delay header file


int main(void)  		  // main function
{
DDRA=0b00000000;          // declare PortA as a input port connected to the sensors
DDRB=0b11111111;          // declare PortB as a output port connected to the motors

int left_sensor=0, right_sensor=0;

while(1) // infinite loop
	{
	left_sensor=PINA&0b00010000;    // mask PA4 bit of Port A
	right_sensor=PINA&0b00100000;   // mask PA5 bit of Port A
	 
	 
	if((left_sensor==0b00000000) && (right_sensor==0b00000000))     // if both sensors "off"
		{
		PORTB=0b00000000;   // stop	
		}

    if((left_sensor==0b00010000) && (right_sensor==0b00100000))     // if both sensors "on"
		{
        PORTB=0b00001001;  // move straight
		}
			
	if((left_sensor==0b00000000) && (right_sensor==0b00100000)) 	// if left sensor off but right sensor on
        {
		PORTB=0b00000001; // turn left
        }

	if((left_sensor==0b00010000)&(right_sensor==0b00000000))  ////if left sensor on but right sensor off
        {
		PORTB=0b00001000; // turn right
		}


	}      // while closed

}         //  main closed

