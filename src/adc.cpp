#include <avr/io.h>
#include <avr/interrupt.h>

#include "adc.h"


ISR(ADC_vect) 
{
 int a=(ADCW+1)/128;
 if (a == 0) 
 PORTB=0x00;
 else 
 PORTB = 1 << (a-1);
}


//ADC Init - ������������� ���. ��� ����� ������ ���� - ������ � ������ ����
//���� ��� ��� � ���:
//ADEN = 1 - ��������� ���
//ADIE = 1��������� ����������. 
//ADSC = 1 ��������� �������������� (������, ������ ���������)
//ADATE = 1 ����������� ���������������� ��������������, ���� �� ������.
//ADPS2..0 = 3 �������� ������� �� 8 - ��� � ���� ���������� ����������� �������.

void adc_init(){
	ADCSRA|=(1<<ADEN)|(0<<ADIE)|(1<<ADSC)|(0<<ADATE)|(3<<ADPS0);

	ADMUX = 0b01000000;
//� ��� �������� ������ ����� ����� ������
//REFS -- 0b[01]000101 ������ ��� ���� - ���������� � ����� AVCC
//ADLAR --0b01[1]00101��������� ��� ������������ �� ������ ����
//MUX -- 0b010[00000]</B>������ �� ���� ���� � �������� ������ ���.
	sei();

}


uint16_t adc_get_value(void){
	ADCSRA|=(1<<ADSC); //��������� ��������������
	while((ADCSRA & (1<<ADIF))==0);
	ADCSRA&=~(1<<ADIF); //����� ����� ���������� �������������� ���
	uint16_t adc_value = ADCL|(ADCH<<8);
	return adc_value;


}
