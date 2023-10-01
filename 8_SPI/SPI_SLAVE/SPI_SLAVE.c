/*
 * SPI_SLAVE.c
 *
 * Created: 01-Oct-23 5:19:16 PM
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

#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"



int main(void)
{
	u8 ReceiveValue;
	
	DIO_SetPinDirection(SPI_SS_PORT,SPI_SS_PIN,DIO_PIN_INPUT);
	DIO_SetPinDirection(SPI_MOSI_PORT,SPI_MOSI_PIN,DIO_PIN_INPUT);
	DIO_SetPinDirection(SPI_SCLK_PORT,SPI_SCLK_PIN,DIO_PIN_INPUT);
	DIO_SetPinDirection(SPI_MISO_PORT,SPI_MISO_PIN,DIO_PIN_OUTPUT);
	
	
	SPI_init();
	LED_init(LED0_PORT,LED0_PIN);
	
    while(1)
    {
		SPI_Receive(&ReceiveValue);
		u8 pin =GET_BIT(PORTB_REG,DIO_PIN4);
		if ( 0== pin)
		{
			LED_TurnON(LED0_PORT,LED0_PIN);
		}
		if ( 1==pin )
		{
			LED_TurnOFF(LED0_PORT,LED0_PIN);
		}
		
    }
}