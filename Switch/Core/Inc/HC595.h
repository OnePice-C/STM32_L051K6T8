#ifndef __HC595_H
#define __HC595_H

#include "main.h"
#include "stm32l0xx_hal.h"

/*********************************************************
							Dinh danh phan cung
*********************************************************/

#define HC_SDA					GPIO_PIN_5
#define HC_SCK					GPIO_PIN_6
#define HC_LAT					GPIO_PIN_7

#define HC_PORT_B			GPIOB

/*********************************************************
							Dinh nghia muc logic 1
*********************************************************/

#define HC_SDA_ON				HAL_GPIO_WritePin(HC_PORT_B, HC_SDA, GPIO_PIN_SET)
#define HC_SCK_ON				HAL_GPIO_WritePin(HC_PORT_B, HC_SCK, GPIO_PIN_SET)
#define HC_LAT_ON				HAL_GPIO_WritePin(HC_PORT_B, HC_LAT, GPIO_PIN_SET)

/*********************************************************
							Dinh nghia muc logic 0
*********************************************************/

#define HC_SDA_OFF				HAL_GPIO_WritePin(HC_PORT_B, HC_SDA, GPIO_PIN_RESET)
#define HC_SCK_OFF				HAL_GPIO_WritePin(HC_PORT_B, HC_SCK, GPIO_PIN_RESET)
#define HC_LAT_OFF				HAL_GPIO_WritePin(HC_PORT_B, HC_LAT, GPIO_PIN_RESET)

/*********************************************************
							Khai bao ham nguyen mau
*********************************************************/

void serialclock();
void serialLat();
void Data_Double(uint16_t dt);
void Data_Byte(uint8_t dt);

#endif
