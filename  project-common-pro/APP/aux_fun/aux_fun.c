/*--------------------------------------------------------------------------*/
/**@file     aux_fun.c
   @brief    AUX任务模块
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "aux_fun.h"
#include "led.h"
#include "rtc_mode.h"
#include "PT2313.h"

#if defined(KPL_MSG_COMPATIBLE)
#include "kpl_msg.h"
#endif

#ifndef NOT_USE_LINE_IN_FUNC	
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
#if defined(TWO_PLAY_LED_IN_USE)
extern bool led_open_enable;
#endif
#ifdef SUPPORT_PT2313
extern xd_u8 audio_effect_state;
#endif
#ifdef USE_AUX_2
static bool aux_2_sel=0;
#endif
extern xd_u8 aux_ch_reg;

#if defined(ADC_DETECT_LINE_IN)
extern bool Line_In_Detect;
extern volatile u8 line_in_level;
#endif
#ifdef LINE_IN_FLASH_WHOLE_SCREEN
bool aux_screen_flash_bit=0;
#endif
#ifdef SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION
extern bool sys_pwr_on_led_protect_bit;
#endif

#if defined(K000_XingChuang_x821_V001)
extern void wkup_pin_ctrl(bool dir);
#endif
/*----------------------------------------------------------------------------*/
/**@brief  AUX消息处理
   @param  无
   @return 无
   @note   void deal_aux( void )
*/
/*----------------------------------------------------------------------------*/
#if defined(IPONE_DOCK_FUNC_ENABLE)
#include "ipone_ctrl.h"
void ipone_hdlr()
{
    u8 key;
#if defined(IPHONE_PP_FLASH)
	bool PP_FLASH_LED = 0;
#endif

    Disp_Con(DISP_IPOD);
#if defined(TURN_ON_MUSIC_WHEN_IPHONE_DOCK)
	delay_10ms(120);

	IPOD_STOP;
	delay_10ms(1);
     	IPOD_RELEASE;	
	delay_10ms(2);
	IPOD_PLAY;
	delay_10ms(1);
     	IPOD_RELEASE;
	delay_10ms(10);
#endif

#if defined(IPONE_LINE_IN_CHANNEL_USE_AUX0)
    aux_channel_crosstalk_improve(DAC_AMUX0);
#else	
    aux_channel_crosstalk_improve(DAC_AMUX1);
#endif
    Mute_Ext_PA(UNMUTE);
    my_main_vol(my_music_vol);
	
    while (1)
    {
        key = get_msg();
#if 0
	if(key!=0xff)
	printf(" ipone_hdlr  %x \r\n",(u16)key);
#endif

       dac_out_select(aux_ch_reg);

	 dac_sw_check();
	 
	switch (key)
        {
        case INFO_PLAY | KEY_SHORT_UP :
	  	play_status = !play_status;

#if defined(IPHONE_CTRL_FAKE)		
            if (play_status)
            {
		  my_main_vol(my_music_vol);
  		  Mute_Ext_PA(UNMUTE);
            }
	     else{
  		Mute_Ext_PA(MUTE);		 	
		my_main_vol(0);	
	     }
#endif		 
		IPOD_PLAY;
		delay_10ms(1);
	     	IPOD_RELEASE;		
            	Disp_Con(DISP_IPOD);
	   break;
	   
        case INFO_NEXT_FIL | KEY_SHORT_UP:
		IPOD_NEXT_TRACK;
		delay_10ms(1);	
	     	IPOD_RELEASE;		
            break;
			
        case INFO_PREV_FIL | KEY_SHORT_UP:
		IPOD_PREVIOUS_TRACK;
		delay_10ms(1);	
	     	IPOD_RELEASE;				
            break;
			       
        case INFO_HALF_SECOND :

#ifdef USE_USB_HOTPLUG_FUNC
		usb_hotplug_hdlr();
#endif

            if (return_cnt < RETURN_TIME)
            {
                return_cnt++;
            }

#if defined(TIME_FORCE_SHOW_ON_SCREEN)
            if (time_show_return_cnt>RETURN_TIME_SHOW_TIME){
                    get_curr_date();
                    Disp_Con(DISP_RTC_POINT);
			break;
	    }	
	     else{
#if defined(MANUAL_SWITCH_TIME_DISPLAY)
                    Disp_Con(DISP_IPOD);
#else			 	
                if(DISP_RTC != curr_menu){
			time_show_return_cnt++;
                }
#endif				
	     }
#endif
			
            if (RETURN_TIME == return_cnt)
            {

#ifdef SUPPORT_PT2313
		  clr_aud_effect_state();
#endif            
                if (DISP_DWORD_NUMBER == curr_menu)
                {
                    cfilenum = 0;
                }

                if (DISP_IPOD != curr_menu)
    			Disp_Con(DISP_IPOD);
            }
#if defined(IPHONE_PP_FLASH)
            if(!play_status){

			PP_FLASH_LED=~PP_FLASH_LED;
			if(PP_FLASH_LED){
    				Disp_Con(DISP_CLR);
			}
			else{

    				Disp_Con(DISP_IPOD);
			}		
	    }				
#endif

#if defined(USE_BAT_MANAGEMENT)
		bmt_hdlr();
#endif
	     Disp_Update();			
            break;

    case INFO_VOL_PLUS:
    case INFO_VOL_PLUS | KEY_HOLD :
#if 1//!defined(INDEPENDENT_VOLUME_KEY)		
    //case INFO_NEXT_FIL:
    //case INFO_NEXT_FIL| KEY_HOLD :
	//	if(IR_KEY_Detect){
	//		IR_KEY_Detect =0;
	//		break;
	//	}
#endif		

	 IPOD_VOLUME_UP;
	 delay_10ms(1);
	 IPOD_RELEASE;
	 delay_10ms(1);	 
	 goto __HOTKEY_HDLR;
	 break;
	 
    case INFO_VOL_MINUS:
    case INFO_VOL_MINUS | KEY_HOLD :
#if 1//!defined(INDEPENDENT_VOLUME_KEY)				
    //case INFO_PREV_FIL:
    //case INFO_PREV_FIL| KEY_HOLD :
	//	if(IR_KEY_Detect){
	//		IR_KEY_Detect =0;
	//		break;
	//	}
#endif
	 IPOD_VOLUME_DOWN;
	 delay_10ms(1);
	 IPOD_RELEASE;
	 delay_10ms(1); 
 	 goto __HOTKEY_HDLR;
	 break;
	 
        default :
__HOTKEY_HDLR:			
            if (!ap_handle_hotkey(key))
                return;
        }
    }
}
#if defined(IPONE_INDEPENDENT_MODE)
void iphone_func(void)
{
#if defined(K000_XingChuang_x821_V001)
	charger_iphone_ctrl();
#endif
    Mute_Ext_PA(MUTE);	

    set_play_flash(LED_FLASH_ON);
    Disp_Con(DISP_IPOD);
    PT1 = 1;										//timer1 interrupt 低优先级
    flush_low_msg();
    play_status = 0;

    set_max_vol(MAX_ANALOG_VOL, MAX_DIGITAL_VOL);			//设置AUX模式的音量上限

    sysclock_div2(1);
	
#ifdef BLUETOOTH_GPIO_CTRL
    BT_PWR_OFF();
#endif 

    open_uart_ctrl();
    ipone_hdlr();
#if defined(TURN_OFF_IPOD_WHEN_LEAVE_IPHONE_DOCK)
	delay_10ms(10);
	IPOD_STOP;
	delay_10ms(1);
     	IPOD_RELEASE;	
	delay_10ms(1);	
#endif	
    close_uart_ctrl();

    main_vol_set(0, CHANGE_VOL_NO_MEM);

    sys_clock_pll();

#if defined(USE_SPECTRUM_PARTTERN)	
    set_lcd_flash_lock(UNLOCK);
#endif

#if defined(K000_XingChuang_x821_V001)
    wkup_pin_ctrl(0);
#endif
	
}
#endif
#endif
void deal_aux( void )
{
    u8 key;
#if defined(K755_JinYeHeLi_755_V001)||defined(K755_AnJieEr_755_V001)
    set_play_flash(LED_FLASH_SLOW);
#endif

#if defined(AUX_PAUSE_LED_INDICATOR_FLASH_WHEN_PLAY)
    set_play_flash(LED_FLASH_NOR);
#endif
#if defined(SPECTRUM_FUNC_ENABLE)
    set_spectrum_lock(UNLOCK);
#endif		  

    while (1)
    {
        key = get_msg();
#if 0
	if(key!=0xFF)
	printf( "---->---deal_aux %x \r\n",(u16)key);
#endif

       dac_out_select(aux_ch_reg);
		
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
#if defined(LINE_IN_PLAY_KEY_PAUSE)
#if 1//defined(USE_ONLY_POWER_HOLD_CTRL)
#if defined(USE_POWER_KEY_FOR_AUX_PLAY)
        case INFO_POWER | KEY_SHORT_UP :	
#ifdef USE_IR_POWER_KEY_TO_POWER_OFF
		if(IR_KEY_Detect){
			goto _HOT_KEY_HDLR;	
		}
        case INFO_PLAY | KEY_SHORT_UP :		
#endif		
			
#else
        case INFO_PLAY | KEY_SHORT_UP :
#endif
#else
        case INFO_PLAY | KEY_SHORT_UP :
#endif			
#ifdef K722_YJH_722_V001
		if(IR_KEY_Detect){
			IR_KEY_Detect = 0;
			break;
		}
#endif			

            if (play_status == MUSIC_PAUSE)
            {
	         play_status =MUSIC_PLAY;
		  my_main_vol(my_music_vol);
#ifndef NO_AUX_MUTE_WHEN_PAUSE		  
  		  Mute_Ext_PA(UNMUTE);
#endif

#if defined(USE_SPECTRUM_PARTTERN)		  
		  set_lcd_flash_lock(UNLOCK);
#endif

#if defined(AUX_PAUSE_LED_INDICATOR)
		 set_play_flash(LED_FLASH_ON);
#elif defined(AUX_PAUSE_LED_INDICATOR_FLASH_WHEN_PLAY)
		 set_play_flash(LED_FLASH_NOR);
#endif
#if defined(SPECTRUM_FUNC_ENABLE)
    set_spectrum_lock(UNLOCK);
#endif		  
            }
	     else if (play_status == MUSIC_PLAY){

	        play_status =MUSIC_PAUSE;

#ifndef NO_AUX_MUTE_WHEN_PAUSE		  		 	
  		Mute_Ext_PA(MUTE);		 
#endif
		my_main_vol(0);	
		
#if defined(USE_SPECTRUM_PARTTERN)		  		
		set_lcd_flash_lock(LOCK);
#endif

#if defined(AUX_PAUSE_LED_INDICATOR)
    		set_play_flash(LED_FLASH_FAST);
#elif defined(AUX_PAUSE_LED_INDICATOR_FLASH_WHEN_PLAY)
		 set_play_flash(LED_FLASH_ON);
#endif	
#if defined(SPECTRUM_FUNC_ENABLE)
    set_spectrum_lock(LOCK);
#endif		  
	     }
#if defined(PAUSE_FLASH_WHOLE_SCREEN)
            if (play_status == MUSIC_PAUSE)
			set_led_flash_tpye(2);
	     else{
			set_led_flash_tpye(0);
	     }
#endif		 
            Disp_Con(DISP_AUX);		 
	   break;        
#endif	   
#ifdef ADC_DETECT_LINE_IN
    case MSG_AUX_IN :
		sys_printf("  MSG_AUX_IN");
	 my_main_vol(my_music_vol);	
	 Mute_Ext_PA(UNMUTE);
        break;

    case MSG_AUX_OUT :
		sys_printf("  MSG_AUX_OUT");
	 Mute_Ext_PA(MUTE);		
	 main_vol(0);			
        break;
#endif

#ifdef USE_AUX_2
     case INFO_MODE | KEY_SHORT_UP:
	 	
		if(aux_2_sel==0){
			aux_2_sel =1;
		       Set_Curr_Func(AUX_2_DEV);
			set_play_flash(LED_FLASH_ON);			   
	   		PT2313_Config(AUX_CHAN,CHAN_ADJ);			
		}
		else{
			aux_2_sel =0;
			goto _HOT_KEY_HDLR;
		}
		break;

     case INFO_AUX_MOD | KEY_SHORT_UP:
	aux_2_sel=~aux_2_sel;
	if(aux_2_sel){

	       Set_Curr_Func(AUX_2_DEV);
   		PT2313_Config(AUX_CHAN,CHAN_ADJ);
	}	
	else{

	       Set_Curr_Func(AUX_DEV);
		PT2313_Config(MP3_CHAN,CHAN_ADJ);
	}

	set_play_flash(LED_FLASH_ON);

	break;
#endif
        case INFO_HALF_SECOND :
			
#if defined(AD_MEASURE_TEMP_FUNC)
		adc_diode_temp_measure_hdlr();
#endif

#ifdef USE_USB_HOTPLUG_FUNC
		usb_hotplug_hdlr();
#endif

            if (return_cnt < RETURN_TIME)
            {
                return_cnt++;
            }

#if defined(LINE_IN_PLAY_KEY_PAUSE)
		if(play_status==MUSIC_PAUSE){

#ifdef LINE_IN_FLASH_WHOLE_SCREEN	
			aux_screen_flash_bit=~aux_screen_flash_bit;
			if(aux_screen_flash_bit){
		                  Disp_Con(DISP_AUX);
			}
			else{
		                   Disp_Con(DISP_PWR_OFF);
					break;
			}
#endif
		}
#endif

			
#if defined(TIME_FORCE_SHOW_ON_SCREEN)

	if(DISP_AUX == curr_menu){
		
	            if (time_show_return_cnt>RETURN_TIME_SHOW_TIME){
	                    get_curr_date();
	                    Disp_Con(DISP_RTC_POINT);
				break;
		    }	
		     else{
#if defined(MANUAL_SWITCH_TIME_DISPLAY)
	                    Disp_Con(DISP_AUX);
#else			 	
	                if(DISP_RTC != curr_menu){
				time_show_return_cnt++;
	                }
#endif				
		     }
	     }
#endif

            if (RETURN_TIME == return_cnt)
            {
            
#ifdef SUPPORT_PT2313
		  clr_aud_effect_state();
#endif

                if (DISP_DWORD_NUMBER == curr_menu)
                {
                    cfilenum = 0;
                }
                if (DISP_AUX != curr_menu)
                    Disp_Con(DISP_AUX);
				
#if defined(CUSTOM_MAIN_DISP_VOL)
	         if (DISP_AUX== curr_menu){
                    Disp_Con(DISP_VOL);
	         }
#endif
				
            }
#if defined(USE_BAT_MANAGEMENT)
		bmt_hdlr();
#endif
	     Disp_Update();			
            break;
#if defined(NEW_VOLUME_KEY_FEATURE)
        case INFO_NEXT_FIL :
        case INFO_NEXT_FIL | KEY_SHORT_UP:
        case INFO_NEXT_FIL | KEY_HOLD:

		if(!new_vol_feature){
			break;
		}
#else			

    case INFO_VOL_PLUS:
    case INFO_VOL_PLUS | KEY_HOLD :
#ifdef KEY_NEXT_PREV_HOLD_ADJ_VOL_IN_AUX
    case INFO_NEXT_FIL| KEY_HOLD :
#endif
#if !defined(INDEPENDENT_VOLUME_KEY)		
    case INFO_NEXT_FIL:
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

        my_music_vol += 2;

#if defined(NEW_VOLUME_KEY_FEATURE)
        case INFO_PREV_FIL :
        case INFO_PREV_FIL | KEY_SHORT_UP:
        case INFO_PREV_FIL | KEY_HOLD:

		if(!new_vol_feature){
			break;
		}
#else				

    case INFO_VOL_MINUS:
    case INFO_VOL_MINUS | KEY_HOLD :
#ifdef KEY_NEXT_PREV_HOLD_ADJ_VOL_IN_AUX
    case INFO_PREV_FIL| KEY_HOLD :
#endif		
#if !defined(INDEPENDENT_VOLUME_KEY)				
    case INFO_PREV_FIL:
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
#ifndef NO_AUX_MUTE_WHEN_PAUSE		  
  		  Mute_Ext_PA(UNMUTE);
#endif		   
	 }
#endif		
	 clear_super_mute_lock();

        write_info(MEM_VOL,my_music_vol);
	 my_main_vol(my_music_vol);	
	 Disp_Con(DISP_VOL);
        break;			
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
_HOT_KEY_HDLR:			        
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
void aux_function(void)
{
#ifdef USE_LINE_IN_DETECT_FUNC
#ifndef AUX_DETECT_FUNC_WITH_MANUAL_SEL
   if(!aux_online){
   	
	Set_Curr_Func(SYS_MP3DECODE_USB);
	return;
   }
#endif   
#endif
#ifdef SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION_UNTIL_AUX
	 sys_pwr_on_led_protect_bit=0;
#endif
#if 1//defined(LINE_IN_PLAY_KEY_PAUSE)
         play_status =MUSIC_PLAY;
#endif
#if defined(TWO_PLAY_LED_IN_USE)
	 led_open_enable = 0;
#endif	
    set_play_flash(LED_FLASH_ON);

#if defined(IPONE_DOCK_FUNC_ENABLE)&&!defined(IPONE_INDEPENDENT_MODE)
    Disp_Con(DISP_IPOD);
#else
    Disp_Con(DISP_AUX);
#endif
    PT1 = 1;										//timer1 interrupt 低优先级
    flush_low_msg();
#if SDMMC_CMD_MODE
	sd_chk_ctl(SET_SD_L_CHK);
#endif

    set_max_vol(MAX_ANALOG_VOL, MAX_DIGITAL_VOL);			//设置AUX模式的音量上限

#ifdef SUPPORT_PT2313

#ifdef AUX_PATH_SHARE_SAME_MP3_PT_CHAN

#ifdef EXCHANGE_LINE_IN_CHANNEL
    aux_channel_crosstalk_improve(DAC_AMUX0);//4P24,P25 FM_IN	  
#else
    aux_channel_crosstalk_improve(DAC_AMUX1);//4P26,P27 FM_IN
#endif

    PT2313_Config(MP3_CHAN,CHAN_ADJ);

#else

    PT2313_Config(AUX_CHAN,CHAN_ADJ);

#endif

#else	//SUPPORT_PT2313

#ifdef FM_BY_PASS

#ifdef ADC_DETECT_LINE_IN
    aux_online =1;
    Line_In_Detect =0;
#endif
    main_vol(0);

#ifdef EXCHANGE_LINE_IN_CHANNEL
    aux_channel_crosstalk_improve(DAC_AMUX0);	//4P24,P25 AUX_IN	 
#else	
    aux_channel_crosstalk_improve(DAC_AMUX1);;//4P26,P27 AUX_IN
#endif

    Mute_Ext_PA(UNMUTE);
    my_main_vol(my_music_vol);
    
#else	//FM_BY_PASS
	
#ifdef EXCHANGE_LINE_IN_CHANNEL
    aux_channel_crosstalk_improve(DAC_AMUX0);	//4P24,P25 AUX_IN	 
#else	
    aux_channel_crosstalk_improve(DAC_AMUX1);//4	P26,P27 AUX_IN
#endif
    //Mute_Ext_PA(UNMUTE);
    //my_main_vol(my_music_vol);
#endif	//FM_BY_PASS
#endif	//SUPPORT_PT2313

#ifdef ADC_DETECT_LINE_IN
    my_main_vol(0);		
#else
    Mute_Ext_PA(UNMUTE);	
    my_main_vol(my_music_vol);	
#endif
	
    sysclock_div2(1);
#if defined(IPONE_DOCK_FUNC_ENABLE)&&!defined(IPONE_INDEPENDENT_MODE)
    //open_uart_ctrl();
    ipone_hdlr();
    //close_uart_ctrl();
#else
    deal_aux();
#endif

   Mute_Ext_PA(MUTE);		

#ifdef SUPPORT_PT2313
    my_main_vol(0);		
#else
   main_vol_set(0, CHANGE_VOL_NO_MEM);
#endif

    sys_clock_pll();

#if defined(USE_SPECTRUM_PARTTERN)		  
    set_lcd_flash_lock(UNLOCK);
#endif

#if SDMMC_CMD_MODE
	sd_chk_ctl(SET_SD_H_CHK);
#endif

}
#endif
