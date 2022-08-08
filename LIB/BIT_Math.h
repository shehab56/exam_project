/*
* **************Description****************
*      Function Like Macro
*
* Prerequisites : None
* *****************************************/

/***** Guard ***** To ensure every file is defined only once ***/
#ifndef BIT_Math_H_
#define BIT_Math_H_

#define SET_BIT(REG,Index)  (REG |= (1 << Index))
#define CLR_BIT(REG,Index)	(REG &= ~(1 << Index))
#define TGL_BIT(REG,Index)  (REG ^= (1 << Index))
#define GET_BIT(REG,Index)  ((REG >> Index) & 1)

#define ASSIGN_BIT(REG,Index,Value)  ( REG = ( REG & (~(1<<Index)) ) | (Value<<Index) )

#endif
/***** End of BIT_Math_H_ File *****/
