#include "LCD_Driver.h"
#include <util/delay.h>
#include <string.h>
#include <avr/io.h>

void LCD_SendNibble(unsigned char Nibble)
{
    pLCD_PORT &= 0x0F;
    Nibble &= 0xF0;
    pLCD_PORT |= Nibble;
    _delay_us(8);
    pLCD_PORT |= (1 << pLCD_E_LINE);
    _delay_us(8);
    pLCD_PORT &= ~(1 << pLCD_E_LINE);
    _delay_us(40);
}

void LCD_SendData(unsigned char Data)
{
    pLCD_PORT &= ~(1 << pLCD_RW_LINE);
    pLCD_PORT |= (1 << pLCD_RS_LINE);
    LCD_SendNibble(Data & 0xF0);
    LCD_SendNibble((Data << 4) & 0xF0);
    pLCD_PORT |= (1 << pLCD_RW_LINE);
}

void LCD_SendCommand(unsigned char Command)
{
    pLCD_PORT &= ~(1 << pLCD_RW_LINE);
    pLCD_PORT &= ~(1 << pLCD_RS_LINE);
    LCD_SendNibble(Command & 0xF0);
    LCD_SendNibble((Command << 4) & 0xF0);
    pLCD_PORT |= (1 << pLCD_RW_LINE);
}

void LCD_Init(void)
{
    pLCD_PORT &= 0x0F;
    pLCD_DDR |= 0xF0;
    pLCD_PORT &= ~(1 << pLCD_RS_LINE);
    pLCD_PORT &= ~(1 << pLCD_E_LINE);
    pLCD_PORT &= ~(1 << pLCD_RW_LINE);
    pLCD_DDR |= (1 << pLCD_RS_LINE);
    pLCD_DDR |= (1 << pLCD_E_LINE);
    pLCD_DDR |= (1 << pLCD_RW_LINE);

    pLCD_PORT &= ~(1 << pLCD_RS_LINE);
    pLCD_PORT &= ~(1 << pLCD_RW_LINE);
    /*LCD_SendNibble(0x20);
	_delay_us(160);
	LCD_SendNibble(0x20);
	_delay_us(160);
	LCD_SendNibble(0x20);
	_delay_us(160);
	LCD_SendNibble(0x20);
	_delay_us(160);

	LCD_SendCommand(0x28);
	_delay_us(160);
	LCD_SendCommand(0x0E);
	_delay_us(160);
	LCD_SendCommand(0x04);
	_delay_us(160);
	LCD_SendCommand(0x01);
	_delay_ms(2);*/
    LCD_SendNibble(0x30);  //Послать тетраду 0b0011
    _delay_us(160);        //Задержка 40 мкс
    LCD_SendNibble(0x30);  //Послать тетраду 0b0011
    _delay_us(160);        //Задержка 40 мкс
    LCD_SendNibble(0x30);  //Послать тетраду 0b0011
    _delay_us(160);        //Задержка 40 мкс
    LCD_SendNibble(0x20);  //Послать тетраду 0b0010
    _delay_us(160);        //Задержка 40 мкс
    LCD_SendCommand(0x28); //Установка 4-разрядного обмена
    _delay_us(160);        //Задержка 40 мкс
    LCD_SendCommand(0x0C); //Включить дисплей. Курсор выключен
    _delay_us(160);        //Задержка 40 мкс
    LCD_SendCommand(0x04); //Курсор сдвигается вправо. Запрет сдвига дисплея.
    _delay_us(160);        //Задержка 40 мкс
    LCD_SendCommand(0x01); //Очистка дисплея
    _delay_us(2000);       //Задержка 1,5 мс
}

void LCD_Clear(void)
{
    LCD_SendCommand(0x01);
    _delay_ms(2);
}

void LCD_GotoXY(unsigned char X, unsigned char Y)
{
    unsigned char Temp = 0; //Временная переменная
    switch (Y)
    //В зависимости от вертикальной координаты
    {
    case 0:
        Temp = 0x00;
        break; //Координата начала первой строчки
    case 1:
        Temp = 0x40;
        break; //Координата начала второй строчки
    case 2:
        Temp = 0x10;
        break; //Координата начала третьей строчки
    case 3:
        Temp = 0x50;
        break; //Координита начала четвертой строчки
    }
    Temp += X;             //Прибавить горизонтальную координату
    Temp |= 0b10000000;    //Установить старший бит команды - признак
    LCD_SendCommand(Temp); //команды для установки адреса DDRAM
}

void LCD_SendString(char *String, unsigned char MaxLength)
{
    for (unsigned char Iterator = 0; Iterator < MaxLength; Iterator++)
    {
        //if (String[Iterator] == 0) break;
        LCD_SendData(String[Iterator]);
    }
}

void LCD_SendStringLocal(char *String, unsigned char MaxLength)
{

    for (unsigned char Iterator = 0; Iterator < MaxLength; Iterator++)
    {
        if (String[Iterator] == 0)
            break;
        LCD_SendData(String[Iterator]);
    }
}
