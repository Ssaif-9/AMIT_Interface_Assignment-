/*
 * _6_TIMER.c
 *
 * Created: 06-Oct-23 11:14:32 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_interface.h"

#include "ADC_config.h"
#include "ADC_interface.h"

#include "TIMER0_config.h"
#include "TIMER0_interface.h"

#include "DcMotor_config.h"
#include "DcMotor_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

int main(void)
{
	u16 DigitalValue;
	u16 AnalogValue;
	u8 SpeedValue;
	LCD_init();
	DIO_SetPinDirection(POT_PORT,POT_PIN,DIO_PIN_INPUT);
	
	ADC_init(ADC_REFERENCE_AVCC,ADC_Prescaller_128);
	DcMotor_init(DcMotor_MOTOR_A);
	
    while(1)
    {
		ADC_ReadDigitalValue(ADC_CHANNEL_1,&DigitalValue);
        AnalogValue=(DigitalValue*5000UL)/1024;
		
		SpeedValue=(AnalogValue*100UL)/5000UL;
		
		DcMotor_ONControlSpeed(DcMotor_MOTOR_A,DcMotor_CLOCK_WISE,SpeedValue);
		
		LCD_GoToLocation(1,1);
		LCD_SendString("Voltage=");
		LCD_SendIntegarNumber(AnalogValue);
		LCD_SendString("mV   ");
		LCD_sendComnd(LCD_GO_TO_2ND_LINE);
		LCD_GoToLocation(1,2);
		LCD_SendString("speed=");
		LCD_SendIntegarNumber(SpeedValue);
		LCD_SendString("%      ");
		
    }
}





































//cant take 0% speed from non inverting PWM and integer percentage (can not fell of 0.1~0.99 )
//can not reach to 100% speed (ADC problem can not take all range )