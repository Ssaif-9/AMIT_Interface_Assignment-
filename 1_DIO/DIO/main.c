/*
 * DIO.c
 *
 * Created: 26-Sep-23 6:59:15 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#define LED_L0_PORT   PORTC_REG
#define LED_L0_PIN    DIO_PIN2

#define LED_L1_PORT   PORTC_REG
#define LED_L1_PIN    DIO_PIN7

/*	config for ways	*/
#define First_Way      1
#define Second_Way     2
#define Third_Way      3

#define WayId          First_Way


#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"

#include "LED_interface.h"
#include "LED_config.h"

int main(void)
{
	DIO_SetPinDirection(LED0_PORT,LED0_PIN,DIO_PIN_OUTPUT);   //Set LED0 As OUTPUT PIN
	DIO_SetPinDirection(LED1_PORT,LED1_PIN,DIO_PIN_OUTPUT);   //Set LED1 As OUTPUT PIN
	DIO_SetPinDirection(LED2_PORT,LED2_PIN,DIO_PIN_OUTPUT);   //Set LED2 As OUTPUT PIN
	
    while(1)
    {
		#if WayId == First_Way                   //blank LED0 USING SET and CLR 
		SET_BIT(LED_L0_PORT,LED_L0_PIN);
		_delay_ms(1000);
		CLR_BIT(LED_L0_PORT,LED_L0_PIN);
		_delay_ms(1000);
		
		#elif  WayId == Second_Way               //blank LED1 USING TGL  
        TGL_BIT(LED_L1_PORT,LED_L1_PIN);
		_delay_ms(1000);
		 
		#elif  WayId == Third_Way                //blank LED2  Using Driver Specific to LED
		LED_init(LED2_PORT,LED2_PIN);
		LED_Toggle(LED2_PORT,LED2_PIN);
		_delay_ms(1000);
		
		#endif
    }
}