#include <Arduino.h>
#include "LCD_Driver.h"

#define PHOTO_RES PIN_PA0 // пин подлкючения к фоторезистору
#define HALL_SENS PIN_PA1 // пин подключения к датчику Холла
#define S1 PIN_PB0        // тумблер выбора программы

uint8_t message[64];

void setup()
{
    pinMode(S1, INPUT_PULLUP);
    pinMode(HALL_SENS, INPUT);
    /* Инициализация LCD-дисплея */
    LCD_Init();
    LCD_Clear();
    LCD_GotoXY(0, 0);
}

void loop()
{
    if (!digitalRead(S1))
    {
        /* Работа с фоторезистором */
        uint16_t adc_value = analogRead(PHOTO_RES);                // считывание падения напряжения с помощью АЦП
        double voltage = 5.0 * ((double)adc_value / 1023.0);       // перевод АЦП в напряжение
        double resistance = (1000.0 * voltage) / (5.0 - voltage);  // вычисление сопротивления фоторезситора
        double illuminance = 531.21 * pow(resistance, -5.0 / 4.0); // определение уровня освещенности
        /* Вывод информации на экран */
        LCD_Clear();
        LCD_GotoXY(0, 0);
        sprintf((char *)message, "ADC:%d", adc_value);
        LCD_SendString((char *)message, strlen((char *)message));
        LCD_GotoXY(0, 1);
        sprintf((char *)message, "Ill:%.2f", illuminance);
        LCD_SendString((char *)message, strlen((char *)message));
    }
    else
    {
        int hall = digitalRead(HALL_SENS); // чтение состояния пина, к которому подлкючен выхода датчика Холла
        /* Вывод информации на экран */
        LCD_Clear();
        LCD_GotoXY(0, 0);
        sprintf((char *)message, "HALL:%i", hall);
        LCD_SendString((char *)message, strlen((char *)message));
    }
    delay(1000);
}