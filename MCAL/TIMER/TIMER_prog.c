/* source code:
 * Prerequisites : STD_Types.h , BIT_Math.h , TIMER_reg.h , TIMER_int.h
 * ***********************************************************************************/

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "TIMER_private.h"
#include "TIMER_reg.h"
#include "TIMER_int.h"
#include "TIMER_config.h"

static void (*TIMER0_OVF_PTR)(void)=NULL_PTR;
static void (*TIMER0_CTC_PTR)(void)=NULL_PTR;


void TIMER0_voidInit(void)
{
#if (TIMER0_u8_MODE == TIMER0_OVERFLOW_MODE)
	/* Normal Mode ( OverFlow Mode) Settings */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/* Prescaller Setting */
	TCCR0= TCCR0 & PRESCALLER_MASK;
	TCCR0= TCCR0 | TIMER0_u8_PRESCALLER;

	/* OverFlow Interrupt Enable */
	SET_BIT(TIMSK,TIMSK_TOIE0);

	/* Preload Initial Setting */
	TCNT0=TIMER0_u8_PRELOAD;

	/* Optional : OC0 Pin Configurations, Note: B3 Must be Output */
	/* To Make OC0 Pin ( B3 ) Toogle */
	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

#elif (TIMER0_u8_MODE == TIMER0_CTC_MODE)
	/* CTC Mode ( Clear Timer On Compare Match Mode ) Settings */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/* Prescaller Setting */
	TCCR0= TCCR0 & PRESCALLER_MASK;
	TCCR0= TCCR0 | TIMER0_u8_PRESCALLER;

	/* Compare Register Initial Setting */
	OCR0=TIMER0_COMPARE_REGISTER_INITAL_VALUE;

	/* CTC Interrupt Enable */
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/* Optional :OC0 Pin Configurations, Note: B3 Must be Output */
	/* To Make OC0 Pin ( B3 ) Toogle */
	/*SET_BIT(TCCR0,TCCR0_COM00);
		CLR_BIT(TCCR0,TCCR0_COM01);*/

#elif (TIMER0_u8_MODE == TIMER0_FAST_PWM_MODE)
	/* Fast PWM Mode Settings */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/* Prescaller Setting */
	TCCR0= TCCR0 & PRESCALLER_MASK;
	TCCR0= TCCR0 | TIMER0_u8_PRESCALLER;

	/* Compare Register Initial Setting */
	OCR0=TIMER0_COMPARE_REGISTER_INITAL_VALUE;

	#if (TIMER0_INVERTING_TYPE == TIMER0_INVERTING) /* SET OC0 Pin on Compare Match and CLR OC0 Pin on button ( overflow ) */
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);

	#elif (TIMER0_INVERTING_TYPE == TIMER0_NON_INVERTING) /* CLR OC0 Pin on Compare Match and SET OC0 Pin on button ( overflow ) */
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);

	#endif

#elif (TIMER0_u8_MODE == TIMER0_PHASE_CORRECT_PWM_MODE)
	/* Phase Correct PWM Mode Settings */
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/* Prescaller Setting */
	TCCR0= TCCR0 & PRESCALLER_MASK;
	TCCR0= TCCR0 | TIMER0_u8_PRESCALLER;

	/* Compare Register Initial Setting */
	OCR0=TIMER0_COMPARE_REGISTER_INITAL_VALUE;

	#if (TIMER0_INVERTING_TYPE == TIMER0_INVERTING) /* SET OC0 Pin on Compare Match and CLR OC0 Pin on button ( overflow ) */
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);

	#elif (TIMER0_INVERTING_TYPE == TIMER0_NON_INVERTING) /* CLR OC0 Pin on Compare Match and SET OC0 Pin on button ( overflow ) */
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);

	#endif

#endif

}

void TIMER0_voidSetPreloadValue(uint8_t Copy_u8PreloadValue)
{
	TCNT0=Copy_u8PreloadValue;
}

void TIMER0_voidSetCompareValue(uint8_t Copy_u8CompareValue)
{
	OCR0=Copy_u8CompareValue;
}

void TIMER0_SetCallBackOverflow(void (*PtrToFun)(void))
{
	TIMER0_OVF_PTR = PtrToFun;
}
void TIMER0_SetCallBackCTC(void (*PtrToFun)(void))
{
	TIMER0_CTC_PTR = PtrToFun;
}

void __vector_11(void) __attribute__((signal));

void __vector_11(void) // TIMER0 OverFlow ( Normal ) ISR
{
	if(TIMER0_OVF_PTR != NULL_PTR)
	{
		TIMER0_OVF_PTR();
	}
}

void __vector_10(void) __attribute__((signal));

void __vector_10(void) // TIMER0 CTC ( Compare Timer On Compare Match ) ISR
{
	if(TIMER0_CTC_PTR != NULL_PTR)
	{
		TIMER0_CTC_PTR();
	}
}
