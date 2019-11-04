#include "ST7789.h"
//88
void ST7789_Init(){

	LCD_SCK1;
	LCD_CS0;
	LCD_RST0;

	HAL_Delay(10);

	LCD_RST1;
	HAL_Delay(10);

	ST7789_sendCmd(0x11);

	HAL_Delay(10);
	ST7789_sendCmd(0x3A);
	ST7789_sendData(0x05);
	ST7789_sendCmd(0x29);

}
void ST7789_senddata(unsigned char data){
	unsigned char i;
	LCD_CS0;
	for(i=0;i<8;i++){
		if(data & 0x80){LCD_MOSI1;}
		else LCD_MOSI0;
		data=data<<1;
		LCD_SCK0;
		LCD_SCK1;
	}
	LCD_CS1;
}
void ST7789_sendCmd(unsigned char cmd){
	LCD_DC0;
	ST7789_senddata(cmd);
}
void ST7789_sendData(unsigned char data){
	LCD_DC1;
	ST7789_senddata(data);
}
void ST7789_pix(unsigned char x,unsigned char y, unsigned int color){
	ST7789_sendCmd(0x2A);
	ST7789_sendData(0x00);
	ST7789_sendData(x);

	ST7789_sendCmd(0x2B);
	ST7789_sendData(0x00);
	ST7789_sendData(y);

	ST7789_sendCmd(0x2C);
	ST7789_sendData((color & 0xFF00)>>8);
	ST7789_sendData(color & 0x00FF);
}
void ST7789_at(unsigned char startx,unsigned char starty,unsigned char stopx,unsigned char stopy){
	ST7789_sendCmd(0x2A);
	ST7789_sendData(0x00);
	ST7789_sendData(startx);
	ST7789_sendData(0x00);
	ST7789_sendData(stopx);

	ST7789_sendCmd(0x2B);
	ST7789_sendData(0x00);
	ST7789_sendData(starty);
	ST7789_sendData(0x00);
	ST7789_sendData(stopy);
}
void ST7789_drawImage(uint32_t xs, uint32_t ys, const uint32_t *image,unsigned int color)
{
	uint32_t i, x, y, sx, sy;

	sx = image[0];
	sy = image[1];

	for (i = 0; i < sx * sy; i++)
	{
		x = xs + (i % sx);
		y = ys + (i / sx);

		if ((image[2 + (i / 32)] >> (31 - (i % 32))) & 0x1)
			ST7789_pix(x, y,color);
		else
			ST7789_pix(x, y,0x0);
	}
}
void ST7789_drawChar(uint32_t xs, uint32_t ys, const uint32_t ** font, uint8_t ascii,unsigned int color)
{
	if ((ascii < 32) || (ascii > 126))
		ascii = 0;
	else
		ascii -= 32;

	ST7789_drawImage(xs, ys, font[ascii],color);
}
void ST7789_drawInt(uint32_t xs, uint32_t ys, const uint32_t ** font, int n,unsigned int color)
{
	int r = 1;
	int offset = 0;

	if (n == 0)
	{
		ST7789_drawChar(xs, ys, font, '0',color);
		return;
	}

	if (n < 0)
	{
		ST7789_drawChar(xs, ys, font, '-',color);
		offset += font[0][0];
		n = -n;
	}

	while (n / r)
		r *= 10;

	while (r != 1)
	{
		r /= 10;
		ST7789_drawChar(xs + offset, ys, font, (uint8_t)((n % (r * 10)) / r + '0'),color);
		offset += font[0][0];
	}
}
void ST7789_drawString(uint32_t xs, uint32_t ys, const uint32_t ** font, uint8_t *str,unsigned int color)
{
	while (*str != 0)
	{
		ST7789_drawChar(xs, ys, font, *(str++),color);
		xs += font[0][0];
	};
}
void ST7789_Clear(uint32_t x1,uint32_t x2,uint32_t y1,uint32_t y2){
	int y,x;
	 for(y=y1;y<y2;y++){
	 		  for(x=x1;x<x2;x++){
	 			  ST7789_pix(x,y,0x0);
	 		  }
	  }
}
