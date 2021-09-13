#include <Arduino.h>

#include "LCD_Driver.h"

#include "adc.h"

uint8_t message[64];

void setup()
{
    //инициализация LCD-дисплея
    LCD_Init();
    LCD_Clear();
    LCD_GotoXY(0, 0);
    //инициализация АЦП микроконтроллера
    adc_init();
}

void loop()
{
    //перевод значения напряжения в освещённость
    uint16_t adc_value = adc_get_value();
    double voltage = 5.0 * ((double)adc_value / 1024.0);
    double resistance = (1000.0 * voltage) / (5.0 - voltage);
    double illuminance = 531.21 * pow(resistance, -5.0 / 4.0);
    //вывод информации на экран
    LCD_Clear();
    LCD_GotoXY(0, 0);
    LCD_SendString((char *)message, sprintf((char *)message, "Illumination: %.3f lux\r\n", illuminance));
    _delay_ms(1000);
}