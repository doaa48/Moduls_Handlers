/*
 * PORT_Config.h
 *
 *  Created on: Sep 28, 2021
 *      Author: dell
 */

#ifndef STEPPER_MOTOR_CONFIG_H_
#define STEPPER_MOTOR_CONFIG_H_

enum Coils{
	 BlueCoil
	,PinkCoil
	,YellowCoil
	,OrangeCoil
		  };


/*PINS chosed in Hardware for ULN Pins*/
#define ULN_BASE_PIN0      PIN0
#define ULN_BASE_PIN1      PIN1
#define ULN_BASE_PIN2      PIN2
#define ULN_BASE_PIN3      PIN3
#define ULN_BASE_PIN4      PIN4
#define ULN_BASE_PIN5      PIN5
#define ULN_BASE_PIN6      PIN6


/*
 * then
 * PIN7 RIGHT for Emitter Common usualy GND
 * PIN8 LEFT for security from back EMF usualy Vcc
 *
 */

/*The port will be connected to Stepper Motor*/
#define STEPPER_MOTOR_PORT_CONNECT PORTD

/*No of Coil*/
#define COIL_NUM  (u8)4

#endif
