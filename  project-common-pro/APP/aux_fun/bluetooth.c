/*--------------------------------------------------------------------------*/
/**@file     bluetooth.c
   @brief     bluetooth任务模块
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

#ifdef BLUE_TOOTH_GPIO_STATUS

#define BLUE_TOOTH_PWR_ON			10
#define BLUE_TOOTH_CONFIG			2000
#define BLUE_TOOTH_CONFIG_OK		15
#define BLUE_TOOTH_DIS_CON		15000
#define BLUE_TOOTH_PP				20
#define BLUE_TOOTH_CONNECTED		25

bool blue_tooth_detect=0,blue_tooth_status=0;
xd_u8 gpio_H_timer=0,gpio_L_timer=0,gpio_debounc_timer=0;
xd_u16 gpio_reset_timer=0;
void bt_disp_status_hdlr()
{
	BT_STATUS_DETECT_INIT();
	if(!BT_STATUS_DETECT_PORT){

		gpio_L_timer++;
		if(gpio_L_timer>3){
			gpio_H_timer=0;
		}
	}
	else{
		gpio_H_timer++;
		
		if(gpio_H_timer>2){

			if(gpio_L_timer>6){
				blue_tooth_status=1;
			}
			else{
				gpio_L_timer =0;
				
			}
		}

		gpio_reset_timer++;
		if(gpio_reset_timer>2000){

			gpio_reset_timer=0;
			gpio_H_timer=0;
			gpio_L_timer=0;
			blue_tooth_status=0;
		}
	}

	if(blue_tooth_status){
		
		blue_tooth_status=0;
		gpio_reset_timer=0;

		if(gpio_L_timer<BLUE_TOOTH_PWR_ON){
			gpio_debounc_timer++;
			if(gpio_debounc_timer>2){
				gpio_debounc_timer=0;
			    set_play_flash(LED_FLASH_ON);
			}

		}
		else if(gpio_L_timer<BLUE_TOOTH_CONFIG_OK){
			gpio_debounc_timer++;		
			if(gpio_debounc_timer>2){
				gpio_debounc_timer=0;
			    set_play_flash(LED_FLASH_ON);
			}
		}
		else if(gpio_L_timer<BLUE_TOOTH_CONFIG){
			gpio_debounc_timer++;		
			if(gpio_debounc_timer>2){
				gpio_debounc_timer=0;
			    set_play_flash(LED_FLASH_VERY_FAST);
			}
		}
		else if(gpio_L_timer<BLUE_TOOTH_CONNECTED){
			gpio_debounc_timer++;		
			if(gpio_debounc_timer>2){
				gpio_debounc_timer=0;
			    set_play_flash(LED_FLASH_ON);
			}
		}
		else{
			gpio_debounc_timer=0;		

		}		
		
		gpio_H_timer=0;
		gpio_L_timer=0;
	}
}
#endif
void blue_tooth_init(void)
{
#ifdef BLUETOOTH_GPIO_CTRL
	BT_PWR_PORT_INIT();
	BT_RST_PORT_INIT();
	BT_PWR_ON();
	delay_10ms(10);

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

xd_u8 bt_key_release_cnt=0,key_release_hdlr=0;
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
	        case BT_PP_HOLD :
			key_release_hdlr=BT_PP_HOLD;
			bt_key_release_cnt=1;
#ifdef BLUETOOTH_GPIO_CTRL		
			BT_PP_PORT_INIT();
			BT_PP_ON();
#endif
			break;
	        case BT_PP_HOLD_RELEASE :
#ifdef BLUETOOTH_GPIO_CTRL		
			BT_PP_OFF();
#endif
			break;
		 case BT_CONFIG_HOLD:
			key_release_hdlr=BT_CONFIG_HOLD;
			bt_key_release_cnt=1;
#ifdef BLUETOOTH_GPIO_CTRL		
			BT_CONFIG_PORT_INIT();
			BT_CONFIG_ON();
#endif		 	
		 	break;
	        case BT_CONFIG_HOLD_RELEASE :
#ifdef BLUETOOTH_GPIO_CTRL		
			BT_CONFIG_OFF();
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

#ifndef BLUE_TOOTH_DISABLE_GPIO_VOL_ADJ
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
			key_release_hdlr=BT_VOL_UP_HOLD;
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
			key_release_hdlr=BT_VOL_DOWN_HOLD;
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
			key_release_hdlr=0;
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
#endif
	}
}

/*----------------------------------------------------------------------------*/
/**@brief  AUX消息处理
   @param  无
   @return 无
   @note   void deal_aux( void )
*/
/*----------------------------------------------------------------------------*/
void blue_tooth_main(void)
{
    u8 key;
#ifdef TURN_OFF_PLAY_STATUS_LED_IN_BLUETOOTH_MODE
    set_play_flash(LED_FLASH_STOP);
#endif

#ifdef K000_XC_BC_BT_V001
        play_status =MUSIC_PAUSE;
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
#ifdef BLUE_TOOTH_GPIO_STATUS
	if(blue_tooth_detect){
		blue_tooth_detect=0;
		bt_disp_status_hdlr();		
	}
#endif
#if defined(KPL_MSG_COMPATIBLE)
	kpl_msg_hdlr(key);
#endif

	 dac_sw_check();

 	switch (key)
        {

#ifdef BLUE_TOOTH_DETECTION_FOR_POWER_OFF
        case INFO_POWER|KEY_SHORT_UP:
	    sys_power_down();
	    break;
#endif 

#ifdef PP_KEY_LONG_CONFIG_BT
        case INFO_PLAY | KEY_LONG:
	     blue_tooth_key_hdlr(BT_CONFIG_HOLD);
		 break;
#endif
        case INFO_PLAY | KEY_HOLD:
#ifdef PP_KEY_LONG_CONFIG_BT
		 break;
	     //blue_tooth_key_hdlr(BT_CONFIG_HOLD);			
#else
	     blue_tooth_key_hdlr(BT_PP_HOLD);			
#endif
	     break;
        case INFO_PLAY | KEY_SHORT_UP :

	     blue_tooth_key_hdlr(BT_PP);
#ifndef BLUE_TOOTH_NO_SYS_MUTE_CTRL
#if !defined(BLUE_TOOTH_BYPASS)	 
            if (play_status == MUSIC_PAUSE)
            {
	         play_status =MUSIC_PLAY;
		  my_main_vol(my_music_vol);
#ifndef BLUE_TOOTH_PP_NOT_EXT_MUTE
  		  Mute_Ext_PA(UNMUTE);
#endif
            }
	     else if (play_status == MUSIC_PLAY){

	        play_status =MUSIC_PAUSE;
#ifndef BLUE_TOOTH_PP_NOT_EXT_MUTE	 	
  		Mute_Ext_PA(MUTE);		 	
#endif
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
#ifdef PP_KEY_HOLD_CONFIG_BT
		if(key_release_hdlr==BT_CONFIG_HOLD){

	     	 	blue_tooth_key_hdlr(BT_CONFIG_HOLD_RELEASE);
#else				
		if(key_release_hdlr==BT_PP_HOLD){
		
	     	 	blue_tooth_key_hdlr(BT_PP_HOLD_RELEASE);
#endif
		}
		else if((key_release_hdlr==BT_VOL_UP_HOLD)||(key_release_hdlr==BT_VOL_DOWN_HOLD)){
	     	 	blue_tooth_key_hdlr(BT_VOL_HOLD_RELEASE);

		}
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
	break;
    case INFO_VOL_PLUS| KEY_SHORT_UP:
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
		break;
    case INFO_VOL_MINUS| KEY_SHORT_UP:
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
	case INFO_ALM_BELL :					   ///<闹钟响消息，进入闹钟循环
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
/**@brief  AUX功能入口
   @param  无
   @return 无
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

    PT1 = 1;										//timer1 interrupt 低优先级
    flush_low_msg();
#if SDMMC_CMD_MODE
   sd_chk_ctl(SET_SD_L_CHK);
#endif
    main_vol(0);

    blue_tooth_init();
	
    set_max_vol(MAX_ANALOG_VOL, MAX_DIGITAL_VOL);			//设置AUX模式的音量上限

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
    my_main_vol(0);	

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

