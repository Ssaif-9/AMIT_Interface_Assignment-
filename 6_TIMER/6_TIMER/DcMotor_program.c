/*
 * DcMotor_program.c
 *
 * Created: 24-Sep-23 3:43:48 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "TIMER0_config.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"

#include "DcMotor_config.h"
#include "DcMotor_interface.h"
#include "DcMotor_private.h"


void DcMotor_init(u8 MotorId)
{
	if( MotorId<=1 )
	{
		switch(MotorId)
		{
			case DcMotor_MOTOR_A:
			DIO_SetPinDirection(DcMotor_H_BRIDG_PORT_EN1,DcMotor_H_BRIDG_PIN_EN1,DIO_PIN_OUTPUT);
			DIO_SetPinDirection(DcMotor_H_BRIDG_PORT_IN1,DcMotor_H_BRIDG_PIN_IN1,DIO_PIN_OUTPUT);
			DIO_SetPinDirection(DcMotor_H_BRIDG_PORT_IN2,DcMotor_H_BRIDG_PIN_IN2,DIO_PIN_OUTPUT);
			break;
			
			case DcMotor_MOTOR_B:
			DIO_SetPinDirection(DcMotor_H_BRIDG_PORT_EN2,DcMotor_H_BRIDG_PIN_EN2,DIO_PIN_OUTPUT);
			DIO_SetPinDirection(DcMotor_H_BRIDG_PORT_IN3,DcMotor_H_BRIDG_PIN_IN3,DIO_PIN_OUTPUT);
			DIO_SetPinDirection(DcMotor_H_BRIDG_PORT_IN4,DcMotor_H_BRIDG_PIN_IN4,DIO_PIN_OUTPUT);
			break;
		}
	}
	else
	{
		//NO THING
	}
	
	
}

void DcMotor_ON(u8 MotorId, u8 MotorDirection)
{
	if( MotorId<=1 && MotorDirection<=1 )
	{
		switch (MotorId)
		{
			case DcMotor_MOTOR_A:
			if (MotorDirection == DcMotor_CLOCK_WISE )
			{
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_EN1,DcMotor_H_BRIDG_PIN_EN1,DIO_PIN_HIGH);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN1,DcMotor_H_BRIDG_PIN_IN1,DIO_PIN_HIGH);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN2,DcMotor_H_BRIDG_PIN_IN2,DIO_PIN_LOW);
			}
		    if(MotorDirection == DcMotor_COUNTER_CLOCK_WISE )
			{
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_EN1,DcMotor_H_BRIDG_PIN_EN1,DIO_PIN_HIGH);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN1,DcMotor_H_BRIDG_PIN_IN1,DIO_PIN_LOW);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN2,DcMotor_H_BRIDG_PIN_IN2,DIO_PIN_HIGH);
			}
			break;
			
			case DcMotor_MOTOR_B:
			if (MotorDirection == DcMotor_CLOCK_WISE )
			{
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_EN2,DcMotor_H_BRIDG_PIN_EN2,DIO_PIN_HIGH);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN3,DcMotor_H_BRIDG_PIN_IN3,DIO_PIN_HIGH);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN4,DcMotor_H_BRIDG_PIN_IN4,DIO_PIN_LOW);
			}
		    if(MotorDirection == DcMotor_COUNTER_CLOCK_WISE )
			{
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_EN2,DcMotor_H_BRIDG_PIN_EN2,DIO_PIN_HIGH);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN3,DcMotor_H_BRIDG_PIN_IN3,DIO_PIN_LOW);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN4,DcMotor_H_BRIDG_PIN_IN4,DIO_PIN_HIGH);
			}
			break;
		}
	}
	else
	{
		//NO THING
	}
	
}

void DcMotor_ONControlSpeed(u8 MotorId, u8 MotorDirection, u8 MotorSpeed)
{
	if ( MotorId<=1 && MotorDirection<=1 && MotorSpeed<=100 )
	{
		DIO_SetPinDirection(DcMotor_SpeedPort,DcMotor_SpeedPin,DIO_PIN_OUTPUT);   //OC0
		TMR0_init();
		TMR0_SetCompareMatchValue_FastPWM_NonInverting(MotorSpeed);
		TMR0_Start();
		
		switch (MotorId)
		{
			case DcMotor_MOTOR_A:
			DIO_SetPinDirection(DcMotor_H_BRIDG_PORT_EN1,DcMotor_H_BRIDG_PIN_EN1,DIO_PIN_INPUT);
			if (MotorDirection == DcMotor_CLOCK_WISE )
			{
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN1,DcMotor_H_BRIDG_PIN_IN1,DIO_PIN_HIGH);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN2,DcMotor_H_BRIDG_PIN_IN2,DIO_PIN_LOW);
			}
			if(MotorDirection == DcMotor_COUNTER_CLOCK_WISE )
			{
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN1,DcMotor_H_BRIDG_PIN_IN1,DIO_PIN_LOW);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN2,DcMotor_H_BRIDG_PIN_IN2,DIO_PIN_HIGH);
			}
			break;
			
			case DcMotor_MOTOR_B:
			DIO_SetPinDirection(DcMotor_H_BRIDG_PORT_EN2,DcMotor_H_BRIDG_PIN_EN2,DIO_PIN_INPUT);
			if (MotorDirection == DcMotor_CLOCK_WISE )
			{
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN3,DcMotor_H_BRIDG_PIN_IN3,DIO_PIN_HIGH);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN4,DcMotor_H_BRIDG_PIN_IN4,DIO_PIN_LOW);
			}
			if(MotorDirection == DcMotor_COUNTER_CLOCK_WISE )
			{
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN3,DcMotor_H_BRIDG_PIN_IN3,DIO_PIN_LOW);
				DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN4,DcMotor_H_BRIDG_PIN_IN4,DIO_PIN_HIGH);
			}
			break;
		}
	}
	else
	{
		//NO THING
	}
}

void DcMotor_OFF(u8 MotorId)
{
	if (MotorId<=1)
	{
		switch (MotorId)
		{
			case DcMotor_MOTOR_A:
			DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN1,DcMotor_H_BRIDG_PIN_IN1,DIO_PIN_LOW);
			DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN2,DcMotor_H_BRIDG_PIN_IN2,DIO_PIN_LOW);
			break;
			
			case DcMotor_MOTOR_B:
			DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN3,DcMotor_H_BRIDG_PIN_IN3,DIO_PIN_LOW);
			DIO_SetPinValue(DcMotor_H_BRIDG_PORT_IN4,DcMotor_H_BRIDG_PIN_IN4,DIO_PIN_LOW);
			break;
		}
	}
	else
	{
		//NO THING
	}
	
}

