#include "main.h"
#include "stm32l0xx_hal.h"
#include "lcd_16x2.h"


/*******************************************************
						Ham gui 4 bit vao Lcd
********************************************************/

void Send_Bit( char sb)
{
	int logic;		// luu muc logic truyen vao pin D4 -> D7
	LCD_EN_ON;
	HAL_GPIO_WritePin(LCD_PORT_A, LCD_D4, logic = ((sb >> 4) & 0x01) ? 1 : 0);
	HAL_GPIO_WritePin(LCD_PORT_A, LCD_D5, logic = ((sb >> 5) & 0x01) ? 1 : 0);
	HAL_GPIO_WritePin(LCD_PORT_A, LCD_D6, logic = ((sb >> 6) & 0x01) ? 1 : 0);
	HAL_GPIO_WritePin(LCD_PORT_A, LCD_D7, logic = ((sb >> 7) & 0x01) ? 1 : 0);
	LCD_EN_OFF;
}

/*******************************************************
						Ham gui 8 bit vao Lcd
********************************************************/

void Send_Byte( char byte)
{
	Send_Bit(byte);
	Send_Bit(byte << 4);
	HAL_Delay(1);
}

/*******************************************************
						Gui lenh vao Lcd
********************************************************/

void Lcd_Cmd (char cmnd)
{
	LCD_RW_OFF;				// RW = 0 de ghi khong doc LCD		
	LCD_RS_OFF;				// RS = 0 de ghi lenh
	Send_Byte(cmnd);
	HAL_Delay(1);
}

/*******************************************************
						Gui du lieu vao Lcd ( 1 ky tu)
********************************************************/

void Lcd_Data (char data)
{
	LCD_RW_OFF;							
	LCD_RS_ON;				// RS = 1 de ghi du lieu
	Send_Byte(data);
	HAL_Delay(1);
}

/*******************************************************
						Gui 1 chuoi ky tu ra Lcd 
********************************************************/

void Lcd_Data_str(char *str)
{
	while( *str)
	{
		Lcd_Data(*str);
		str++;
	}
}

/*******************************************************
						Gui so ra Lcd 
********************************************************/

void Lcd_Data_Num(int numble)
{
	int donvi =(((numble%1000)%100)%10)/1,
			chuc  =((numble%1000)%100)/10,
			tram  = (numble%1000)/100,
			nghin = numble/1000;
	
	if ( numble >= 1000)
		Lcd_Data(48 + nghin);
	if ( numble >= 100)
		Lcd_Data(48 + tram);
	if( numble >= 10)
		Lcd_Data(48 + chuc);
	if( numble >= 0)
		Lcd_Data(48 + donvi);
}

/*******************************************************
						 di chuyen den toa do x, y 
********************************************************/

void Lcd_Goto( char x, char y)
{
	if(y == 1)
		Lcd_Cmd(0x80 | x - 1);
	if(y == 2)
		Lcd_Cmd(0xC0 | x - 1);	
}

/*******************************************************
						 Khoi tao Lcd 
********************************************************/

void Lcd_Init (void)
{
	Lcd_Cmd(0x28);									// khoi tao Lcd 4 bit, 2 dong, 5x7
	Lcd_Cmd(0x0C);									// bat hien thi, tat con tro
	Lcd_Cmd(0x02);									// dua con tro ve dau man hinh
	Lcd_Cmd(0x01);									// xoa toan bo man hinh
	
}
