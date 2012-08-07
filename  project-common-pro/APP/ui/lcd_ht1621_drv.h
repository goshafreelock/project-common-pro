
#include "Custom_config.h"

#ifndef _LCD_HT1621_DRV_H_
#define	_LCD_HT1621_DRV_H_


#define HT1621_BIT_DELAY 6
#define HT1621_INI_DELAY 20


#define HT1621_BIAS    	0x52
#define HT1621_SYSDIS  	0x00
#define HT1621_SYSEN   	0x02
#define HT1621_LCDOFF  	0x04
#define HT1621_LCDON   	0x06
#define HT1621_XTAL    	0x28
#define HT1621_RC256   	0x30
#define HT1621_TONEON  	0x12
#define HT1621_TONEOFF 0x10
#define HT1621_WDTDIS  	0x0A

#define MAX_SEG_NUM                32

#define 	DIG_A	0x01
#define 	DIG_B	0x02
#define 	DIG_C	0x04
#define 	DIG_D	0x08
#define 	DIG_E	0x10
#define 	DIG_F	0x20
#define 	DIG_G	0x40
#define 	DIG_H	0x80

#if defined(K000_XingChuang_x821_V002)
#define TOTAL_DISP_NUM			6
#define TOTAL_NUM_BUF			7
#define LED_BIT_IDX_LEN		   	7+TOTAL_NUM_BUF+1
#define STOP_NUM		7+2

#else
#define TOTAL_DISP_NUM			5
#define TOTAL_NUM_BUF		3
#define LED_BIT_IDX_LEN		   7+4
#define STOP_NUM		2

#endif

typedef struct{

	u8 digit_num;
	u8 buf_idx[TOTAL_NUM_BUF];
	u8 digit_bit_tab[LED_BIT_IDX_LEN];
		
}Digit_Tab;

void init_disp(void);
void lcd_ht1621_init(void);
void UpdateLcd_HT_1621_Buf(void);
void lcd_backlight_ctrl(bool on);


void disp_buf_clear(void);
void Lcd_check_buf(void);

#endif
