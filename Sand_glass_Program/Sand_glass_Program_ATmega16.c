// Project name		: Sand_Glass_Program_for_ATmega16_IBOT_mini_V3
// Designed By 		: ROBOMART.com
// Designed for		: Robosapiens Technologies Pvt. Ltd.
//                	  http://www.robosapiensindia.com
/* Program for "Sand Glass" 
______________________________________________________________________________________________________
Connection settings of the Kit


8 LEDs -----> PORTB - PB0 to PB7


BOOTLooder Condition Check--->PA0(If 0 bootler section else program execution section of Flash memory)
Crystal Ossilator(12MHz)----->XTAL1,XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)


*/

#define F_CPU 1200000UL
#include<avr/io.h>
#include<util/delay.h>
#include<math.h>

int powe(int x);

void wait(float x)
{
for(int i=0;i<(int)(x*1302);i++)
_delay_loop_1(0);
}


void main()
{
DDRB=0xFF;
int i,j,k,p=0;
j=1;

	while(1)
	{
	for(i=7;i>=0;i--)
		{
		for(k=0;k<=i;k++)
			{
			PORTB=p+(1<<k);
   			wait(.5);
			}
		p=p+powe(i);
		}
	p=0;
	}
}

int powe(int x)
{
int d=1;
	for (int i=0;i<x;i++)
	{
	 d=d*2;
	}
return d;
}
