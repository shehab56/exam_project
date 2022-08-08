/* Gaurd */
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/* TIMER0 Prototypes */

void TIMER0_voidInit(void);

void TIMER0_voidSetPreloadValue(uint8_t Copy_u8PreloadValue);

void TIMER0_voidSetCompareValue(uint8_t Copy_u8CompareValue);

void TIMER0_SetCallBackOverflow(void (*PtrToFun)(void));
void TIMER0_SetCallBackCTC(void (*PtrToFun)(void));

/**************************************************************************************************/


#endif /* TIMER_INTERFACE_H_ */
