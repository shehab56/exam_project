
* **************Description****************
*      Addresses
*
* Prerequisites : STD_Types.h
* *****************************************/

/***** Guard ***** To ensure every file is defined only once ***/
#ifndef DIO_REG_H_
#define DIO_REG_H_


typedef struct
{
    u8 PIND;
    u8 DDRD;
    u8 PORTD;

    u8 PINC;
    u8 DDRC;
    u8 PORTC;

    u8 PINB;
    u8 DDRB;
    u8 PORTB;

    u8 PINA;
    u8 DDRA;
    u8 PORTA;

}DIO_Registers;

#define DIO  ( (volatile DIO_Registers*) 0x30 )

#endif

/***** End of DIO_REG_H_ File *****/

