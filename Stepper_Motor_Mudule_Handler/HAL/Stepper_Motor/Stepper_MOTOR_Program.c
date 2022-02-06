/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */
#include "util/delay.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "../../MCAL/DIO_Driver/DIO_REG.h"
#include "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "Stepper_MOTOR_Config.h"
#include "Stepper_MOTOR_Private.h"
#include "Stepper_MOTOR_Interface.h"



/*if you want to rotate the motor clockwise*/
void STEPPER_MOTOR_VidRotateClockWiseFullStep(void)
{
	u8 Local_CoilIterator1;
	u8 Local_CoilIterator2;
  for(Local_CoilIterator1=BlueCoil; Local_CoilIterator1<=OrangeCoil ;Local_CoilIterator1++)
	{
	  DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,Local_CoilIterator1,HIGH);
	  for(Local_CoilIterator2=Local_CoilIterator1+1; Local_CoilIterator2<=OrangeCoil ;Local_CoilIterator2++)
	  {
		  DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,Local_CoilIterator2,LOW);
	  }
	  _delay_ms(2);
	  DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,Local_CoilIterator1,LOW);

	}
}

/*if you want to rotate the motor unti_clockwise*/
void STEPPER_MOTOR_VidRotateUntiClockWiseFullStep(void)
{
	s8 Local_CoilIterator1;
	s8 Local_CoilIterator2;
	  for(Local_CoilIterator1=OrangeCoil; Local_CoilIterator1>=BlueCoil ;Local_CoilIterator1--)
		{
		  DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,Local_CoilIterator1,HIGH);
		  for(Local_CoilIterator2=Local_CoilIterator1-1; Local_CoilIterator2>=BlueCoil ;Local_CoilIterator2--)
		  {
			  DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,Local_CoilIterator2,LOW);
		  }
		  _delay_ms(2);
		  DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,Local_CoilIterator1,LOW);

		}


}

/*if you want to rotate the motor clockwise in half step mode*/
void STEPPER_MOTOR_VidRotateClockWiseHalfStep(void)
{
	    DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,HIGH);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);

		_delay_ms(2);

		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,HIGH);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,HIGH);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);
		_delay_ms(2);

		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,HIGH);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);
		_delay_ms(2);

	    DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,HIGH);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,HIGH);
		DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);
	    _delay_ms(2);

         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,HIGH);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);

         _delay_ms(2);

         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,HIGH);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,HIGH);
         _delay_ms(2);

         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,HIGH);
         _delay_ms(2);

         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,HIGH);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
         DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,HIGH);
}
/*if you _delay_ms(5);                                               */
void STEPPER_MOTOR_VidRotateUntiClockWiseHalfStep(void)
{
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,HIGH);

	_delay_ms(2);

	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,HIGH);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,HIGH);
	_delay_ms(2);

	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,HIGH);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);
	_delay_ms(2);

	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,HIGH);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,HIGH);
	DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);
	_delay_ms(2);

	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,LOW);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,HIGH);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);

	 _delay_ms(2);

	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,HIGH);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,HIGH);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);
	 _delay_ms(2);

	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,HIGH);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,LOW);
	 _delay_ms(2);

	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,BlueCoil  ,HIGH);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,PinkCoil  ,LOW);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,YellowCoil,LOW);
	 DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,OrangeCoil,HIGH);
}


/*f you want to stop the motor from moving*/
void  STEPPER_MOTOR_VidStop(void)

{    u8 Local_CoilIterator1;
	 for(Local_CoilIterator1=BlueCoil; Local_CoilIterator1<=OrangeCoil ;Local_CoilIterator1++)
			  {
				  DIO_U8SetPinVal(STEPPER_MOTOR_PORT_CONNECT,Local_CoilIterator1,LOW);
			  }
}

/*to define the Angle of rotation Required*/
u8 STEPPER_MOTOR_u8CalcAngle(f32 Copy_f32StepAngleRequired)
{
	u8 Local_NumberOfSteps=Copy_f32StepAngleRequired/STRIDE_ANGLE;
	return Local_NumberOfSteps/4;
}









