// Project name		: Obstacle_avoider_Robot_for_ATmega16_IBOT_mini_V3
// Designed By 		: ROBOMART.com
// Designed for		: Robosapiens Technologies Pvt. Ltd.
//                	  http://www.robosapiensindia.com
/* Program for "avoiding the obstacle using three IR Sensors" 
______________________________________________________________________________________________________
Connection settings of the Kit

Pins of IR sensor is connected with the PortA of the MCU

Right Sensor -----> PA4
Left Sensor  -----> PA5
Front Sensor -----> PA6

Left Motor  -----> PB0,PB1
Right Motor -----> PB2,PB3

BOOTLooder Condition Check--->PA0(If 0 bootler section else program execution section of Flash memory)
Crystal Ossilator(12MHz)----->XTAL1,XTAL2
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)

*/


#define F_CPU 12000000UL       // define clock speed of MCU
#include <avr/io.h>            // include avr header file
#include <util/delay.h>        // include delay header file

int move_backward=0b00000110;  // make variabe & Assign the value
int right_turn=0b00001000;
int move_forward=0b00001001;
int left_turn=0b00000001;

int right_sensor_on=0b00000010;
int left_sensor_on=0b00000100;
int front_sensor_on=0b00001000;
int left_sensor_off=0b00000000;
int right_sensor_off=0b00000000;
int front_sensor_off=0b00000000;


void wait(float x)             // wait function
{
for(int i=0;i<(int)(46*x);i++)
_delay_loop_2(0);
}


void main ()  				  // main function
{
DDRB = 0b11111111;            // declare PortB as a Output port connected to the motors
DDRA = 0b00000000;            // declare PortA as a input port connected to the sensors
  
  int left_sensor = 0;
  int right_sensor = 0;
  int front_sensor = 0;

while(1)   					  // create an infinite loop
{	
right_sensor = (PINA & 0b00000010);  // masking PA4 to right_sensor
left_sensor =  (PINA & 0b00000100);  // masking PA5 to Left sensor
front_sensor = (PINA & 0b00001000);  // masking PA6 to front_sensor

	   if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_off) & (front_sensor==front_sensor_on))
	   {
		PORTB = move_backward;	     // move backward
		wait(1);
		PORTB=right_turn;            // take a right turn
		wait(.5);
	   }

	   if((left_sensor==left_sensor_off) & (right_sensor==right_sensor_off) & (front_sensor==front_sensor_off))
	   {
         PORTB=move_forward;         // move forward
	   } 

       if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_off) & (front_sensor==front_sensor_off))
	   {
	    PORTB=move_backward;         // move backward
		wait(1);
		PORTB=right_turn;            // take right turn
		wait(.5);
	   }
	 
	   if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_on) & (front_sensor==front_sensor_off))
	   {
	    PORTB=move_backward;  		// move backward
		wait(1);
		PORTB=left_turn;            // take left turn
		wait(.5);
	   }

	   if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_on) & (front_sensor==front_sensor_on))
	   {
	    PORTB=move_backward;  		// move backward
		wait(1);
		PORTB=left_turn;            // take left turn
		wait(.5);
	   }
	      	 
	   if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_on) & (front_sensor==front_sensor_off))
	   {
	    PORTB=move_forward;         // move forward
	   }

	   if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_off) & (front_sensor==front_sensor_on))
	   {
	    PORTB=move_backward;  		// move backward
		wait(1);
		PORTB=right_turn;  			// take right turn
		wait(.5);
	   }

}


}
