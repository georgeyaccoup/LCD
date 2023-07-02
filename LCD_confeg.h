/*
 * LCD_confeg.h
 *
 *  Created on: 26 Jun 2023
 *      Author: george yaccoup
 */

#ifndef LCD_CONFEG_H_
#define LCD_CONFEG_H_
#include "DIO_private.h"

#define LCD_MODE EIGHT_BIT_MODE

#define RS_GRP DIO_GROUP_B
#define RS_PIN DIO_PIN_1

#define Rw_GRP DIO_GROUP_B
#define Rw_PIN DIO_PIN_2

#define EN_GRP DIO_GROUP_B
#define EN_PIN DIO_PIN_3


#define D0_GRP DIO_GROUP_A
#define D0_PIN DIO_PIN_0

#define D1_GRP DIO_GROUP_A
#define D1_PIN DIO_PIN_1

#define D2_GRP DIO_GROUP_A
#define D2_PIN DIO_PIN_2
		
#define D3_GRP DIO_GROUP_A
#define D3_PIN DIO_PIN_3
		
#define D4_GRP DIO_GROUP_A
#define D4_PIN DIO_PIN_4
		
#define D5_GRP DIO_GROUP_A
#define D5_PIN DIO_PIN_5
		
#define D6_GRP DIO_GROUP_A
#define D6_PIN DIO_PIN_6

#define D7_GRP DIO_GROUP_A
#define D7_PIN DIO_PIN_7

#endif /* LCD_CONFEG_H_ */
