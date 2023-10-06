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


#include "DIO_interface.h"
#include "DIO_config.h"

#include "SPI_interface.h"
#include "SPI_config.h"

#include "LED_interface.h"
#include "LED_config.h"


#define MASTER_TRUE_SIGNAL  1
#define MASTER_FALSE_SIGNAL 0

#define SLAVE_TRUE_SIGNAL  2
#define SLAVE_FALSE_SIGNAL 3


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
		if(MASTER_TRUE_SIGNAL==ReceiveValue)
		{
			SPI_Tranceive(SLAVE_TRUE_SIGNAL,&ReceiveValue);
			LED_TurnON(LED0_PORT,LED0_PIN);
		}
		else
		{
			SPI_Tranceive(SLAVE_FALSE_SIGNAL,&ReceiveValue);
			LED_TurnOFF(LED0_PORT,LED0_PIN);
		}
    }
}