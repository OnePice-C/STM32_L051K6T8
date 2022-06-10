#ifndef __LCD_H
#define __LCD_H

#include "main.h"
#include "stm32l0xx_hal.h"

/*******************************************************

							Dinh danh phan cung

********************************************************/

#define LCD_EN		GPIO_PIN_10
#define LCD_RW		GPIO_PIN_9
#define LCD_RS		GPIO_PIN_8

#define LCD_D4		GPIO_PIN_4
#define LCD_D5		GPIO_PIN_5
#define LCD_D6		GPIO_PIN_6
#define LCD_D7		GPIO_PIN_7

#define LCD_PORT_A 		 GPIOA

/*******************************************************

						Dinh nghia thiet lap muc logic 1

********************************************************/

#define LCD_EN_ON			HAL_GPIO_WritePin(LCD_PORT_A, LCD_EN, GPIO_PIN_SET)
#define LCD_RW_ON			HAL_GPIO_WritePin(LCD_PORT_A, LCD_RW, GPIO_PIN_SET)
#define LCD_RS_ON			HAL_GPIO_WritePin(LCD_PORT_A, LCD_RS, GPIO_PIN_SET)

/*******************************************************

						Dinh nghia thiet lap muc logic 0

********************************************************/

#define LCD_EN_OFF		HAL_GPIO_WritePin(LCD_PORT_A, LCD_EN, GPIO_PIN_RESET)
#define LCD_RW_OFF		HAL_GPIO_WritePin(LCD_PORT_A, LCD_RW, GPIO_PIN_RESET)
#define LCD_RS_OFF		HAL_GPIO_WritePin(LCD_PORT_A, LCD_RS, GPIO_PIN_RESET)

/*******************************************************

						Khai bao ham nguyen mau

********************************************************/

void Send_Bit( char sb);
void Send_Byte(char byte);
void Lcd_Cmd (char cmnd);
void Lcd_Data (char data);
void Lcd_Data_str(char *str);
void Lcd_Data_Num(int numble);
void Lcd_Init (void);
void Lcd_Goto(char x, char y);


#endif
