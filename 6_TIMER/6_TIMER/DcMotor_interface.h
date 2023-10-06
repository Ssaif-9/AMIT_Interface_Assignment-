/*
 * DcMotor_interface.h
 *
 * Created: 24-Sep-23 3:44:18 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#define DcMotor_MOTOR_A                      0
#define DcMotor_MOTOR_B                      1

#define DcMotor_CLOCK_WISE                   0
#define DcMotor_COUNTER_CLOCK_WISE           1


void DcMotor_init                            (u8 MotorId);
void DcMotor_ON                              (u8 MotorId, u8 MotorDirection);
void DcMotor_ONControlSpeed                  (u8 MotorId, u8 MotorDirection, u8 MotorSpeed);
void DcMotor_OFF                             (u8 MotorId);


#endif /* DCMOTOR_INTERFACE_H_ */