/*
* **************Description****************
*      Functions Prototypes
*
* Prerequisites : STD_Types.h , Error_State.h
* *****************************************/

/***** Guard ***** To ensure every file is defined only once ***/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_U8_PIN0 0
#define DIO_U8_PIN1 1
#define DIO_U8_PIN2 2
#define DIO_U8_PIN3 3
#define DIO_U8_PIN4 4
#define DIO_U8_PIN5 5
#define DIO_U8_PIN6 6
#define DIO_U8_PIN7 7

#define DIO_U8_PIN8 8
#define DIO_U8_PIN9 9
#define DIO_U8_PIN10 10
#define DIO_U8_PIN11 11
#define DIO_U8_PIN12 12
#define DIO_U8_PIN13 13
#define DIO_U8_PIN14 14
#define DIO_U8_PIN15 15

#define DIO_U8_PIN16 16
#define DIO_U8_PIN17 17
#define DIO_U8_PIN18 18
#define DIO_U8_PIN19 19
#define DIO_U8_PIN20 20
#define DIO_U8_PIN21 21
#define DIO_U8_PIN22 22
#define DIO_U8_PIN23 23

#define DIO_U8_PIN24 24
#define DIO_U8_PIN25 25
#define DIO_U8_PIN26 26
#define DIO_U8_PIN27 27
#define DIO_U8_PIN28 28
#define DIO_U8_PIN29 29
#define DIO_U8_PIN30 30
#define DIO_U8_PIN31 31

/* Direction */
#define OUT 1
#define IN  0

/* Value */
#define HIGH 1
#define LOW  0


void DIO_init(uint8_t pinNumber, uint8_t port, uint8_t direction); /* Options: OUTPUT or INPUT for  pin */

void DIO_write(uint8_t pinNumber, uint8_t port, uint8_t value); /* Option: HIGH or LOW for Pin */

void DIO_toogle(uint8_t pinNumber, uint8_t port); 


#endif

/***** End of DIO_INTERFACE_H_ File *****/

