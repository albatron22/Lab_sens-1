#ifndef LCDDRIVER_H_
#define LCDDRIVER_H_

#define		pLCD_PORT		(PORTC)
#define		pLCD_DDR		(DDRC)
#define		pLCD_E_LINE		(2)
#define		pLCD_RS_LINE	(0)
#define		pLCD_RW_LINE	(1)

void LCD_SendNibble(unsigned char Nibble);
void LCD_SendData(unsigned char Data);
void LCD_SendCommand(unsigned char Command);

void LCD_Init(void);
void LCD_Clear(void);
void LCD_GotoXY(unsigned char X, unsigned char Y);
void LCD_SendString(char * String, unsigned char MaxLength);
void LCD_SendStringLocal(char * String, unsigned char MaxLength);


//char rusLocal="�è�������������������������������������������


#define		R_b		(0xB2)		// �
#define		R_v		(0xB3)		// �
#define		R_g		(0xB4)		// �
#define		R_ie	(0xB5)		// �
#define		R_ge	(0xB6)		// �
#define		R_z		(0xB7)		// �
#define		R_i		(0xB8)		// �
#define		R_ii	(0xB9)		// �
#define		R_k		(0xBA)		// �
#define		R_l		(0xBB)		// �
#define		R_m		(0xBC)		// �
#define		R_n		(0xBD)		// �
#define		R_p		(0xBE)		// �
#define		R_t		(0xBF)		// �
#define		R_ch	(0xC0)		// �
#define		R_sh	(0xC1)		// �
#define		R_tvz	(0xC2)		// �
#define		R_bi	(0xC3)		// �
#define		R_mz	(0xC4)		// �
#define		R_ee	(0xC5)		// �
#define		R_u		(0xC6)		// �
#define		R_ia	(0xC7)		// �
#define		R_D		(0xE0)		// �
#define		R_TC	(0xE1)		// �
#define		R_SHC	(0xE2)		// �
#define		R_d		(0xE3)		// �
#define		R_f		(0xE4)		// �
#define		R_tc	(0xE5)		// �
#define		R_shc	(0xE6)		// �


#endif /* LCDDRIVER_H_ */




