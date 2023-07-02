/*
 * LCD_program.c
 *
 *  Created on: 26 Jun 2023
 *      Author: george yaccoup
 */
#include "stdTypes.h"
#include "DIO_init.h"
#include "LCD_init.h"
#include "LCD_confeg.h"
#include "util/delay.h"
static void LCD_voidWriteByteLatch(u8 copy_u8Byte) {
#if LCD_MODE == EIGHT_BIT_MODE
	DIO_voidSetPinValue(Rw_GRP, Rw_PIN, DIO_LOW);
	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_LOW);

	DIO_voidSetPinValue(D7_GRP, D7_PIN, ((copy_u8Byte >> 7) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D6_GRP, D6_PIN, ((copy_u8Byte >> 6) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D5_GRP, D5_PIN, ((copy_u8Byte >> 5) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D4_GRP, D4_PIN, ((copy_u8Byte >> 4) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D3_GRP, D3_PIN, ((copy_u8Byte >> 3) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D2_GRP, D2_PIN, ((copy_u8Byte >> 2) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D1_GRP, D1_PIN, ((copy_u8Byte >> 1) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D0_GRP, D0_PIN, ((copy_u8Byte >> 0) & DIO_BIT_MASK));

	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_LOW);
	_delay_ms(2);
     #elif LCD_MODE == FOUR_BIT_MODE
	DIO_voidSetPinValue(Rw_GRP, Rw_PIN, DIO_LOW);
	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_LOW);

	DIO_voidSetPinValue(D7_GRP, D7_PIN, ((copy_u8Byte >> 7) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D6_GRP, D6_PIN, ((copy_u8Byte >> 6) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D5_GRP, D5_PIN, ((copy_u8Byte >> 5) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D4_GRP, D4_PIN, ((copy_u8Byte >> 4) & DIO_BIT_MASK));
	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_LOW);
	DIO_voidSetPinValue(D7_GRP, D7_PIN, ((copy_u8Byte >> 3) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D6_GRP, D6_PIN, ((copy_u8Byte >> 2) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D5_GRP, D5_PIN, ((copy_u8Byte >> 1) & DIO_BIT_MASK));
	DIO_voidSetPinValue(D4_GRP, D4_PIN, ((copy_u8Byte >> 0) & DIO_BIT_MASK));

	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_LOW);
	_delay_ms(2);
    #else
    #error LCD mode setting is wrong
    #endif
}


void LCD_voidInit() {
	_delay_ms(30);
	DIO_voidSetPinDirection(RS_GRP, RS_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(Rw_GRP, Rw_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(EN_GRP, EN_PIN, DIO_OUTPUT);

	DIO_voidSetPinDirection(D7_GRP, D7_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(D6_GRP, D6_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(D5_GRP, D5_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(D4_GRP, D4_PIN, DIO_OUTPUT);

    #if LCD_MODE == EIGHT_BIT_MODE
	DIO_voidSetPinDirection(D3_GRP, D3_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(D2_GRP, D2_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(D1_GRP, D1_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(D0_GRP, D0_PIN, DIO_OUTPUT);
	DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_LOW);
	LCD_voidWriteByteLatch(0X38);
    #elif LCD_MODE == FOUR_BIT_MODE
	DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_LOW);
	
	DIO_voidSetPinValue(D7_GRP, D7_PIN, 0);
	DIO_voidSetPinValue(D6_GRP, D6_PIN, 0);
	DIO_voidSetPinValue(D5_GRP, D5_PIN, 1);
	DIO_voidSetPinValue(D4_GRP, D4_PIN, 0);
	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_GRP, EN_PIN, DIO_LOW);
	_delay_ms(2);
	LCD_voidWriteByteLatch(0x28);
    #else
    #error LCD MODE Setting is wrong
    #endif
	DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_LOW);
	LCD_voidWriteByteLatch(0x0F);

	DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_LOW);
	LCD_voidWriteByteLatch(0x01);

	DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_LOW);
	LCD_voidWriteByteLatch(0x06);
	
}
void LCD_voidSendData(u8 copy_u8Data) {
	DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_HIGH);
	LCD_voidWriteByteLatch(copy_u8Data);
}
void LCD_voidSendCommand(u8 copy_u8Command) {
	DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_LOW);
	LCD_voidWriteByteLatch(copy_u8Command);
}
void LCD_voidWriteString(const char* copy_pcString) {
	while (*copy_pcString != '\0') {
		DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_HIGH);
		LCD_voidWriteByteLatch(*copy_pcString++);
	}
}
void LCD_voidWriteNum(s32 copy_s32Num) {
	if (copy_s32Num == 0) {
		DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_HIGH);
		LCD_voidWriteByteLatch('0');
	}
	else if (copy_s32Num < 0) {
		DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_HIGH);
		LCD_voidWriteByteLatch('-');
		copy_s32Num *= -1;
	}
	u8 local_u8NumOfDegits = LCD_u8Counter(copy_s32Num)-1;
	u8 local_u8Degits[12] = { 0 };
	for (s8 local_s8LoopCounter = local_u8NumOfDegits; local_s8LoopCounter >= 0; local_s8LoopCounter--) {
		local_u8Degits[local_s8LoopCounter] = (copy_s32Num % 10) + '0';
		copy_s32Num /= 10;
	}
	for (s8 local_s8LoopCounter = 0; local_s8LoopCounter < 12; local_s8LoopCounter++) {
		DIO_voidSetPinValue(RS_GRP, RS_PIN, DIO_HIGH);
		LCD_voidWriteByteLatch(local_u8Degits[local_s8LoopCounter]);
	}
}
void LCD_voidWriteFloat(s32 copy_s32Float)
{
}
void LCD_voidWriteFloat(s32 copy_s32Float);
u8 LCD_u8Counter(s32 copy_s32Num) {
	u8 Local_u8Counter = 0;
	while (copy_s32Num > 0) {
		copy_s32Num /= 10;
		Local_u8Counter++;
	}
	return Local_u8Counter;
}
