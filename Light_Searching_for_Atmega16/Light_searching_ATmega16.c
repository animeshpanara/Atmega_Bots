// Project name		: Light Searching Robot_for_ATmega16_IBOT_mini_V3
// Designed By 		: ROBOMART.com
// Designed for		: Robosapiens Technologies Pvt. Ltd.
//                	  http://www.robosapiensindia.com
/* Program for " Light Searching Robot" 
______________________________________________________________________________________________________
Connection settings of the Kit

Pins of Light Searching sensor is connected with the PortD of the MCU

Output ----> PD6
Vcc    ----> +5v
Gnd    ----> 0v

Left Motor  -----> PB0,PB1
Right Motor -----> PB2,PB3



BOOTLooder Condition Check--->PA0(If 0 bootler section else program execution section of Flash memory)
Crystal Ossilator(12MHz)----->XTAL1,XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)

*/


#define F_CPU 12000000UL       // define cpu frequency for delay function
#include <avr/io.h>            // includes input/output header file     
#include <util/delay.h>        // includes delay header file  

main()                         // main function
{
DDRD=0b00000000;               // PORTD as Input Port connected to Sensor
DDRB=0b11111111;               // PORTB Output port connected to Motors

int light_sensor=0;

while(1) // infinite loop
	{
	light_sensor=PIND&0b01000000; // mask PD6 bit of Port D

		if(light_sensor==0b01000000) //if Light source is on robot's left side "
      		PORTB=0b00000001; // move left
    		 else
    	  		PORTB=0b00001000; // move right

               
			
			 


 	}       // while closed

}           //  main closed

