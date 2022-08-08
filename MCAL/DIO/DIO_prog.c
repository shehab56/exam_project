/*
* **************Description****************
*      Source Code
*
* Prerequisites : STD_Types.h , BIT_Math.h , DIO_reg.h , DIO_int.h
* ***********************************************************************************/

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "DIO_reg.h"
#include "DIO_int.h"


/************************** Set Pin Direction ******************************/
void DIO_init(uint8_t pinNumber, uint8_t port, uint8_t direction);
{
	switch(port)
	{
		case 'A':
			ASSIGN_BIT(DIO->DDRA,pinNumber,direction);
			break;
		case 'B':
			ASSIGN_BIT(DIO->DDRB,pinNumber,direction);
			break;
		case 'C':
			ASSIGN_BIT(DIO->DDRC,pinNumber,direction);
			break;
		case 'D':
			ASSIGN_BIT(DIO->DDRD,pinNumber,direction);
			break;
	}
}

/********************************** Set Pin Value ************************************/
void DIO_write(uint8_t pinNumber, uint8_t port, uint8_t value); /* Option: HIGH or LOW for Pin */
{
    switch( port )
        {
            case 'A':
                ASSIGN_BIT(DIO->PORTA,pinNumber,value);
                break;
            case 'B':
                ASSIGN_BIT(DIO->PORTB,pinNumber,value);
                break;
            case 'C':
                ASSIGN_BIT(DIO->PORTC,pinNumber,value);
                break;
            case 'D':
                ASSIGN_BIT(DIO->PORTD,pinNumber,value);
                break;
		}
}

/*************************** TOOGLE PIN *************************************/
void DIO_toogle(uint8_t pinNumber, uint8_t port)
{

    switch( port )
		{
            case 'A':
                TGL_BIT(DIO->PORTA,pinNumber);
                break;
            case 'B':
                TGL_BIT(DIO->PORTB,pinNumber);
                break;
            case 'C':
                TGL_BIT(DIO->PORTC,pinNumber);
                break;
            case 'D':
                TGL_BIT(DIO->PORTD,pinNumber);
                break;
        }
}
