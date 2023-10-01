/*
 * UART_ASSIG.c
 *
 * Created: 01-Oct-23 4:40:43 PM
 *  Author: SEIF EL-DIN SOLTAN
 */


 #define F_CPU 16000000UL
 #include <util/delay.h>

 #include "STD_TYPE.h"
 #include "BIT_MATH.h"

 #include "DIO_interface.h"
 #include "DIO_config.h"
 #include "DIO_private.h"

 #include "UART_interface.h"
 #include "UART_config.h"
 #include "UART_private.h"

 #include "LED_interface.h"
 #include "LED_config.h "
 #include "LED_private.h"

 int main(void)
 {
	 u8 ReceiveValue;
	 
	 DIO_SetPinDirection(UART_TX_PORT,UART_TX_PIN,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(UART_RX_PORT,UART_RX_PIN,DIO_PIN_INPUT);
	 
	 UART_init();
	 LED_init(LED0_PORT,LED0_PIN);
	 
	 while(1)
	 {
		 UART_ReceiveChar(&ReceiveValue);
		 if (ReceiveValue=='1')
		 {
			 LED_TurnON(LED0_PORT,LED0_PIN);
		 }
		 if (ReceiveValue=='0')
		 {
			 LED_TurnOFF(LED0_PORT,LED0_PIN);
		 }
	 }
 }