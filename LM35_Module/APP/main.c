//#include"avr/io.h"
//#include"avr/interrupt.h"
/*
#include"avr/io.h"
#include"avr/interrupt.h"
#include "../LIB/BIT_MATH.h"
#include"util/delay.h"


#define Angle_0_tickis 400
#define Angle_180_tickis 2600
void main(void)
{
  unsigned short int angle_tickes;
DDRD|=(1<<5);
TCCR1A|=(1<<COM1A1);
TCCR1A&=~(1<<WGM10);
TCCR1A|=(1<<WGM11);
TCCR1B|=(1<<WGM12)|(1<<WGM13);

TCCR1B|=(1<<CS11);
ICR1=20000;


while (1)
{
for( angle_tickes=Angle_0_tickis;angle_tickes<Angle_180_tickis;angle_tickes+=10)
{
  OCR1A=angle_tickes;
  _delay_ms(40);
}


for( angle_tickes=Angle_180_tickis;angle_tickes>Angle_0_tickis;angle_tickes-=10)
{
  OCR1A=angle_tickes;
  _delay_ms(40);
}

}

}*/
//#include"util/delay.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Interface.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Config.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/GIE_Driver/GIE_REG.h"
#include "../MCAL/GIE_Driver/GIE_Interface.h"
#include "../HAL/LCD_Module/LCD_Config.h"
#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../MCAL/Timer_Driver/Timer_REG.h"
#include "../MCAL/Timer_Driver/Timer_Interface.h"
#include "../MCAL/Timer_Driver/Timer_Config.h"
/*
void __vector_10 (void)  __attribute__((signal)) ;
void __vector_10 (void)
{
 static char counter=0;
 counter++;
 if(counter==50)
 {
  TOG_BIT(PORTA,0);
  counter=0;
 }
}*/

#define FIRST_RISING   0
#define RISING_2       1
#define FALLING_2      2

u16 Period_Time_Ticks;
u16 Ton_Time_Ticks;

int main(void)
{
PORT_VoidInit();
LCD_VoidInit();
TMR1_VoidInit_Prebuild();
TMR0_VoidInit_Prebuild();
EXTI_VidEnableOrDisableGIE(ENABLE);


u8 TON_T,T_Total,Duty,Freq;

while (1)
{





	    TON_T=(2/15625)*Ton_Time_Ticks;
	     T_Total=(2/15625)*Period_Time_Ticks;
	     Duty=(TON_T/T_Total)*100;
	     Freq=1/T_Total;

	     LCD_VoidSendString("Duty");
	      LCD_VoidSendNumber(Duty);
	      LCD_VoidSendString("Freq");
	      LCD_VoidSendNumber(Freq);


}





return 0;

}

void ICU_HW(void)
{

static u16 Local_u16Recording1;
static u16 Local_u16Recording2;
static u16 Local_u16Recording3;
static u8 Local_u8FlagState =FIRST_RISING;

   if( Local_u8FlagState ==FIRST_RISING)
{
	Local_u16Recording1=TMR1_VoidReadInputCapture();
	Local_u8FlagState=RISING_2;
}
else if(Local_u8FlagState==RISING_2)
{
	Local_u16Recording2=TMR1_VoidReadInputCapture();
 	Period_Time_Ticks=Local_u16Recording2-Local_u16Recording1;

	TMR1_VoidSetInputCaptureEdge(CAPTURE_EDGE_DETECTION_FALLING);
	 Local_u8FlagState=FALLING_2;

}
else if(Local_u8FlagState ==FALLING_2)
{
	Local_u16Recording3=TMR1_VoidReadInputCapture();
 	Ton_Time_Ticks=Local_u16Recording3-Local_u16Recording2;

}
}

void ICU_SW(void)
{
static u8 PWM_state=FIRST_RISING;

if(PWM_state ==FIRST_RISING)
{
	 TMR1_VoidResetTimer();
	 EXTI_u8ControlSense_Postbuild(INT0,FALLING_EDGE);
	 PWM_state=FALLING_2;
}
else if(PWM_state ==FALLING_2)
{
	Ton_Time_Ticks=TMR1_VoidGetTimerVal();
	EXTI_u8ControlSense_Postbuild(INT0,RISING_EDGE);
	  PWM_state=RISING_2;

}
else if(PWM_state ==RISING_2)
{
 	Ton_Time_Ticks=TMR1_VoidGetTimerVal();
	 TMR1_VoidResetTimer();
	 EXTI_u8ControlSense_Postbuild(INT0,FALLING_EDGE);
 	PWM_state=FALLING_2;

}

}
