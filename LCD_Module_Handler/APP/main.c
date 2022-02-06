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
#include "../HAL/LCD_Module/LCD_Config.h"
#include "../HAL/LCD_Module/LCD_Interface.h"
int main(void)
{
	PORT_VoidInit();
	LCD_VoidInit();
	LCD_VoidShiftRight(2,0,0);
	 //LCD_VoidCursorON();

	// LCD_VoidCursorOFF();

	 LCD_VoidBlinkingCursorON();

	 //LCD_VoidBlinkingCursorOFF();

    LCD_VoidSendString("mama helwa we doaa agmd awyee");




	return 0;

}
