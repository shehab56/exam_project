/*/* source code:
 * Prerequisites : STD_Types.h , BIT_Math.h , DIO_int.h , TIMER_int.h , SWPWM_int.h
 * ***********************************************************************************/

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "../../MCAL/DIO_int.h"
#include "../../MCAL/TIMER_int.h"

#include "SWPWM_int.h"

void Timer0_OVF_ISR(void);

uint32_t Total_Period; // Total Number of Ticks to make a period
uint32_t T_ON_Counts;
uint32_t T_OFF_Counts;
uint8_t ON_OFF_Flag=1;

void SWPWM_init(uint32_t frequency_kh, uint8_t dutycycle)
{
	DIO_init(DIO_U8_PIN0,'A',OUT); // Pin A0 Out (Generated PWM)
	DIO_write(DIO_U8_PIN0,'A',LOW); // A0 LOW
	TIMER0_voidInit(); // Based on Timer Configurations (TIMER_config.h) OVF Mode, Prescaller=1 >> Timer_Frequency=8Mhz >> Tick_time=0.125 MicroSec
	TIMER0_SetCallBackOverflow(Timer0_OVF_ISR); // Call Back Function For OVF ISR
	Total_Period=1000/frequency_kh; // Total Number of Ticks to make a period
	T_ON_Counts=(dutycycle*Total_Period)/100;
	T_OFF_Counts=Total_Period-T_ON_Counts;
	T_ON_Counts=256-T_ON_Counts;
	T_OFF_Counts=256-T_OFF_Counts;
	TIMER0_voidSetPreloadValue(T_ON_Counts);
}

void SWPWM_start(void)
{
	ON_OFF_Flag=1; // Toggle Pin A0 in ISR
}

void SWPWM_changeDutyCycle(uint8_t newDutyCycle)
{
	T_ON_Counter=(dutycycle*Frequency_Counter)/100;
}

void SWPWM_stop(void)
{
	ON_OFF_Flag=0; // Stop Toggling Pin A0 in ISR
}

void Timer0_OVF_ISR(void)
{	
	static uint8_t flag=0;
	if(ON_OFF_Flag==1)
	{
		if(flag==0)
		{
			DIO_write(DIO_U8_PIN0,'A',HIGH); // A0 HIGH
			TIMER0_voidSetPreloadValue(T_ON_Counter);
			flag=1;
		}
		if(flag==1)
		{
			DIO_write(DIO_U8_PIN0,'A',LOW); // A0 LOW
			TIMER0_voidSetPreloadValue(T_OFF_Counts);
			flag=0;
		}
	}
	else
	{
		flag=0;
		DIO_write(DIO_U8_PIN0,'A',LOW); // A0 LOW
	}
}