/*main.c */

#define F_CPU 8000000

#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"

#include <utils/delay.h>

#include "SWPWM_int.h"

int main(void)
{
	SWPWM_init(10,50); // Frequency = 10Khz, DutyCycle = 50%
	SWPWM_start();
	
	_delay_ms(1000);
	
	SWPWM_changeDutyCycle(75); // 75% Duty Cycle
	
	_delay_ms(1000);
	
	while(1)
	{

	}

	return 0;
}