// Project name		: Wall Follower Robot_for_ATmega16_IBOT_mini_V3
// Designed By 		: ROBOMART.com
// Designed for		: Robosapiens Technologies Pvt. Ltd.
//                	  http://www.robosapiensindia.com
/* Program for " To follow a wall" 
______________________________________________________________________________________________________
Connection settings of the Kit

Pins of IR sensor is connected with the PortA of the MCU
Attach sensor on left side

left_Sensor -----> PA4

Left Motor  -----> PB0,PB1
Right Motor -----> PB2,PB3

BOOTLooder Condition Check--->PA0(If 0 bootler section else program execution section of Flash memory)
Crystal Ossilator(12MHz)----->XTAL1,XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)

*/


#define F_CPU 12000000UL 				// define clock speed of the MCU
#include<avr/io.h>   					// include avr header file
#include<util/delay.h>				    // include delay header file


main() 									// main function
{
DDRB=0xFF; 								// declare Port B as a output port connected to the motors
DDRA=0x00; 								// declare Port A as a Input port connected to the Sensor

int left_sensor=0;

while(1) 								// infinite loop
{
 left_sensor=PINA&0b00010000; 			// mask PA4 bit of Port A

 if(left_sensor==0b00010000) 			// is sensor is on

     PORTB=0b00001000; 					// turn right
		
		else 

     		PORTB=0b00000001; 			// turn left

}										// while close

}										// main close



