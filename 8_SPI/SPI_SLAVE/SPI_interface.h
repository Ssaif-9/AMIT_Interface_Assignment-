/*
 * SPI_interface.h
 *
 * Created: 30-Sep-23 12:14:16 PM
 *  Author: SEIF EL_DIN SULTAN 
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPI_Master   0
#define SPI_Slave    1

void SPI_init                  (void);
void SPI_Tranceive             (u8 TxData,u8* RxData);
void SPI_Receive               (u8* RxData);
void SPI_Transimite            (u8 TxData);
void SPI_TransimiteString      (u8* TxData);
void SPI_SetCallBack           (void(*PtrToFun)(void));
#endif /* SPI_INTERFACE_H_ */