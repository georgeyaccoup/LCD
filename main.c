/*
 * main.c
 *
 *  Created on: 26 Jun 2023
 *      Author: george yaccoup
 */
#include "DIO_private.h"
#include "LCD_init.h"
#include "DIO_confeg.h"
#include <util/delay.h>

void main(void){
	LCD_voidInit();
	while (1) {
		for (int i = 0; i < 10; i++) {
			LCD_voidWriteNum(i);
			LCD_voidWriteString(" ");
		}
		LCD_voidWriteString("george yaccoup");
	}
	

}
