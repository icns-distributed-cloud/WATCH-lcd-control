/*
 * 7789.h
 *
 *  Created on: 2019. 2. 28.
 *      Author: yoons
 */

#include "gpio.h"

#define LCD_Width 240
#define LCD_Height 240

#define LCD_RST1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,GPIO_PIN_SET)
#define LCD_RST0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,GPIO_PIN_RESET)

#define LCD_DC1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_SET)
#define LCD_DC0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_RESET)

#define LCD_CS1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,GPIO_PIN_SET)
#define LCD_CS0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,GPIO_PIN_RESET)

#define LCD_SCK1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,GPIO_PIN_SET)
#define LCD_SCK0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,GPIO_PIN_RESET)

#define LCD_MOSI1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_SET)
#define LCD_MOSI0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_RESET)

void ST7789_Init();
void ST7789_senddata(unsigned char data);
void ST7789_sendCmd(unsigned char cmd);
void ST7789_sendData(unsigned char data);
void ST7789_pix(unsigned char x,unsigned char y, unsigned int color);
void ST7789_at(unsigned char startx,unsigned char starty,unsigned char stopx,unsigned char stopy);
void ST7789_drawImage(uint32_t xs, uint32_t ys, const uint32_t *image, unsigned int color);
void ST7789_drawChar(uint32_t xs, uint32_t ys, const uint32_t ** font, uint8_t ascii, unsigned int color);
void ST7789_drawString(uint32_t xs, uint32_t ys, const uint32_t ** font, uint8_t *str, unsigned int color);
void ST7789_drawInt(uint32_t xs, uint32_t ys, const uint32_t ** font, int n, unsigned int color);
void ST7789_Clear(uint32_t x1,uint32_t x2,uint32_t y1,uint32_t y2);
