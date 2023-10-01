/*
 * SPI_MASTER.c
 *
 * Created: 01-Oct-23 5:18:47 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"

#include "BUTTON_config.h"
#include "BUTTON_interface.h"
#include "BUTTON_private.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"





int main(void)
{
	u8 ButtonValue;
	u8 TransimiteValue;
	
	DIO_SetPinDirection(SPI_SS_PORT,SPI_SS_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(SPI_MOSI_PORT,SPI_MOSI_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(SPI_SCLK_PORT,SPI_SCLK_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(SPI_MISO_PORT,SPI_MISO_PIN,DIO_PIN_INPUT);
	
	LCD_init();
	SPI_init();
	BUTTON_init(BUTTON_B0_PORT,BUTTON_B0_PIN);
	
	
    while(1)
    {
		BUTTON_ReadValue(BUTTON_B0_PORT,BUTTON_B0_PIN,&ButtonValue,BUTTON_PullUp);
		if (1 == ButtonValue)
		{
			DIO_SetPinValue(SPI_SS_PORT,SPI_SS_PIN,DIO_PIN_LOW);
			SPI_Transimite(1);
			_delay_ms(10);
		}
		if (0 == ButtonValue)
		{
			DIO_SetPinValue(SPI_SS_PORT,SPI_SS_PIN,DIO_PIN_HIGH);
			/*SPI_Transimite(0);*/
		    _delay_ms(10);
		}
    }
}
