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

#include "DIO_interface.h"
#include "DIO_config.h"

#include "SPI_interface.h"
#include "SPI_config.h"

#include "BUTTON_interface.h"
#include "BUTTON_config.h"

#include "LCD_interface.h"
#include "LCD_config.h"

#define MASTER_TRUE_SIGNAL  1
#define MASTER_FALSE_SIGNAL 0

#define SLAVE_TRUE_SIGNAL  2
#define SLAVE_FALSE_SIGNAL 3

#define BUTTON_PRESSED     1

int main(void)
{
	u8 ReceiveValue;
	u8 ButtonValue;
	
	DIO_SetPinDirection(SPI_SS_PORT,SPI_SS_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(SPI_MOSI_PORT,SPI_MOSI_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(SPI_SCLK_PORT,SPI_SCLK_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(SPI_MISO_PORT,SPI_MISO_PIN,DIO_PIN_INPUT);
	
    DIO_SetPinValue(SPI_SS_PORT,SPI_SS_PIN,DIO_PIN_LOW);
	
	SPI_init();
	
	BUTTON_init(BUTTON_B0_PORT,BUTTON_B0_PIN);
	
	LCD_init();

    while(1)
    {
		DIO_SetPinValue(SPI_SS_PORT,SPI_SS_PIN,DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_SetPinValue(SPI_SS_PORT,SPI_SS_PIN,DIO_PIN_LOW);
		
		BUTTON_ReadValue(BUTTON_B0_PORT,BUTTON_B0_PIN,&ButtonValue,BUTTON_PullDown);
		
		ButtonValue==BUTTON_PRESSED ? (SPI_Tranceive(MASTER_TRUE_SIGNAL,&ReceiveValue)) : (SPI_Tranceive(MASTER_FALSE_SIGNAL,&ReceiveValue)) ;
		
		if (SLAVE_TRUE_SIGNAL==ReceiveValue)
		{
			LCD_GoToLocation(1,1);
			LCD_SendString("LED IS ON");
		}
		else
		{
			LCD_ClearDesplay();
		}			
    }
}
