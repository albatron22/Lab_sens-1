#ifndef LCDDRIVER_H_
#define LCDDRIVER_H_

#define pLCD_PORT (PORTC)
#define pLCD_DDR (DDRC)
#define pLCD_E_LINE (2)
#define pLCD_RS_LINE (0)
#define pLCD_RW_LINE (1)

void LCD_SendNibble(unsigned char Nibble);
void LCD_SendData(unsigned char Data);
void LCD_SendCommand(unsigned char Command);

void LCD_Init(void);
void LCD_Clear(void);
void LCD_GotoXY(unsigned char X, unsigned char Y);
void LCD_SendString(char *String, unsigned char MaxLength);
void LCD_SendStringLocal(char *String, unsigned char MaxLength);

//char rusLocal="БГЁЖЗИЙЛПУФЧЬЪЫЭЮЯбвгёжзийклмнптчшъыьэюяДЦЩдфцщ

#define R_b (0xB2)   // б
#define R_v (0xB3)   // в
#define R_g (0xB4)   // г
#define R_ie (0xB5)  // ё
#define R_ge (0xB6)  // ж
#define R_z (0xB7)   // з
#define R_i (0xB8)   // и
#define R_ii (0xB9)  // й
#define R_k (0xBA)   // к
#define R_l (0xBB)   // л
#define R_m (0xBC)   // м
#define R_n (0xBD)   // н
#define R_p (0xBE)   // п
#define R_t (0xBF)   // т
#define R_ch (0xC0)  // ч
#define R_sh (0xC1)  // ш
#define R_tvz (0xC2) // ъ
#define R_bi (0xC3)  // ы
#define R_mz (0xC4)  // ь
#define R_ee (0xC5)  // э
#define R_u (0xC6)   // ю
#define R_ia (0xC7)  // я
#define R_D (0xE0)   // Д
#define R_TC (0xE1)  // Ц
#define R_SHC (0xE2) // Щ
#define R_d (0xE3)   // д
#define R_f (0xE4)   // ф
#define R_tc (0xE5)  // ц
#define R_shc (0xE6) // щ

#endif /* LCDDRIVER_H_ */
