/*
 * LCD.c
 *
 * Created: 26-Sep-23 7:44:10 PM
 *  Author: SEIF EL-DIN SOLTAN 
 */ 

#define F_CPU 16000000UL 
#include <util/delay.h>

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "GLBI_interfase.h"
#include "GLBI_private.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void UP_Counter   (void);
void DOWN_Counter (void);

u8 Counter = 0;

int main(void)
{
	
	LCD_init();
	GLBI_Enable();
	EXTI_Enable(EXTI_INT0,EXTI_RISING_EDGE);
	EXTI_Enable(EXTI_INT1,EXTI_RISING_EDGE);
	EXTI_SetCallBackInt0(&UP_Counter);
	EXTI_SetCallBackInt1(&DOWN_Counter);
	LCD_SendIntegarNumber(Counter);
	
    while(1)
    {
      
    }
}
void UP_Counter (void)
{
	if(Counter<9)
	{
		Counter++;
		LCD_ClearDesplay();
		LCD_SendIntegarNumber(Counter);
	}
	else
	{
		//No Action
	}
}

void DOWN_Counter (void)
{
	if(Counter>0)
	{
		Counter--;
		LCD_ClearDesplay();
		LCD_SendIntegarNumber(Counter);
	}
	else
	{
		//No Action
	}
}

