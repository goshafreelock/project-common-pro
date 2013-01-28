/*--------------------------------------------------------------------------
   @file   display_common.h
   @brief    显示模块头文件
   @details
   @author
   @date   2010-04-20
   @note
----------------------------------------------------------------------------*/
#ifndef   _DISPLAY_COMMON_H_
#define  _DISPLAY_COMMON_H_


#ifdef __C51__

#include "gpio_config.h"
#if 0
#define play_led_seg_out() P0DIR &= ~0x80;P0PU |= 0x80;
#define play_led_seg_in() P0DIR |= 0x80;P0PU &= ~0x80; 
#define PLAY_STATUS_PORT P07
//#define PLAY_STATUS_PORT_1 P00
#endif
#endif

typedef enum
{
    DISP_NULL = 0,
    DISP_CLR,
    DISP_STOP,
    DISP_PLAY,
    DISP_PAUSE,
    DISP_VOL,
    DISP_EQ,
    DISP_BALENCE,
    DISP_TREBLE,
    DISP_BASS,
    DISP_LONDESS,
    DISP_FADE,  
    DISP_SW_VOL,
    DISP_MIC_VOL,
    DISP_ECHO,
    DISP_POWER_UP,
    DISP_PLAYMODE,
    DISP_NOFILE,
    DISP_NODEVICE,
    DISP_FILENUM,
    DISP_FILE_NAME,
    DISP_DWORD_NUMBER,
    DISP_WAIT,
    DISP_USBDEV,
    DISP_FREQ,
    DISP_CH_NO,
    DISP_SCAN_NO,
    DISP_SCH,
    DISP_CUR_DEV,
    DISP_AUX,
    DISP_IPOD,
    DISP_BLUE_TOOTH,
    DISP_BLUETOOTH_VOL,
    DISP_PWR_OFF,
    DISP_PWR_TIMER,
    DISP_START,
    DISP_LOAD,
    DISP_ERROR,
    DISP_MIC,
    DISP_RTC,
    DISP_RTC_DATE,
    DISP_RTC_POINT,
    DISP_RTC_PWD,
    DISP_ALM_UP,
    DISP_ALM_SET,
    DISP_ROLLING_MODE,
};

#define CLS_BUF_MAGIC_NUM	0x80

typedef enum {
	LED_FLASH_ON,
	LED_FLASH_VERY_FAST,
	LED_FLASH_FAST,
	LED_FLASH_NOR,
	LED_FLASH_SLOW,
	LED_FLASH_STOP,
	
}LED_FLASH_TYPE;


enum {
	DISP_STOP_SPECT,
	DISP_RUN_SPECT,
	DISP_SPECT_ROLLING,
};

void Disp_Init(void);
void Disp_Init_2(void);
void Disp_Update(void);
void Disp_Scan(void);
void Disp_Con(u8 LCDinterf);
u8 get_led_flash_mode();
void restore_led_flash_mod(u8 led_mod);
#if defined(TWO_PLAY_LED_IN_USE)
void set_play_flash_no2(LED_FLASH_TYPE led_status);
#endif
extern void disp_file_time(void);
#if defined(SPECTRUM_FUNC_ENABLE)
void set_spectrum_lock(bool lock);
void get_spectrum_data(void);
#endif

#ifdef K202_WEISI_KL202_V0010000000
void set_led_enable_bit(bool led);
#endif

#ifdef DISP_BACKLIGHT_AUTO_SAVE_POWER
void Disp_BL_time_out();
void Disp_BL_turn_on();
#endif

void select_spectrum_mode(void);

#endif
