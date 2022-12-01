#include "header.h"

/******************************************************************************************
*Interrupts.c: Innehåller avbrottsrutiner för lysdioderna, som sker när respektive tryckknapp
*trycks ned.
*******************************************************************************************/

ISR (PCINT0_vect)
{
	if (button_is_pressed(&b3))
	{
	    led3_pwm_enabled = !led3_pwm_enabled;	
	}
	if(button_is_pressed(&b4))
	{
		led4_pwm_enabled = !led4_pwm_enabled;	
	}
	if(button_is_pressed(&b5))
	{
		led5_pwm_enabled = !led5_pwm_enabled;
	}
}

ISR (PCINT2_vect)
{
	if (button_is_pressed(&b1))
	{
		led1_pwm_enabled = !led1_pwm_enabled;
	}
	if (button_is_pressed(&b2))
	{
		led2_pwm_enabled = !led2_pwm_enabled;
	}
}
