/*
 * INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef STEPPER_MOTOR_INTERFACE_H_
#define STEPPER_MOTOR_INTERFACE_H_


/*if you want to rotate the motor clockwise in full step mode*/
void STEPPER_MOTOR_VidRotateClockWiseFullStep(void);

/*if you want to rotate the motor unti_clockwise in full step mode*/
void STEPPER_MOTOR_VidRotateUntiClockWiseFullStep(void);

/*if you want to rotate the motor clockwise in half step mode*/
void STEPPER_MOTOR_VidRotateClockWiseHalfStep(void);

/*if you want to rotate the motor unti_clockwise in half step mode*/
void STEPPER_MOTOR_VidRotateUntiClockWiseHalfStep(void);

/*f you want to stop the motor from moving*/
void STEPPER_MOTOR_VidStop(void);

/*to define the Angle of rotation Required*/
u8 STEPPER_MOTOR_u8CalcAngle(f32 Copy_f32StepAngleRequired);

#endif
