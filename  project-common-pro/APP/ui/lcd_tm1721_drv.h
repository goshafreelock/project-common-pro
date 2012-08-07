#ifndef _LCD_TM1721_DRV_H_
#define	_LCD_TM1721_DRV_H_


#define TM1721_BIT_DELAY 2
#define TM1721_INI_DELAY 6


#define MAX_SEG_NUM                32

#define TOTAL_DISP_NUM			5
#define TOTAL_NUM_BUF		3
#if 1//defined(LED_NORMAL_DISPLAY)
#define STOP_NUM		2
#define LED_BIT_IDX_LEN		   11
#else
#define STOP_NUM		2
#define LED_BIT_IDX_LEN		   13+5
#endif


typedef struct{

	u8 digit_num;
	u8 buf_idx[TOTAL_NUM_BUF];
	u8 digit_bit_tab[LED_BIT_IDX_LEN];
		
}Digit_Tab;


void init_disp(void);
void lcd_TM1721_init(void);
void UpdateLcd_TM1721_Buf(void);
void lcd_backlight_ctrl(bool on);
void TM1721_key_scan();


void disp_buf_clear(void);
void Lcd_check_buf(void);

#endif
