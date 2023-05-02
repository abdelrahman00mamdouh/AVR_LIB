/*
 * BIT_MATH.h
 *
 *  Created on: Jan 31, 2023
 *      Author: AMIT
 */
#include <../include/util/delay.h>


#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define  Set_bit(Register_Name,Shift_Step)		(Register_Name)|=(1<<Shift_Step)
#define  Clr_bit(Register_Name,Shift_Step)		(Register_Name)&=~(1<<Shift_Step)
#define  Toggle_bit(Register_Name,Shift_Step)	(Register_Name)^=(1<<Shift_Step)
#define  Get_bit(Register_Name,Shift_Step)		((Register_Name>>Shift_Step)&0x01)


#endif /* LIB_BIT_MATH_H_ */
