#include "HC595.h"
#include "main.h"
#include "stm32l0xx_hal.h"

/*********************************************************
					Ham truyen 2 byte vao Hc595
*********************************************************/

void Data_Double(uint16_t dt)
{
	uint16_t temp;
	temp = dt;
	for(int i=0; i<16; i++)
	{
		if (temp & 0x8000)
		{
			HC_SDA_ON;
		}
		else
		{
			HC_SDA_OFF;
		}
		
		serialclock();
		temp = temp << 1;
	}	
}

/*********************************************************
								Ham truyen 1 byte vao Hc595
*********************************************************/

void Data_Byte (uint8_t dt)
{
	uint8_t temp;
	temp = dt;
	for(int i=0; i<8; i++)
	{
		if (temp & 0x80)
		{
			HC_SDA_ON;
		}
		else
		{
			HC_SDA_OFF;
		}
		
		serialclock();
		temp = temp << 1;
	}	
}

/*********************************************************
	tao xung clock ghi 1 bit logic vao chan Hc595 tuong ung
*********************************************************/

void serialclock()
{
	HC_SCK_ON;
	HAL_Delay(1);
	HC_SCK_OFF;
}

/*********************************************************
					Cap nhap du lieu cho Hc595
*********************************************************/

void serialLat()
{
	
	HC_LAT_ON;
	HAL_Delay(1);
	HC_LAT_OFF;
}
