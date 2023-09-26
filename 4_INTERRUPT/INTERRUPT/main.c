/*
 * INTERRUPT.c
 *
 * Created: 26-Sep-23 9:11:44 PM
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

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"

void UP_Counter   (void);
void DOWN_Counter (void);

u8 Counter = 0;

int main(void)
{
	LED_init(LED0_PORT,LED0_PIN);
	LED_init(LED1_PORT,LED1_PIN);
	LED_init(LED2_PORT,LED2_PIN);
	GLBI_Enable();
	EXTI_Enable(EXTI_INT1,EXTI_RISING_EDGE);
	EXTI_Enable(EXTI_INT2,EXTI_RISING_EDGE);
	EXTI_SetCallBackInt1(&UP_Counter);
	EXTI_SetCallBackInt2(&DOWN_Counter);
	
    while(1)
    {
        if(Counter==0)
		{
			LED_TurnOFF(LED0_PORT,LED0_PIN);
			LED_TurnOFF(LED1_PORT,LED1_PIN);
			LED_TurnOFF(LED2_PORT,LED2_PIN);
		}
		else if (Counter==1)	
		{
			LED_TurnON(LED0_PORT,LED0_PIN);
			LED_TurnOFF(LED1_PORT,LED1_PIN);
			LED_TurnOFF(LED2_PORT,LED2_PIN);
		}		
		else if (Counter==2)
		{
			LED_TurnON(LED0_PORT,LED0_PIN);
			LED_TurnON(LED1_PORT,LED1_PIN);
			LED_TurnOFF(LED2_PORT,LED2_PIN);
		}
		else if (Counter==3)
		{
			LED_TurnON(LED0_PORT,LED1_PIN);
			LED_TurnON(LED1_PORT,LED1_PIN);
			LED_TurnON(LED2_PORT,LED2_PIN);
		}
    }
}

void UP_Counter (void)
{
	if (Counter<3)
	{
		Counter++;
	}
	else 
	{
		//No Thing
	}
}
void DOWN_Counter (void)
{
	if (Counter>0)
	{
		Counter--;
	}
	else
	{
		//No Thing
	}
}