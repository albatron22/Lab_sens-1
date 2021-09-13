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


//char rusLocal="ÁÃ¨ÆÇÈÉËÏÓÔ×ÜÚÛİŞßáâã¸æçèéêëìíïò÷øúûüışÿÄÖÙäôöù


#define		R_b		(0xB2)		// á
#define		R_v		(0xB3)		// â
#define		R_g		(0xB4)		// ã
#define		R_ie	(0xB5)		// ¸
#define		R_ge	(0xB6)		// æ
#define		R_z		(0xB7)		// ç
#define		R_i		(0xB8)		// è
#define		R_ii	(0xB9)		// é
#define		R_k		(0xBA)		// ê
#define		R_l		(0xBB)		// ë
#define		R_m		(0xBC)		// ì
#define		R_n		(0xBD)		// í
#define		R_p		(0xBE)		// ï
#define		R_t		(0xBF)		// ò
#define		R_ch	(0xC0)		// ÷
#define		R_sh	(0xC1)		// ø
#define		R_tvz	(0xC2)		// ú
#define		R_bi	(0xC3)		// û
#define		R_mz	(0xC4)		// ü
#define		R_ee	(0xC5)		// ı
#define		R_u		(0xC6)		// ş
#define		R_ia	(0xC7)		// ÿ
#define		R_D		(0xE0)		// Ä
#define		R_TC	(0xE1)		// Ö
#define		R_SHC	(0xE2)		// Ù
#define		R_d		(0xE3)		// ä
#define		R_f		(0xE4)		// ô
#define		R_tc	(0xE5)		// ö
#define		R_shc	(0xE6)		// ù


#endif /* LCDDRIVER_H_ */




