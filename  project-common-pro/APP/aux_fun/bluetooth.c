/*--------------------------------------------------------------------------*/
/**@file     bluetooth.c
   @brief     bluetooth����ģ��
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "bluetooth.h"
#include "led.h"
#include "rtc_mode.h"
#include "PT2313.h"

#if defined(KPL_MSG_COMPATIBLE)
#include "kpl_msg.h"
#endif

#ifdef BLUE_TOOTH_FUNC

#if defined(TIME_FORCE_SHOW_ON_SCREEN)
extern xd_u8 time_show_return_cnt; 
#endif
extern u16 cfilenum;
extern xd_u8 curr_menu;
extern xd_u8  return_cnt;
extern bit aux_online;
extern _xdata SYS_WORK_MODE work_mode;
extern xd_u8 IR_Type;
extern bool IR_KEY_Detect;
extern void set_play_flash(u8 led_status);
extern xd_u8 my_music_vol;  
extern _idata u16 dac_cnt;
extern u8 play_status;
#if defined(NEW_VOLUME_KEY_FEATURE)
extern bool new_vol_feature;
extern u8 last_disp_menu;
#endif

extern xd_u8 bluetooth_vol_dir;

#ifdef BLUE_TOOTH_KEY_DELAY_25MS
#define BLUE_TOOTH_DELAY		25
#else
#define BLUE_TOOTH_DELAY		10
#endif
#ifdef SUPPORT_PT2313
extern xd_u8 audio_effect_state;
#endif
#ifdef USE_BT_ACTIVATED_PIN
xd_u8 ACTIVATED_PIN_cnt=0;
#endif
#ifdef BT_DISP_CONNECT_TIME
xd_u8 link_sec=0,link_min=0,link_hour=0;
void bt_disp_time_hdlr()
{
	static bool sec_cnt=0;
	
	sec_cnt=~sec_cnt;
	if(sec_cnt)return;
	
	link_sec++;
	if(link_sec>59){
		
		link_sec =0;
		
		link_min++;
		if(link_min>59){
			link_min =0;
			link_hour++;
			if(link_hour>99){
				link_min =0;
				link_sec =0;
				link_hour =0;				
			}
		}
	}

}
#endif

void blue_tooth_init(void)
{
#ifdef BLUETOOTH_GPIO_CTRL
	BT_PWR_PORT_INIT();
	BT_RST_PORT_INIT();
	BT_PWR_ON();
	delay_10ms(20);

#ifdef USE_BT_ACTIVATED_PIN
	BT_RST_ON();
	//delay_10ms(100);
	ACTIVATED_PIN_cnt=20;
	//BT_RST_OFF();
#endif

#endif
}
#ifdef BLUE_TOOTH_MUTE_DETECT_FUNC
void blue_tooth_mute_detect(void)
{
	static bool bluetooth_mute_detect=0;
	BT_MUTE_DETECT_INIT();
	
	if(BT_MUTE_DETECT_PORT){
		
		if(!bluetooth_mute_detect){
    			my_main_vol(0);	
			bluetooth_mute_detect=1;
		}
	}
	else{

		if(bluetooth_mute_detect){
    			my_main_vol(my_music_vol);	
			bluetooth_mute_detect=0;
		}
	}

	BT_MUTE_DETECT_RELEASE();
}
#endif

xd_u8 bt_key_release_cnt=0;
void blue_tooth_key_hdlr(u8 key)
{
	switch(key)
	{
	        case BT_PP :
#ifdef BLUETOOTH_GPIO_CTRL		
			BT_PP_PORT_INIT();
			BT_PP_ON();delay_10ms(BLUE_TOOTH_DELAY);BT_PP_OFF();
#endif
			break;
	        case BT_NEXT_FILE:
#ifdef BLUETOOTH_GPIO_CTRL
			BT_NEXT_PORT_INIT();
			BT_NEXT_ON();delay_10ms(BLUE_TOOTH_DELAY);BT_NEXT_OFF();				
#endif
			break;
	        case BT_PREV_FILE:
#ifdef BLUETOOTH_GPIO_CTRL	
			BT_PREV_PORT_INIT();
			BT_PREV_ON();delay_10ms(BLUE_TOOTH_DELAY);BT_PREV_OFF();				
#endif
			break;
		case BT_VOL_UP:
#ifdef BLUETOOTH_GPIO_CTRL
			BT_VOLU_PORT_INIT();
			BT_VOL_UP_ON();
			delay_10ms(BLUE_TOOTH_DELAY);
			BT_VOL_UP_OFF();				
#endif	
#ifdef BLUE_TOOTH_DISP_VOL_DIR
			bluetooth_vol_dir=0xFF;
			Disp_Con(DISP_BLUETOOTH_VOL);
#endif
			break;			
		case BT_VOL_DOWN:
#ifdef BLUETOOTH_GPIO_CTRL
			BT_VOLD_PORT_INIT();
			BT_VOL_DOWN_ON();
			delay_10ms(BLUE_TOOTH_DELAY);
			BT_VOL_DOWN_OFF();				
#endif		

#ifdef BLUE_TOOTH_DISP_VOL_DIR
			bluetooth_vol_dir=0xF1;
			Disp_Con(DISP_BLUETOOTH_VOL);
#endif
			break;	
		case BT_VOL_UP_HOLD:
			bt_key_release_cnt=1;
#ifdef BLUETOOTH_GPIO_CTRL
#ifdef BT_VOL_USE_NEXT_PREV_KEY
			BT_NEXT_PORT_INIT();
			BT_NEXT_ON();
#else
			BT_VOLU_PORT_INIT();
			BT_VOL_UP_ON();
#endif			
#endif		

#ifdef BLUE_TOOTH_DISP_VOL_DIR
			bluetooth_vol_dir=0xFF;
			Disp_Con(DISP_BLUETOOTH_VOL);
#endif			

			break;			
		case BT_VOL_DOWN_HOLD:
			bt_key_release_cnt=1;
#ifdef BLUETOOTH_GPIO_CTRL
#ifdef BT_VOL_USE_NEXT_PREV_KEY
			BT_PREV_PORT_INIT();
			BT_PREV_ON();
#else
			BT_VOLD_PORT_INIT();
			BT_VOL_DOWN_ON();
#endif			
#endif	

#ifdef BLUE_TOOTH_DISP_VOL_DIR
			bluetooth_vol_dir=0xF1;
			Disp_Con(DISP_BLUETOOTH_VOL);
#endif			
			break;		
		case BT_VOL_HOLD_RELEASE:
			bt_key_release_cnt=0;
#ifdef BLUETOOTH_GPIO_CTRL
#ifdef BT_VOL_USE_NEXT_PREV_KEY
			BT_NEXT_OFF();	
			BT_PREV_OFF();		
#else
			BT_VOL_UP_OFF();	
			BT_VOL_DOWN_OFF();				
#endif			
#endif			
			break;
	}
}

/*----------------------------------------------------------------------------*/
/**@brief  AUX��Ϣ����
   @param  ��
   @return ��
   @note   void deal_aux( void )
*/
/*----------------------------------------------------------------------------*/
void blue_tooth_main(void)
{
    u8 key;
#ifdef TURN_OFF_PLAY_STATUS_LED_IN_BLUETOOTH_MODE
    set_play_flash(LED_FLASH_STOP);
#endif
    while (1)
    {
        key = get_msg();
#if 0
	if(key!=0xFF)
	printf( "---->---deal_aux %x \r\n",(u16)key);
#endif
		
#if defined(KEY_PRESS_LED_INDICATOR)
	key_press_led_indicator(key);
#elif defined(CUSTOM_KEY_FEATURE_USE)
	custom_key_hdlr(key);
#endif

#if defined(KPL_MSG_COMPATIBLE)
	kpl_msg_hdlr(key);
#endif

	 dac_sw_check();

 	switch (key)
        {

        case INFO_PLAY | KEY_SHORT_UP :

	     blue_tooth_key_hdlr(BT_PP);
#ifndef BLUE_TOOTH_NO_SYS_MUTE_CTRL
#if !defined(BLUE_TOOTH_BYPASS)	 
            if (play_status == MUSIC_PAUSE)
            {
	         play_status =MUSIC_PLAY;
		  my_main_vol(my_music_vol);
  		  Mute_Ext_PA(UNMUTE);

            }
	     else if (play_status == MUSIC_PLAY){

	        play_status =MUSIC_PAUSE;
		 	
  		Mute_Ext_PA(MUTE);		 	
		my_main_vol(0);	
	     }
#endif		 
#endif		 
            Disp_Con(DISP_BLUE_TOOTH);		 
	   break;        

        case INFO_NEXT_FIL | KEY_SHORT_UP:	
        	blue_tooth_key_hdlr(BT_NEXT_FILE);
		break;
		
        case INFO_PREV_FIL | KEY_SHORT_UP:
	     	 blue_tooth_key_hdlr(BT_PREV_FILE);
		 break;

        case INFO_HALF_SECOND :

#ifdef USE_USB_HOTPLUG_FUNC
		usb_hotplug_hdlr();
#endif
#ifdef BLUE_TOOTH_MUTE_DETECT_FUNC
		blue_tooth_mute_detect();
#endif
#if defined(USE_BAT_MANAGEMENT)
		bmt_hdlr();
#endif

	    if(bt_key_release_cnt--==0){
	     	 blue_tooth_key_hdlr(BT_VOL_HOLD_RELEASE);
	    }
		
#ifdef USE_BT_ACTIVATED_PIN
	   if(ACTIVATED_PIN_cnt--==0){
			BT_RST_OFF();
	   }
#endif
		
#ifdef BT_DISP_CONNECT_TIME
		bt_disp_time_hdlr();
#endif


#if defined(LINE_IN_PLAY_KEY_PAUSE)
		if(play_status==MUSIC_PAUSE){

#ifdef LINE_IN_FLASH_WHOLE_SCREEN	
			aux_screen_flash_bit=~aux_screen_flash_bit;
			if(aux_screen_flash_bit){
		                  Disp_Con(DISP_BLUE_TOOTH);
			}
			else{
		                   Disp_Con(DISP_PWR_OFF);
					break;
			}
#endif
		}
#endif

			
#if defined(TIME_FORCE_SHOW_ON_SCREEN)

	if(DISP_BLUE_TOOTH == curr_menu){
		
	            if (time_show_return_cnt>RETURN_TIME_SHOW_TIME){
	                    get_curr_date();
	                    Disp_Con(DISP_RTC_POINT);
				break;
		    }	
		     else{
#if defined(MANUAL_SWITCH_TIME_DISPLAY)
	                    Disp_Con(DISP_BLUE_TOOTH);
#else			 	
	                if(DISP_RTC != curr_menu){
				time_show_return_cnt++;
	                }
#endif				
		     }
	     }
#endif
            if (return_cnt < RETURN_TIME)
            {
                return_cnt++;
            }
            else if (RETURN_TIME == return_cnt)
            {
                if (DISP_BLUE_TOOTH != curr_menu)
                    Disp_Con(DISP_BLUE_TOOTH);
				
#if defined(CUSTOM_MAIN_DISP_VOL)
	         if (DISP_BLUE_TOOTH== curr_menu){
                    Disp_Con(DISP_VOL);
	         }
#endif
            }

            if (DISP_BLUE_TOOTH == curr_menu)
	 	     Disp_Con(DISP_BLUE_TOOTH);

	     Disp_Update();			
            break;
			
#ifdef BLUE_TOOTH_BYPASS
    case INFO_VOL_PLUS:
    case INFO_VOL_PLUS | KEY_HOLD :
    case INFO_NEXT_FIL:
    case INFO_NEXT_FIL| KEY_HOLD :
		
    case INFO_VOL_MINUS:
    case INFO_VOL_MINUS | KEY_HOLD :
    case INFO_PREV_FIL:
    case INFO_PREV_FIL| KEY_HOLD :		
		break;
#else
#if defined(NEW_VOLUME_KEY_FEATURE)
        case INFO_NEXT_FIL :
        case INFO_NEXT_FIL | KEY_SHORT_UP:
        case INFO_NEXT_FIL | KEY_HOLD:

		if(!new_vol_feature){
			break;
		}
#else			

    case INFO_VOL_PLUS:
#ifdef BLUE_TOOTH_INDEPENDENT_VOLUME_KEY
      	blue_tooth_key_hdlr(BT_VOL_UP);
	break;
#endif	
    case INFO_VOL_PLUS | KEY_HOLD :
#if !defined(INDEPENDENT_VOLUME_KEY)		
    //case INFO_NEXT_FIL:
    case INFO_NEXT_FIL| KEY_HOLD :
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			break;
		}
#endif		

#endif		

#ifdef SUPPORT_PT2313
	if((audio_effect_state>0)){
		audio_effect_hdlr(0x01);
		flush_low_msg();	
		break;
	}
#endif
#ifndef BLUE_TOOTH_INDEPENDENT_VOLUME
        my_music_vol += 2;
#endif
      	blue_tooth_key_hdlr(BT_VOL_UP_HOLD);
	goto __VOL_HDLR;
	
#if defined(NEW_VOLUME_KEY_FEATURE)
        case INFO_PREV_FIL :
        case INFO_PREV_FIL | KEY_SHORT_UP:
        case INFO_PREV_FIL | KEY_HOLD:

		if(!new_vol_feature){
			break;
		}
#else				

    case INFO_VOL_MINUS:
#ifdef BLUE_TOOTH_INDEPENDENT_VOLUME_KEY
      	blue_tooth_key_hdlr(BT_VOL_DOWN);
	break;
#endif
    case INFO_VOL_MINUS | KEY_HOLD :
#if !defined(INDEPENDENT_VOLUME_KEY)				
    //case INFO_PREV_FIL:
    case INFO_PREV_FIL| KEY_HOLD :
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			break;
		}
#endif		
#endif

#ifdef SUPPORT_PT2313	
	if((audio_effect_state>0)){
		audio_effect_hdlr(0x02);
		flush_low_msg();
		break;
	}
#endif
      	blue_tooth_key_hdlr(BT_VOL_DOWN_HOLD);

__VOL_HDLR:

#ifndef BLUE_TOOTH_INDEPENDENT_VOLUME
        if(my_music_vol)
            my_music_vol--;

        if (my_music_vol > MAX_VOL)
        {
            my_music_vol = MAX_VOL;
        }
#if defined(LINE_IN_PLAY_KEY_PAUSE)
        if (play_status == MUSIC_PAUSE)
        {
	       play_status =MUSIC_PLAY;
	 }
#endif		
	 clear_super_mute_lock();

        write_info(MEM_VOL,my_music_vol);
	 my_main_vol(my_music_vol);	
	 Disp_Con(DISP_VOL);
#endif	 
        break;
#endif		
#if RTC_ENABLE 
	case INFO_ALM_BELL :					   ///<��������Ϣ����������ѭ��
		sys_clock_pll();
		dac_out_select(DAC_DECODE);
		if(alm_bell_mode())
		{
			dac_out_select(DAC_AMUX0);
			return;
		}		
		dac_out_select(DAC_AMUX0);
	break;
#endif
        default :							    
            if (!ap_handle_hotkey(key))
                return;
        }
    }
}
/*----------------------------------------------------------------------------*/
/**@brief  AUX�������
   @param  ��
   @return ��
   @note   void aux_function(void)
*/
/*----------------------------------------------------------------------------*/
void blue_tooth_hdlr(void)
{
#if 1//defined(LINE_IN_PLAY_KEY_PAUSE)
         play_status =MUSIC_PLAY;
#endif

#ifdef BT_DISP_CONNECT_TIME
    link_sec =0;
    link_min =0; 
    link_hour =0;		
#endif

    set_play_flash(LED_FLASH_ON);
    Disp_Con(DISP_BLUE_TOOTH);

    PT1 = 1;										//timer1 interrupt �����ȼ�
    flush_low_msg();
#if SDMMC_CMD_MODE
   sd_chk_ctl(SET_SD_L_CHK);
#endif
    main_vol(0);

    blue_tooth_init();
	
#ifdef BT_DEFAULT_VOL
    my_music_vol = BT_DEFAULT_VOL;
#endif

    set_max_vol(MAX_ANALOG_VOL, MAX_DIGITAL_VOL);			//����AUXģʽ����������

#ifdef SUPPORT_PT2313

#ifdef BT_USE_AUX_0
    aux_channel_crosstalk_improve(DAC_AMUX0);	//4P24,P25 AUX_IN	 
#else	
    aux_channel_crosstalk_improve(DAC_AMUX1);//4	P26,P27 AUX_IN
#endif

    PT2313_Config(MP3_CHAN,CHAN_ADJ);

    my_main_vol(my_music_vol);	
	
#elif defined(BLUE_TOOTH_BYPASS)||defined(BLUE_TOOTH_PATH_DIRECT_IN_PA)

    dac_out_select(DAC_DECODE);

#else

#ifdef BT_USE_AUX_0
    aux_channel_crosstalk_improve(DAC_AMUX0);	//4P24,P25 AUX_IN	 
#else	
    aux_channel_crosstalk_improve(DAC_AMUX1);//4	P26,P27 AUX_IN
#endif

    my_main_vol(my_music_vol);	
	
#endif

    sysclock_div2(1);

    Mute_Ext_PA(UNMUTE);	

    blue_tooth_main();
    Mute_Ext_PA(MUTE);		
	
    main_vol_set(0, CHANGE_VOL_NO_MEM);

    sys_clock_pll();

#ifdef BLUETOOTH_GPIO_CTRL
    BT_PWR_OFF();
#endif 

#if SDMMC_CMD_MODE
	sd_chk_ctl(SET_SD_H_CHK);
#endif

}
#endif
