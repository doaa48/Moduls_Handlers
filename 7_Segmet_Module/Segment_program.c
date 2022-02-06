/*
 * Segment_interface.c

 *
 *  Created on: Sep 19, 2021
 *      Author: dell
 */
#include "BIT_MATH.h"
#include "STDTYPES.h"
#include <stdio.h>
#include "DIO_REG.h"
#include "DIO_Interface.h"
#include "Segment_interface.h"
#include "Segment7_Config.h"


u8 SEG_7_U8CountingUpOrDown (Segment_7_Config *Copy_Config)

{
u8 Local_Status=RT_OK;
 if((Copy_Config->Copy_u8Start<0)||(Copy_Config->Copy_u8Start>9)||(Copy_Config->Copy_u8End<0)||(Copy_Config->Copy_u8End>9)||Copy_Config->Copy_PortNo<0||Copy_Config->Copy_PortNo>3)
{
	Local_Status=RT_NOK;
}
else
{
	#if SEGMENT_TYPE == CATHODE
	{
	if(Copy_Config->Copy_u8UpOrDown==COUNT_UP)
	{
		switch(Copy_Config->Copy_PortNo)
		{
		case 0:
			{
				for(u8 i=Copy_Config->Copy_u8Start;i<=Copy_Config->Copy_u8End;i++)
						{

						    DDRA_REG=0xFF;
							PORTA_REG=Segment[i];
						}
				break;


			}
		case 1:
			{
				for(u8 i=Copy_Config->Copy_u8Start;i<=Copy_Config->Copy_u8End;i++)
						{

					 	 	 DDRB_REG=0xFF;
							PORTB_REG=Segment[i];
						}
				break;


			}
		case 2:
			{
				for(u8 i=Copy_Config->Copy_u8Start;i<=Copy_Config->Copy_u8End;i++)
						{

					        DDRC_REG=0xFF;
							PORTC_REG=Segment[i];
						}
				break;


			}
		case 3:
			{
				for(u8 i=Copy_Config->Copy_u8Start;i<=Copy_Config->Copy_u8End;i++)
						{
					 	 	 DDRA_REG=0xFF;
					 	 	 PORTD_REG=Segment[i];
						}
				break;


			}
		}

	}
	else if(Copy_Config->Copy_u8UpOrDown==COUNT_DOWN)
			{
				switch(Copy_Config->Copy_PortNo)
				{
				case 0:
					{
						for(u8 i=Copy_Config->Copy_u8Start;i>=Copy_Config->Copy_u8End;i--)
								{
							        DDRA_REG=0xFF;
									PORTA_REG=Segment[i];
								}
						break;


					}
				case 1:
					{
						for(u8 i=Copy_Config->Copy_u8Start;i>=Copy_Config->Copy_u8End;i--)
								{
							        DDRB_REG=0xFF;
							        PORTB_REG=Segment[i];
								}
						break;


					}
				case 2:
					{
						for(u8 i=Copy_Config->Copy_u8Start; i>=Copy_Config->Copy_u8End;i--)
								{
									DDRC_REG=0xFF;
									PORTC_REG=Segment[i];
								}
						break;


					}
				case 3:
					{
						for(u8 i=Copy_Config->Copy_u8Start;i>=Copy_Config->Copy_u8End;i--)
								{
									DDRA_REG=0xFF;
									PORTD_REG=Segment[i];
								}
						break;


					}
				}

			}
          #elif SEGMENT_TYPE==ANODE
	{
		if(Copy_Config->Copy_u8UpOrDown==COUNT_UP)
		{
			switch(Copy_Config->Copy_PortNo)
			{
			case 0:
				{
					for(u8 i=Copy_Config->Copy_u8Start;i<=Copy_Config->Copy_u8End;i++)
							{

						        DDRA_REG=0xFF;
								PORTA_REG=~Segment[i];
							}
					break;


				}
			case 1:
				{
					for(u8 i=Copy_Config->Copy_u8Start;i<=Copy_Config->Copy_u8End;i++)
							{

								DDRB_REG=0xFF;
								PORTB_REG=~Segment[i];
							}
					break;


				}
			case 2:
				{
					for(u8 i=Copy_Config->Copy_u8Start;i<=Copy_Config->Copy_u8End;i++)
							{
								 DDRC_REG=0xFF;
								 PORTC_REG=~Segment[i];
							}
					break;


				}
			case 3:
				{
					for(u8 i=Copy_Config->Copy_u8Start;i<=Copy_Config->Copy_u8End;i++)
							{
								 DDRD_REG=0xFF;
								 PORTD_REG=~Segment[i];
							}
					break;


				}
			}

		}
		else if(Copy_Config->Copy_u8UpOrDown==COUNT_DOWN)
				{
					switch(Copy_Config->Copy_PortNo)
					{
					case 0:
						{
							for(u8 i=Copy_Config->Copy_u8Start;i>=Copy_Config->Copy_u8End;i--)
									{

										DDRA_REG=0xFF;
										PORTA_REG=~Segment[i];
									}
							break;


						}
					case 1:
						{
							for(u8 i=Copy_Config->Copy_u8Start;i>=Copy_Config->Copy_u8End;i--)
									{

											DDRB_REG=0xFF;
											PORTB_REG=~Segment[i];
									}
							break;


						}
					case 2:
						{
							for(u8 i=Copy_Config->Copy_u8Start; i>=Copy_u8End;i--)
									{

										 DDRC_REG=0xFF;
										 PORTC_REG=~Segment[i];
									}
							break;


						}
					case 3:
						{
							for(u8 i=Copy_Config->Copy_u8Start;i>=Copy_Config->Copy_u8End;i--)
									{
										 DDRD_REG=0xFF;
										 PORTD_REG=~Segment[i];
									}
							break;


						}
					}

				}
#endif
	}

	}
	return Local_Status;
}

u8 SEG_7_U8SetSegmentNo (Segment_7_Config *Copy_Config)
	{
		u8 Local_Status=RT_OK;
		if((Copy_Config->Copy_SEG_NO<0)||(Copy_Config->Copy_SEG_NO>9)||Copy_Config->Copy_PortNo<0||Copy_Config->Copy_PortNo>3)
		{
			Local_Status=RT_NOK;
		}
		else
		{
        #if SEGMENT_TYPE==CATHODE
			{
				switch(Copy_Config->Copy_PortNo)
						{
						case 0:{  DDRA_REG=0xFF;PORTA_REG=Segment[Copy_Config->Copy_SEG_NO];break;}
						case 1:{  DDRB_REG=0xFF;PORTB_REG=Segment[Copy_Config->Copy_SEG_NO];break;}
						case 2:{  DDRC_REG=0xFF;PORTC_REG=Segment[Copy_Config->Copy_SEG_NO];break;}
						case 3:{  DDRD_REG=0xFF;PORTD_REG=Segment[Copy_Config->Copy_SEG_NO];break;}
						}
			}
       #elif SEGMENT_TYPE==ANODE
			{
				switch(*Copy_Config->Copy_PortNo)
				{
						case 0:{  DDRA_REG=0xFF;PORTA_REG=~Segment[Copy_Config->Copy_SEG_NO];break;}
						case 1:{  DDRB_REG=0xFF;PORTB_REG=~Segment[Copy_Config->Copy_SEG_NO];break;}
						case 2:{  DDRC_REG=0xFF;PORTC_REG=~Segment[Copy_Config->Copy_SEG_NO];break;}
						case 3:{  DDRD_REG=0xFF;PORTD_REG=~Segment[Copy_Config->Copy_SEG_NO];break;}
				}
			}
    #endif
		}


return Local_Status;
}

u8 SEG_7_U8ClearSegmentNo(Segment_7_Config *Copy_Config)
{

	u8 Local_Status=RT_OK;
			if((Copy_Config->Copy_SEG_NO<0)||(Copy_Config->Copy_SEG_NO>9)||Copy_Config->Copy_PortNo<0||Copy_Config->Copy_PortNo>3)
			{
				Local_Status=RT_NOK;
			}
			else
			{
	        #if SEGMENT_TYPE==CATHODE
				{
					switch(Copy_Config->Copy_PortNo)
							{
							case 0:{ DDRA_REG=0xFF;PORTA_REG=0x00;break;}
							case 1:{ DDRB_REG=0xFF;PORTB_REG=0x00;break;}
							case 2:{ DDRC_REG=0xFF;PORTC_REG=0x00;break;}
							case 3:{ DDRD_REG=0xFF;PORTD_REG=0x00;break;}
							}
				}
	       #elif SEGMENT_TYPE==ANODE
				{
					switch(Copy_Config->Copy_PortNo)
					{
					case 0:{  DDRA_REG=0xFF;PORTA_REG=0xFF;break;}
					case 1:{  DDRB_REG=0xFF;PORTB_REG=0xFF;break;}
					case 2:{  DDRC_REG=0xFF;PORTC_REG=0xFF;break;}
					case 3:{  DDRD_REG=0xFF;PORTD_REG=0xFF;break;}
					}
				}
	    #endif
			}
	return Local_Status;
}


