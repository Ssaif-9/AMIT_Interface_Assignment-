/*
 * SPI_config.h
 *
 * Created: 30-Sep-23 12:14:28 PM
 *  Author: SEIF EL_DIN SULTAN 
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define SPI_MODE   SPI_Slave      // SPI_Master || SPI_Slave


#define  SPI_SS_PORT   DIO_PORTB
#define  SPI_SS_PIN	   DIO_PIN4

#define  SPI_MISO_PORT DIO_PORTB
#define  SPI_MISO_PIN  DIO_PIN6

#define  SPI_MOSI_PORT DIO_PORTB
#define  SPI_MOSI_PIN  DIO_PIN5

#define  SPI_SCLK_PORT DIO_PORTB
#define  SPI_SCLK_PIN  DIO_PIN7




#endif /* SPI_CONFIG_H_ */