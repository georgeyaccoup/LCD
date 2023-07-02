/*
 * LCD_init.h
 *
 *  Created on: 26 Jun 2023
 *      Author: george yaccoup
 */

#ifndef LCD_INIT_H_
#define LCD_INIT_H_
#include "stdTypes.h"


void LCD_voidInit();
void LCD_voidSendData(u8 copy_u8Data);
void LCD_voidSendCommand(u8 copy_u8Command);
void LCD_voidWriteString(const char* copy_pcString);
void LCD_voidWriteNum(s32 copy_s32Num);
void LCD_voidWriteFloat(s32 copy_s32Float);
u8 LCD_u8Counter(s32 copy_s32Num);

#endif /* LCD_INIT_H_ */
