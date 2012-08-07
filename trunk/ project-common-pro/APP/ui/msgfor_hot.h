/*--------------------------------------------------------------------------*/
/**@file    msgfor_hot.h
   @brief   HOT 消息处理
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#ifndef _MSGFOR_HOT_
#define	_MSGFOR_HOT_

#ifdef __C51__
#include "config.h"
#include "uart.h"
#include "main.h"
#include "key.h"
#include "display_common.h"

u8 ap_handle_hotkey(u8 msg);
void my_main_vol(u8 my_vol);

typedef enum {

	AUTO,
	MUTE,
	UNMUTE,
	SUPERMUTE,
}MUTE_TYPE;

void Mute_Ext_PA(MUTE_TYPE M_Type);
void clear_super_mute_lock();
bool get_super_mute_lock();

#if defined(USE_SPECTRUM_PARTTERN)
void set_lcd_flash_lock(bool flag);
bool get_lcd_flash_lock();
#endif

void dac_highz_output_enable(void);
void main_vol(u8 vol);
void aux_channel_crosstalk_improve(u8 ch_num);

#if defined(USE_TIMER_POWER_OFF_FUNC)
void timer_pwr_off_hdlr();
#endif

#if defined(AUX_MODE_HOT_KEY_ENABLE)||defined(MUSIC_MODE_HOT_KEY_ENABLE)||defined(RADIO_MODE_HOT_KEY_ENABLE)||defined(RTC_MODE_HOT_KEY_ENABLE)
void set_mode_hotkey_protect(bool protec);
bool get_mod_hotkey_protect_status();
#endif

#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)||defined(MP3_PUASE_FLASH_FIGURE)
void Led_flash_screen_hdlr();
void set_led_flash_tpye(u8 type_reg);
#endif
#endif
enum{
	UNLOCK,
	LOCK,
};
typedef enum{

	USB_DEV,
	SD_DEV,
#if defined(EXCHANGE_FM_AUX_PRIO)    
	AUX_DEV,
	FM_DEV,
#ifdef RADIO_AM_WM_ENABLE
    	AM_DEV,
#endif    		
#else	
	FM_DEV,
#ifdef RADIO_AM_WM_ENABLE
    	AM_DEV,
#endif    	
	AUX_DEV,
#endif
#ifdef USE_AUX_2
       AUX_2_DEV,
#endif
#if defined(IPONE_INDEPENDENT_MODE)	
	IPH_DEV,
#endif
#if defined(BLUE_TOOTH_FUNC)	
	BT_DEV,
#endif	
#ifdef USE_RTC_FUNCTION
	RTC_DEV,
#endif	
	IDLE,
}DEV_ON_LIST;

void Init_Func_List();
void Set_Curr_Func(u8 curr_mod);
void Remov_Func_From_List(DEV_ON_LIST Dev);

#ifdef LED_MODE_INDICATOR_ENABLE
void LED_MODE_INDICATOR();
#endif
#if defined(KEY_PRESS_LED_INDICATOR)
void key_press_led_indicator(u8 key_t);
#elif defined(CUSTOM_KEY_FEATURE_USE)
void custom_key_hdlr(u8 key_t);
#endif

#ifdef GPIO_SWITCH_SELECT_MODE
bool gpio_select_mode(void);
#endif

#ifdef SUPPORT_PT2313
void clr_aud_effect_state();
void audio_effect_hdlr(u8 hdlr_cmd);
#endif

#endif
