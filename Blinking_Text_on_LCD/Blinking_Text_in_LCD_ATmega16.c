// Project name		: Blinking_Text_on_LCD_ATmega16_IBOT_mini_V3
// Designed By 		: ROBOMART.com
// Designed for		: Robosapiens Technologies Pvt. Ltd.
//                	  http://www.robosapiensindia.com
/* Program for "Blinking_Text_on_LCD" 
_______________________________________________________________________________________________________
Connection settings of the Kit

16x2 LCD connection
Pin 1 -----> GND
Pin 2 -----> VCC(+5v)
VEE   -----> Connected with Variable resistor
RS --------> PC0
RW --------> PC1
E  --------> PC2
D0,D1,D2 & D3 do not Used
D4 --------> PC4 
D5 --------> PC5
D6 --------> PC6
D7 --------> PC7
Pin 15-----> Vcc(+5v)
Pin 16-----> GND

BOOTLooder Condition Check--->PA0(If 0 bootler section else program execution section of Flash memory)
Crystal Ossilator(12MHz)----->XTAL1,XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/


#define F_CPU 12000000UL  // defines the clock speed
#include <avr/io.h>       // includes input/output header file     
#include <util/delay.h>   // includes delay header file   
#include"lcd_16.h"        // include lcd_16.h 
#include"lcd_16.c"        // include lcd_16.c


void wait(float x)        // wait function
{
for(int i=0;i<(int)(1302*x);i++)
_delay_loop_1(0);
}


int main (void)          // main function
{
lcd_init(LCD_DISP_ON);   // initialize Lcd

	while(1)             // infinite loop
	{
	lcd_clrscr();                  // clear screen
	lcd_gotoxy(2,0);               // select the position of the text
	lcd_puts("Robosapiens");       // print the text
	wait(5);                       // delay
	lcd_clrscr();                  // clear screen
	lcd_gotoxy(5,1);               // select the position of the text
	lcd_puts("India");             // print the text
	wait(5);                       // delay
	}                   // while closed
}                       // main closed
