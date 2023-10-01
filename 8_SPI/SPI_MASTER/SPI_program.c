/*
 * SPI_program.c
 *
 * Created: 30-Sep-23 12:13:41 PM
 *  Author: SEIF EL_DIN SULTAN 
 */ 

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"

static void (*Private_CallBackSPI) (void) =NULL;

void SPI_init(void)
{
	#if SPI_MODE == SPI_Master

	SET_BIT(SPCR,SPIE); //Enaple Interrupt
	
	SET_BIT(SPCR,SPR0);   //Select CLK Rate
	CLR_BIT(SPCR,SPR1);   //  F/16
	CLR_BIT(SPSR,SPI2X);  //  1MHZ
	
	SET_BIT(SPCR,CPHA);   //Select Phase 
	SET_BIT(SPCR,CPOL);   //Select Polarity
	
	SET_BIT(SPCR,MSTR);  //Select Master 
	SET_BIT(SPCR,DORD);  //Select LSB
	SET_BIT(SPCR,SPE);   //Enable SPI 
	
	#elif SPI_MODE == SPI_Slave
	SET_BIT(SPCR,SPIE);  //Enaple Interrupt
	
	SET_BIT(SPCR,CPHA);    //Select Phase
	SET_BIT(SPCR,CPOL);    //Select Polarity
	
	CLR_BIT(SPCR,MSTR);   //Select Slave
	SET_BIT(SPCR,DORD);   //Select LSB
	SET_BIT(SPCR,SPE);    //Enable SPI 
	
	#endif
}

void SPI_Tranceive(u8 TxData,u8* RxData)
{
	if(RxData!=NULL)
	{
		while (1 == GET_BIT(SPSR,WCOL));
		SPDR=TxData;
		
		while (0 == GET_BIT(SPSR,SPIF));
		*RxData=SPDR;
	}
}

void SPI_Receive (u8* RxData)
{
	if(RxData!=NULL)
	{
		while (0 == GET_BIT(SPSR,SPIF));
		*RxData=SPDR;
	}
}

void SPI_Transimite (u8 TxData)
{
	while (1 == GET_BIT(SPSR,WCOL));
	SPDR=TxData;
}



 void SPI_SetCallBack  (void(*PtrToFun)(void))
 {
	 Private_CallBackSPI=PtrToFun;
 }
 
 void  __vector_12(void) __attribute__((signal));
 void  __vector_12(void)
 {
	 if (Private_CallBackSPI != NULL)
	 {
		 Private_CallBackSPI();
	 }
 }