// Project name		: Buzzer_testing_ATmega16_IBOT_mini_V3
// Designed By 		: ROBOMART.com
// Designed for		: Robosapiens Technologies Pvt. Ltd.
//                	  http://www.robosapiensindia.com
/* Program for "Buzzer_Testing" 
______________________________________________________________________________________________________
Connection settings of the Kit

Buzzer -----> PB4
BOOTLooder Condition Check--->PA0(If 0 bootler section else program execution section of Flash memory)
Crystal Ossilator(12MHz)----->XTAL1,XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/

#include<avr/io.h>       // include AVR Header file
#include<util/delay.h>   // include delay header file

main()                   // main function
{
DDRB=0b00010000;         // Declare PB4 as a Output

	while(1)             // infinte loop
	{
	PORTB=0b00010000;    // buzzer on 
	_delay_ms(1000);     // delay
	PORTB=0b00000000;    // buzzer off
	_delay_ms(1000);     // delay
	}					 // while closed

}						 // main closed
