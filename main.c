#include "header.h"

/******************************************************************************************
* main: Ansluter fem lysdioder till pin 6 - 10 och fem tryckknappar till pin 2 och 3,
*       samt 11 -13, även en potentiometer till analog pin A0. Vid nedtryckning av respektive
*       tryckknapp sker avläsning av den analoga insignalen från potentiometern och denna används
*       för att kontrollera ljusstyrkan på lysdiodenrna, övrig tid hålls de
*       släckta. En PWM-period på 10 000 us används. Lysdioderna ska kunna släckas och tändas
*       oberoende av varandra.
*******************************************************************************************/
int main(void)
{
   setup();
  
   while (1)
   {
	 pwm_run();
   }  
   return 0;
}

