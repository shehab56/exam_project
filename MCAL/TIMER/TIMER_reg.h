/* Gaurd */
#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/* TIMER0 Registers */

/* Timer/Counter 0 Control Register */
#define TCCR0 		*((volatile u8*)0x53)

/* Mode Selection */
#define TCCR0_WGM00		6 
#define TCCR0_WGM01		3 

/* OC0 Pin Options */
#define TCCR0_COM00		4
#define TCCR0_COM01		5

/* TIMER0_Register (Counter) */
#define TCNT0 		*((volatile u8*)0x52)

/* Timer MASK Rgister */
#define TIMSK 		*((volatile u8*)0x59)

#define TIMSK_TOIE0		0 /* Timer 0 OverFlow Interrupt Enable */
#define TIMSK_OCIE0		1 /* Timer 0 Compare  Interrupt Enable */

/* TIMER0 Compare Register */
#define OCR0 		*((volatile u8*)0x5C)

#endif /* TIMER_REGISTER_H_ */
