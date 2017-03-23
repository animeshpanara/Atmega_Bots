// Project name		: Motor_testing_for_ATmega16_IBOT_mini_V3
// Designed By 		: ROBOMART.com
// Designed for		: Robosapiens Technologies Pvt. Ltd.
//                	  http://www.robosapiensindia.com
/* Program for " Testing the motors & L293D Motor driver IC" 
______________________________________________________________________________________________________
Connection settings of the Kit

Input Pins of L293D is connected with the PortB of the MCU

Left Motor  -----> PB0,PB1
Right Motor -----> PB2,PB3

BOOTLooder Condition Check--->PA0(If 0 bootler section else program execution section of Flash memory)
Crystal Ossilator(12MHz)----->XTAL1,XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)

*/


#define F_CPU12000000UL   // define MCU Clock speed
#include<avr/io.h>        // include avr header file
#include<util/delay.h>    // include delay header file

main()     // main function
{
DDRB=0b00001111;     // Declare PortB as a output port connected to the motors

while(1)   // infinite loop
	{
	PORTB=0b00001001;   // Both Motors in  Clockwise Direction
	_delay_ms(1000);    // delay
	_delay_ms(1000);

	PORTB=0b00000110;   // Both Motors in Anti Clockwise direction
	_delay_ms(1000);
	_delay_ms(1000);

	PORTB=0b00000001;   // Left motor stop but Right motor in clockwise direction
	_delay_ms(1000);
	_delay_ms(1000);

	PORTB=0b00001000; 	// Right motor stop but Left motor in clockwise direction
	_delay_ms(1000);
	_delay_ms(1000);

	PORTB=0b00000000;   // Both motors stop
	_delay_ms(1000);
	_delay_ms(1000);
	} 					// while closed


}                       // main closed
