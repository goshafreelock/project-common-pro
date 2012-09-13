/*--------------------------------------------------------------------------*/
/**@file    fm_receive.c
   @brief   FM接收任务模块
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "fm_rev.h"
#include "led.h"
#include "rtc_mode.h"
#include "aux_fun.h"
#include "PT2313.h"

#if defined(KPL_MSG_COMPATIBLE)
#include "kpl_msg.h"
#endif

extern u16 cfilenum;
extern xd_u8 curr_menu;
extern xd_u8  return_cnt;
#if defined(TIME_FORCE_SHOW_ON_SCREEN)
extern xd_u8 time_show_return_cnt; 
#endif
extern bit aux_online;
extern void set_play_flash(u8 led_status);
extern xd_u8 IR_Type;
extern _xdata SYS_WORK_MODE work_mode;
extern bool IR_KEY_Detect;
extern xd_u8 my_music_vol; 
extern u16 get_fm_id();

#if defined(NEW_VOLUME_KEY_FEATURE)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
extern bool new_vol_feature;
extern u8 last_disp_menu;
#endif
extern u8 play_status;
/** FM收音当前搜索到的台总数*/
xd_u8 all_channl = 0;
/** 当前频率*/
xd_u16 frequency =0;
/** FM收音当前所在的台号*/
xd_u8 fre_channl =0;
#ifdef RADIO_AM_WM_ENABLE
xd_u16 am_fre_point[MAX_AM_CHANNL] _at_ 0xd80;    //4 AM收音搜索到的台的缓存
bool radio_mode=1;
xd_u8 fre_point[MAX_CHANNL]	_at_ 0xd80;    ///< FM收音搜索到的台的缓存
#else
xd_u8 fre_point[MAX_CHANNL];    ///< FM收音搜索到的台的缓存
#endif
extern _idata u16 dac_cnt;
extern xd_u8 aux_ch_reg;

void fm_osc_output_select(bool flag)
{
   // P05 OUT CLK for FM module
   if(flag){
#if defined(SYS_CRYSTAL_USE_12M)
	   P05_source_select(1);
#else
	   P05_source_select(2);
#endif
	   P0PU |=(1<<5);
	   P0DIR &=~(1<<5);
	   _nop_();
   	   _nop_();
   }
   else{
   	P05_source_select(0);
   }

}
/*----------------------------------------------------------------------------*/
/**@brief  获取FM任务的信息
   @param  无
   @return 无
   @note   void enter_fm_rev(void)
*/
/*----------------------------------------------------------------------------*/
void enter_fm_rev(void)
{
    u8 i;
    	all_channl = read_info(MEM_ALL_CHANNL);
   	if (all_channl > MAX_CHANNL)
    	{
        	all_channl = MAX_CHANNL;
   	}

	for (i = 0;i<all_channl;i++)
       {
            fre_point[i] = read_info(MEM_CHANNL+i);
       }


    fre_channl = read_info(MEM_FRE_CHANNL);//MEM_FRE
    if (fre_channl > all_channl)
    {
        fre_channl = 1;
    }
    else if (!fre_channl)
    {
        fre_channl = 1;
    }
    frequency = read_info(MEM_FRE)+MIN_FRE;
    if ( frequency > MAX_FRE)
    {
        frequency = MIN_FRE;
    }
    else if (frequency < MIN_FRE)
    {
        frequency = MIN_FRE;
    }

#if defined(K738_LHD_LTB1_V001)||defined(K740_LHD_916_V001)
        frequency = 880;
#endif
#if defined(CUSTOM_RADIO_FREQ_875)
        frequency = 875;
#endif

}
#ifdef RADIO_AM_WM_ENABLE
extern u16 Read_AM_Freq(u8 ch);
extern u8 KT_AMFMSetMode(u8 AMFM_MODE);
void enter_am_rev(void)
{
    u8 i;
    	all_channl = read_info(MEM_AM_ALL_CHANNL);

   	if (all_channl > MAX_CHANNL)
    	{
        	all_channl = MAX_CHANNL;
   	}

	for (i = 0;i<all_channl;i++)
       {
            am_fre_point[i] = Read_AM_Freq(i*2);
       }


    fre_channl = read_info(MEM_AM_FRE_CHANNL);//MEM_FRE
    if (fre_channl > all_channl)
    {
        fre_channl = 1;
    }
    else if (!fre_channl)
    {
        fre_channl = 1;
    }
	
    frequency = Read_AM_Freq((AM_FREQ_MAGIC_NUM))+AM_MIN_FRE;
    if ( frequency > AM_MAX_FRE)
    {
        frequency = AM_MIN_FRE;
    }
    else if (frequency < AM_MIN_FRE)
    {
        frequency = AM_MIN_FRE;
    }
}
void FMAM_Mode_Switch_Profile(u8 fm_wm)
{
	if((fm_wm==SYS_FMREV)||(fm_wm==SYS_AMREV)){
	}
	else{
		work_mode = SYS_FMREV;
	}
	
    	my_main_vol(0);
	if(fm_wm==SYS_FMREV){

		//printf(" ----FM   %x \r\n",(u16)fm_wm);
		radio_mode=1;
		FM_AM_chip_mode_sel(RADIO_FM);
		enter_fm_rev();
		set_fre(frequency,1);		
	       Disp_Con(DISP_FREQ);

	}
	else if(fm_wm==SYS_AMREV){

		//printf(" -----AM   %x \r\n",(u16)fm_wm);
		radio_mode=0;
		FM_AM_chip_mode_sel(RADIO_AM);
		enter_am_rev();
		set_fre(frequency,1);
	       Disp_Con(DISP_FREQ);		
	}
	delay_10ms(20);
	set_fre(frequency,1);
    	my_main_vol(my_music_vol);
	
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief  FM任务函数
   @param  无
   @return 无
   @note   void fm_rev( void )
*/
/*----------------------------------------------------------------------------*/
void fm_rev( void )
{
    u8 key;

#if defined(SPECTRUM_FUNC_ENABLE)
    set_spectrum_lock(UNLOCK);
#endif		  

#if defined(FM_PAUSE_LED_INDICATOR)
    set_play_flash(LED_FLASH_NOR);
#endif
	
    while (1)
    {
        key = get_msg();
#if defined(KEY_PRESS_LED_INDICATOR)
	key_press_led_indicator(key);
#elif defined(CUSTOM_KEY_FEATURE_USE)
		custom_key_hdlr(key);
#endif

#if defined(KPL_MSG_COMPATIBLE)
	kpl_msg_hdlr(key);
#endif

#if 0
	if(key!=0xff)
	printf(" music_play get_msg %x \r\n",(u16)key);
#endif
	dac_sw_check();

#ifndef FM_BY_PASS
       dac_out_select(aux_ch_reg);
#endif

        switch (key)
        {

#ifdef K000_HG_898_V001	   
	case INFO_STOP |KEY_SHORT_UP :
		goto __CH_DOWN;
		break;
#endif

#ifdef IR_INFO_EQ_DOWN_SCAN
        case INFO_EQ_DOWN| KEY_SHORT_UP :
		if(IR_KEY_Detect){
			IR_KEY_Detect = 0;
			goto __SCAN_FREQ;
		}
		break;
#endif

#ifdef USE_MODE_KEY_LONG_SCAN
    	case INFO_MODE | KEY_LONG :
	goto __SCAN_FREQ;
#endif

#ifdef USE_EQ_KEY_SHORT_SCAN
    	case INFO_EQ_UP| KEY_SHORT_UP :
	goto __SCAN_FREQ;
#endif
#ifdef USE_EQ_KEY_SHORT_CH_UP
    case INFO_EQ_UP | KEY_SHORT_UP :
	goto __CH_DOWN;
		break;
#endif
#if 1//def USE_POWER_KEY
#ifdef USE_POWER_KEY_SHORT_SCAN
    	case INFO_POWER | KEY_SHORT_UP :
#ifdef USE_IR_POWER_KEY_TO_POWER_OFF
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			goto _HOT_KEY_HDLR;	
		}
#endif		
	goto __SCAN_FREQ;

#endif
#endif  

#ifdef RADIO_MODE_HOT_KEY_ENABLE	

#ifdef RADIO_AM_WM_SEL_IN_ONE_KEY
#ifdef RADIO_AM_WM_ENABLE
    case INFO_FM_MOD | KEY_SHORT_UP:
        if (work_mode == SYS_AMREV){
		Set_Curr_Func(SYS_FMREV);			
	     	FMAM_Mode_Switch_Profile(SYS_FMREV);
	}
	else if(work_mode == SYS_FMREV){
		Set_Curr_Func(SYS_AMREV);			
	     	FMAM_Mode_Switch_Profile(SYS_AMREV);
	}
		break;
#endif		
#endif
#endif		
#if defined(USE_POWER_KEY_FOR_FM_PLAY)
    	 case INFO_POWER | KEY_SHORT_UP :
#elif defined(USE_MODE_LONG_FOR_FM_PLAY)
    	 case INFO_MODE| KEY_LONG:
#endif
        case INFO_PLAY | KEY_SHORT_UP :
#if defined(FM_PLAY_KEY_PAUSE)        
#ifdef K722_YJH_722_V001
		if(IR_KEY_Detect){
			IR_KEY_Detect = 0;
			break;
		}
#endif			
            play_status = !play_status;

            if (play_status)
            {
		  my_main_vol(my_music_vol);
  		  Mute_Ext_PA(UNMUTE);
#if defined(FM_PAUSE_LED_INDICATOR)
		 set_play_flash(LED_FLASH_ON);
#endif
            }
	     else{
  		Mute_Ext_PA(MUTE);		 	
		my_main_vol(0);	

#if defined(USE_SPECTRUM_PARTTERN)		  		
		set_lcd_flash_lock(LOCK);
#endif

#if defined(FM_PAUSE_LED_INDICATOR)
    		set_play_flash(LED_FLASH_NOR);
#endif		
	     }

#if defined(PAUSE_FLASH_WHOLE_SCREEN)
            if (play_status == MUSIC_PAUSE)
			set_led_flash_tpye(2);
	     else{
			set_led_flash_tpye(0);
	     }
#endif
          Disp_Con(DISP_FREQ);		 
		
	   break;        
#endif	   
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
#if defined(IR_PLAY_KEY_SCAN_FREQ_DISABLE)
			break;
#elif defined(IR_PLAY_SHORT_CH_UP)
			goto __CH_UP;
#else
			goto __SCAN_FREQ;
#endif
		}
		else{
			
		#ifdef ADKEY_PLAY_SHORT_SCAN_FRE
			goto __SCAN_FREQ;
		#else
			#if defined( ADKEY_NEXT_ADJST_FREQ)
			goto __CH_UP;
			#endif
			#if defined(ADKEY_PLAY_SHORT_ADJ_CH)
			goto __CH_UP;
			#endif
		#endif
		}
            break;
#if defined(IR_USER_CODE_0x7F80)||defined(K120_YJH_120_V001)||defined(K000_HG_898_V001)||defined(EQ_DOWN_SCAN_ALL)
        case INFO_EQ_DOWN| KEY_SHORT_UP :
#if 1//defined(EQ_DOWN_SCAN_ALL)	
		goto __SCAN_FREQ;
#endif
#ifndef K722_YJH_722_V001		
		goto __FRE_DOWN;
#endif
#endif			
        case INFO_PLAY | KEY_LONG :

		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
#if defined(IR_PLAY_KEY_LONG_SCAN_FREQ)
		goto __SCAN_FREQ;
#else
		break;
#endif
		}
#ifdef USE_LONG_PLAY_KEY_TO_SWITCH_MODE		
		goto _HOT_KEY_HDLR;
#endif
#ifdef USE_EQ_KEY_SHORT_SCAN
		break;
#endif
#ifdef ADKEY_PLAY_SHORT_SCAN_FRE
		break;
#endif
__SCAN_FREQ:

#if defined(USE_SPECTRUM_PARTTERN)		  
	     set_lcd_flash_lock(LOCK);
#endif

#ifdef DISP_SCH_AT_FM_SCAN	
            Disp_Con(DISP_SCH);
	     delay_10ms(60);
#endif
            scan_fre();

#if defined(USE_SPECTRUM_PARTTERN)		  
	     set_lcd_flash_lock(UNLOCK);
#endif

	     if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			//break;
	     }			
            //flush_low_msg();
            fre_channl = 1;
            get_channl(fre_channl);
            //Disp_Con(DISP_FREQ);
            break;
#if RTC_ENABLE 
		case INFO_ALM_BELL :				///<闹钟响消息，进入闹钟循环
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

#if defined(TIME_FORCE_SHOW_ON_SCREEN)

            if (DISP_FREQ == curr_menu){
				
	            if (time_show_return_cnt>RETURN_TIME_SHOW_TIME){
	                    get_curr_date();
	                    Disp_Con(DISP_RTC_POINT);
				break;
		    }	
		     else{
#if defined(MANUAL_SWITCH_TIME_DISPLAY)
	                    Disp_Con(DISP_FREQ);
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
                    goto _PICK_CH;
                }
                else if (DISP_FREQ != curr_menu)
                    Disp_Con(DISP_FREQ);
#if defined(NEW_VOLUME_KEY_FEATURE)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
		if(new_vol_feature){
			new_vol_feature =0;
			if(last_disp_menu!=DISP_NULL)			
                     Disp_Con(last_disp_menu);
		}
#endif								
            }
#if defined(USE_BAT_MANAGEMENT)
		bmt_hdlr();
#endif
	     Disp_Update();			
            break;

        case INFO_PICK_FRE | KEY_LONG:
            save_fre(frequency);
            Disp_Con(DISP_FREQ);
            break;

        case INFO_PICK_FRE | KEY_SHORT_UP:
_PICK_CH:
            if (DISP_DWORD_NUMBER != curr_menu)
            {
                break;
            }

            if (( cfilenum <= MAX_FRE) && (cfilenum >= MIN_FRE))
            {

                frequency = cfilenum;
                cfilenum = 0;
                set_fre(frequency, 1);
            }
            else if ((cfilenum) && (cfilenum<=all_channl))
            {
                fre_channl = cfilenum;
                get_channl(fre_channl);
            }
            cfilenum = 0;
            Disp_Con(DISP_FREQ);
            write_info(MEM_FRE,frequency - MIN_FRE);
            break;

#if defined(VOL_TUNE_FREQ_VOL)||defined(VOL_TUNE_FREQ_ONLY)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
        case INFO_PLUS:	
      	     frequency += 2;
            goto __FRE_DOWN;			
			
        case INFO_MINUS:			 
		goto __FRE_DOWN;			
		break;
#endif
        case INFO_NEXT_FIL | KEY_SHORT_UP:

#if defined(NEW_VOLUME_KEY_FEATURE)
		break;
        case INFO_NEXT_FIL :
        case INFO_NEXT_FIL | KEY_HOLD:

		if(new_vol_feature){
			goto _HOT_KEY_HDLR;
		}
#endif				
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
#if defined(IR_NEXT_PREV_SHORT_ADJ_CH)
			     goto __CH_UP;
#elif defined( IR_NEXT_PREV_DO_NOTHING)
			break;
#elif defined( IR_NEXT_PREV_SHORT_AUTO_SCAN)
			     goto __SCAN_UP;	
#else
 	     	      		frequency += 2;
		            goto __FRE_DOWN;
#endif
		}
		else{
#if defined(K722_YJH_722_V001)
		if(fre_channl==1){
 	     	      		frequency += 2;
		            goto __FRE_DOWN;
		}
		else{
			     goto __CH_UP;
		}
#endif

#if defined( ADKEY_NEXT_ADJST_FREQ)
 	     	      		frequency += 2;
		            goto __FRE_DOWN;
#elif defined(ADKEY_NEXT_PREV_SHORT_AUTO_SCAN)
			     goto __SCAN_UP;	
#else
			     goto __CH_UP;
#endif
		}

	case INFO_PREV_FIL | KEY_SHORT_UP:
		
#if defined(NEW_VOLUME_KEY_FEATURE)
		break;
	case INFO_PREV_FIL :
	case INFO_PREV_FIL | KEY_HOLD:

		if(new_vol_feature){
			goto _HOT_KEY_HDLR;
		}
#endif				
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
#if defined(IR_NEXT_PREV_SHORT_ADJ_CH)
			     goto __CH_DOWN;
#elif defined( IR_NEXT_PREV_DO_NOTHING)
			break;
#elif defined(IR_NEXT_PREV_SHORT_AUTO_SCAN)
			     goto __SCAN_DOWN;
#else
		            goto __FRE_DOWN;
#endif
		}
		else{
#if defined(K722_YJH_722_V001)
		if(fre_channl==1){
		            goto __FRE_DOWN;
		}
		else{
			     goto __CH_DOWN;
		}
#endif
				
#if defined( ADKEY_NEXT_ADJST_FREQ)
				goto __FRE_DOWN;
#elif defined(ADKEY_NEXT_PREV_SHORT_AUTO_SCAN)
				goto __SCAN_DOWN;		
#else				
				goto __CH_DOWN;
#endif
		}
		
__FRE_DOWN:
            frequency--;

#ifdef RADIO_AM_WM_ENABLE			
	    if(work_mode==SYS_FMREV){
			
	            if ( frequency > MAX_FRE)
	            {
	                frequency = MIN_FRE;
	            }
	            else if (frequency < MIN_FRE)
	            {
	                frequency = MAX_FRE;
	            }
	            set_fre(frequency, 1);
	            write_info(MEM_FRE,frequency - MIN_FRE);
	    	}
		else	{

		     if ( frequency > AM_MAX_FRE)
	            {
	                frequency = AM_MIN_FRE;
	            }
	            else if (frequency < AM_MIN_FRE)
	            {
	                frequency = AM_MAX_FRE;
	            }
	            set_fre(frequency, 1);
	            Save_AM_Freq((frequency - AM_MIN_FRE),(AM_FREQ_MAGIC_NUM));
		}
#else
	            if ( frequency > MAX_FRE)
	            {
	                frequency = MIN_FRE;
	            }
	            else if (frequency < MIN_FRE)
	            {
	                frequency = MAX_FRE;
	            }
	            set_fre(frequency, 1);
	            write_info(MEM_FRE,frequency - MIN_FRE);
#endif
            Disp_Con(DISP_FREQ);
            //delay_ms(20);
            break;

        case INFO_CH_NEXT | KEY_SHORT_UP:
        case INFO_CH_UP| KEY_SHORT_UP:
	__CH_UP:
			fre_channl += 2;
        case INFO_CH_PREV | KEY_SHORT_UP:
        case INFO_CH_DOWN| KEY_SHORT_UP:
	__CH_DOWN:
            fre_channl--;
            if (fre_channl > all_channl)
            {
                fre_channl = 1;
            }
            else if (!fre_channl)
            {
                fre_channl = all_channl;
            }
            get_channl(fre_channl);
            Disp_Con(DISP_FREQ);
            flush_low_msg();
			
            break;

#ifdef SEMI_AUTO_SCAN_FREQ

#if defined(K722_YJH_722_V001)
        case INFO_PLAY_MODE | KEY_SHORT_UP:
		frequency += 2;
		goto __FRE_DOWN;					
#endif		
        case INFO_CH_UP| KEY_HOLD:

        case INFO_NEXT_FIL | KEY_HOLD:
	 if(IR_KEY_Detect){
		IR_KEY_Detect =0;
#if defined(IR_NEXT_PREV_HOLD_AUTO_SCAN)

#elif defined(IR_NEXT_PREV_KEY_HOLD_DO_NOTHING)
	break;
#else
	break;
#endif
		
	 }
	 else{
#if defined(ADKEY_NEXT_PREV_HOLD_AUTO_SCAN)
	//goto __SCAN_UP;
#elif defined(ADKEY_NEXT_PREV_HOLD_FREQ_ADJ)
      		frequency += 2;
		goto __FRE_DOWN;			
#elif defined(ADKEY_NEXT_PREV_HOLD_CH_SEL)
	goto __CH_UP;
#else
	goto _HOT_KEY_HDLR;
#endif
        }
        case INFO_PLUS | KEY_SHORT_UP:
#if defined(INDEPENDENT_KEY_TUNE_FREQ)
	frequency += 2;
	goto __FRE_DOWN;
#endif
        case INFO_PLUS | KEY_HOLD:
 #if defined(INDEPENDENT_KEY_FAST_TUNE_FREQ)			
 	frequency += 2;
	goto __FRE_DOWN;
#endif

__SCAN_UP:			
		auto_scan(SEARCH_UP);
            break;
#if defined(K722_YJH_722_V001)
        case INFO_EQ_UP | KEY_SHORT_UP:
		goto __FRE_DOWN;			
#endif
        case INFO_CH_DOWN| KEY_HOLD:
        case INFO_PREV_FIL | KEY_HOLD:

	 if(IR_KEY_Detect){
		IR_KEY_Detect =0;
#if defined(IR_NEXT_PREV_HOLD_AUTO_SCAN)

#elif defined(IR_NEXT_PREV_KEY_HOLD_DO_NOTHING)
	break;
#else
	break;
#endif	
	 }
	 else{
 	
#if defined(ADKEY_NEXT_PREV_HOLD_AUTO_SCAN)
	//goto __SCAN_DOWN;
#elif defined(ADKEY_NEXT_PREV_HOLD_FREQ_ADJ)
		goto __FRE_DOWN;			
#elif defined(ADKEY_NEXT_PREV_HOLD_CH_SEL)
	goto __CH_DOWN;
#else
	goto _HOT_KEY_HDLR;
#endif
        }
        case INFO_MINUS|KEY_SHORT_UP:			 

#if defined(INDEPENDENT_KEY_TUNE_FREQ)			
	goto __FRE_DOWN;
#endif

        case INFO_MINUS| KEY_HOLD:
#if defined(INDEPENDENT_KEY_FAST_TUNE_FREQ)			
	goto __FRE_DOWN;
#endif
			
__SCAN_DOWN:			
		auto_scan(SEARCH_DN);			
            break;
#endif

        default :
_HOT_KEY_HDLR:			
            if (!ap_handle_hotkey(key))
                return;
        }
    }
}

void fm_radio(void)
{
#if defined(FM_LINE_IN_SHARE_SAME_CHANNEL)||defined(FM_LINE_IN_ONLY_ONE_MODE_EXIST)
#ifdef USE_LINE_IN_DETECT_FUNC
   if(aux_online){
   	
	Set_Curr_Func(SYS_AUX);
	return;
   }
#endif
#endif

#ifdef NOT_MOUNT_FM_DEV		
       if(get_fm_id() ==0xFFFF){	//NO FM 
		Set_Curr_Func(SYS_IDLE);
		return;
	}
#endif

//     xd_u8 vol_tmp=0;
    PT1 = 1;										//timer1 interrupt 低优先级
    IR_KEY_Detect =0;
#if 1//defined(FM_PLAY_KEY_PAUSE)    
            play_status = MUSIC_PLAY;
#endif

#ifndef DISABLE_P05_OSC_OUTPUT
    fm_osc_output_select(TRUE);
#endif

#if defined(K202_WEISI_KL202_V001000000000)
    set_led_enable_bit(1);
#endif	
    set_play_flash(LED_FLASH_ON);
#ifdef USE_AMP_MODE_SELECT
	D_CLASS_AMP_GPIO_INIT(); 
	D_CLASS_AMP_LOW();
#endif
    Mute_Ext_PA(MUTE);
    my_main_vol(0);
#if SDMMC_CMD_MODE
	sd_chk_ctl(SET_SD_L_CHK);
#endif
    flush_low_msg();
    sysclock_div2(1);

#ifdef RADIO_AM_WM_ENABLE
	FMAM_Mode_Switch_Profile(work_mode);
#endif

#ifdef DISP_CH_NUM_IN_RADIO_AT_FISRT
    Disp_Con(DISP_CH_NO);
#else
    Disp_Con(DISP_FREQ);
#endif

#ifndef RADIO_AM_WM_ENABLE
    init_fm_rev();
    set_fre(frequency,1);
#endif

//    delay_10ms(1);
	
//vol_tmp = my_music_vol;
//    if(vol_tmp>12)my_music_vol = 12;//dac_channel_sel()会用music_vol 打开声音通道

#ifdef SUPPORT_PT2313

    my_main_vol(0);	
    delay_10ms(10);
	
#ifdef FM_PATH_SHARE_SAME_MP3_PT_CHAN

#ifdef EXCHANGE_LINE_IN_CHANNEL
    aux_channel_crosstalk_improve(DAC_AMUX1);//4  P26,P27 FM_IN
#else
    aux_channel_crosstalk_improve(DAC_AMUX0);//4P24,P25 FM_IN	
#endif

    PT2313_Config(MP3_CHAN,CHAN_ADJ);
#else
    PT2313_Config(FM_CHAN,CHAN_ADJ);
#endif	

#else//  SUPPORT_PT2313

#ifdef FM_BY_PASS
 //   Mute_Ext_PA(UNMUTE); 
    //my_main_vol(my_music_vol);	
    	dac_out_select(DAC_DECODE);	//4  
    	main_vol(0);  
//    dac_highz_output_enable();
#else

#ifdef FM_LINE_IN_SHARE_SAME_CHANNEL

#ifdef EXCHANGE_LINE_IN_CHANNEL
    aux_channel_crosstalk_improve(DAC_AMUX0);//4P24,P25 FM_IN	  
#else
    aux_channel_crosstalk_improve(DAC_AMUX1);//4P26,P27 FM_IN
#endif

#else

#ifdef EXCHANGE_LINE_IN_CHANNEL
    aux_channel_crosstalk_improve(DAC_AMUX1);//4P26,P27 FM_IN
#else
    aux_channel_crosstalk_improve(DAC_AMUX0);//4P24,P25 FM_IN	  
#endif

#endif

#endif	// END OF FM_BY_PASS

#endif	// END OF SUPPORT_PT2313

//    my_music_vol =vol_tmp;
	
    my_main_vol(my_music_vol);	
    set_fre(frequency,1);
#ifdef FM_BY_PASS
    my_main_vol(my_music_vol);	// add here for FM volume setting confirm, after setting the freq ,vol may turn on ....
#endif

    set_max_vol(MAX_ANALOG_VOL, MAX_DIGITAL_VOL);			//设置FM模式的音量上限

    delay_10ms(2);	
    Mute_Ext_PA(UNMUTE);
    fm_rev();
    Mute_Ext_PA(MUTE);
    sys_clock_pll();

    main_vol_set(0, CHANGE_VOL_NO_MEM);
	
    fm_rev_powerdown();
#if SDMMC_CMD_MODE
	sd_chk_ctl(SET_SD_H_CHK);
#endif

#ifndef DISABLE_P05_OSC_OUTPUT
    fm_osc_output_select(FALSE);
#endif

#if defined(USE_SPECTRUM_PARTTERN)		  
    set_lcd_flash_lock(UNLOCK);	
#endif

#ifdef USE_AMP_MODE_SELECT
	D_CLASS_AMP_HIGH();
#endif
	
}


