
#include <avr/io.h>       // include avr header file
#include <util/delay.h>   // include delay header file


int main(void)  		  // main function
{
        // declare PortA as a input port connected to the sensors
DDRB=0b00001111;          // declare PortB as a output port connected to the motors

int ls,rs,tp;

while(1) // infinite loop
	{
	ls=PIND & 0b00000001;    // mask PA4 bit of Port A
	rs=PIND & 0b00000010;   // mask PA5 bit of Port A
	 
	 
	if((ls==0b00000000) && (rs==0b00000000) && tp==1)     // if both sensors "off"
		{
		PORTB=0b00000101;   // stop	
		}
    	if((ls==0b00000000) && (rs==0b00000000) && tp==2)     // if both sensors "off"
		{
		PORTB=0b00001010;   // stop	
		}

    if((ls==0b00000001) && (rs==0b00000010))     // if both sensors "on"
		{
        PORTB=0b00001001;  // move straight
		}
			
	if((ls==0b00000000) && (rs==0b00000010)) 	// if left sensor off but right sensor on
        {
		PORTB=0b00000001; 
		tp=1;// turn left
        }

	if((ls==0b00000001)&&(rs==0b00000000))  ////if left sensor on but right sensor off
        {
		PORTB=0b00001000; // turn right
        tp=2;
		}


	}      // while closed

}         //  main closed

