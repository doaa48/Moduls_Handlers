/*
 * main.c
 *
 *  Created on: Sep 28, 2021
 *      Author: dell
 */
#include"util/delay.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../HAL/Stepper_Motor/Stepper_MOTOR_Config.h"
#include "../HAL/Stepper_Motor/Stepper_MOTOR_Private.h"
#include "../HAL/Stepper_Motor/Stepper_MOTOR_Interface.h"
int main(void)
{
	PORT_VoidInit();

u8 i;

	for (i=0;i<512;i++)
		{
		STEPPER_MOTOR_VidRotateClockWiseFullStep();
		}
	_delay_ms(100);
	STEPPER_MOTOR_VidStop();



	return 0;

}
