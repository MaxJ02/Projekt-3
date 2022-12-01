#include "header.h"

/******************************************************************************************
* main: Ansluter fem lysdioder till pin 6 - 10 och fem tryckknappar till pin 2 och 3,
*       samt 11 -13, �ven en potentiometer till analog pin A0. Vid nedtryckning av respektive
*       tryckknapp sker avl�sning av den analoga insignalen fr�n potentiometern och denna anv�nds
*       f�r att kontrollera ljusstyrkan p� lysdiodenrna, �vrig tid h�lls de
*       sl�ckta. En PWM-period p� 10 000 us anv�nds. Lysdioderna ska kunna sl�ckas och t�ndas
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

