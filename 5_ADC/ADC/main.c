/*
 * ADC.c
 *
 * Created: 26-Sep-23 10:15:06 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"


int main(void)
{
	u16 AnalogValue;
	u16 DigitalValue;
	DIO_SetPinDirection(POT_PORT,POT_PIN,DIO_PIN_INPUT);
	
	LCD_init();
	ADC_init(ADC_REFERENCE_AVCC,ADC_Prescaller_128);
	
    while(1)
    {
		ADC_ReadDigitalValue(ADC_CHANNEL_1,&DigitalValue);
		
		AnalogValue= (DigitalValue*5000UL)/1024; 
		
       LCD_SendString("Voltage=");
	   LCD_SendIntegarNumber(AnalogValue);
	   LCD_SendString("mV");
	   _delay_ms(500);
	   LCD_ClearDesplay();
    }
}