/******************************************************************************************
* setup.c: Definierar struktarna led, buttom samt adc. Definierar även datatypen bool som
*innehåller led1-5_pwm_enabled. Definierar setup som initierar AD-omvandlaren, alla lysdioder,
*alla knappar samt avbrottsrutiner på alla knapparna. Definierar pwm_run
*******************************************************************************************/

#include "header.h"

struct led l1, l2, l3, l4, l5;
struct button b1, b2, b3, b4, b5;
struct adc a1;

volatile bool led1_pwm_enabled = false,
              led2_pwm_enabled = false,
			  led3_pwm_enabled = false,
              led4_pwm_enabled = false,
              led5_pwm_enabled = false;

/******************************************************************************************
* setup:

initierar AD-omvandlaren, alla lysdioder samt alla knappar och deras respektive avbrottsrutiner.
*******************************************************************************************/
void setup(void)
{
	adc_init(&a1, A0);
	
	led_init(&l1, 6);
	led_init(&l2, 7);
	led_init(&l3, 8);
	led_init(&l4, 9);
	led_init(&l5, 10);
	
	button_init(&b1, 2);
	button_init(&b2, 3);
	button_init(&b3, 11);
	button_init(&b4, 12);
	button_init(&b5, 13);
	
	button_enable_interrupt(&b1);
	button_enable_interrupt(&b2);
	button_enable_interrupt(&b3);
	button_enable_interrupt(&b4);
	button_enable_interrupt(&b5);
}

/******************************************************************************************
* pwm_run:

*Läser av pwm värderna via anrop av funktionen adc_get_pwm_values, är någon av dessa på 
*så tänds respektive lysdiod. Sedan sker det en delay i mikrosekunder via delay_us.
*Lysdioderna släcks sedan vid nedtryckning av knapparna en andra gång. 
*******************************************************************************************/

void pwm_run(void)
{
		 adc_get_pwm_values(&a1, 1000);
		 
		 if (led1_pwm_enabled) led_on(&l1);
		 if (led2_pwm_enabled) led_on(&l2);
		 if (led3_pwm_enabled) led_on(&l3);
		 if (led4_pwm_enabled) led_on(&l4);
		 if (led5_pwm_enabled) led_on(&l5);
		 
		 delay_us(a1.pwm_on_us);
		 // Vänta under on-tiden.
		 
		 led_off(&l1);
		 led_off(&l2);
		 led_off(&l3);
		 led_off(&l4);
		 led_off(&l5);
		 
		 // Vänta under off-tiden.
		 delay_us(a1.pwm_off_us);
	
}