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
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../HAL/DC_MOTOR/DC_MOTOR_Config.h"
#include "../HAL/DC_MOTOR/DC_MOTOR_Interface.h"
int main(void)
{
	PORT_VoidInit();


while(1){
DC_MOTOR_VidRotateClockWise();
  _delay_ms(2000);

 DC_MOTOR_VidRotateUntiClockWise();
	_delay_ms(2000);
}

	return 0;

}
